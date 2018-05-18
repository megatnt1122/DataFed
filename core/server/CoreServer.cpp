#include <fstream>
#include <time.h>
#include "MsgBuf.hpp"
#include "DynaLog.hpp"
#include "CoreServer.hpp"
#include "Util.hpp"


#define timerDef() struct timespec _T0 = {0,0}, _T1 = {0,0}
#define timerStart() clock_gettime(CLOCK_REALTIME,&_T0)
#define timerStop() clock_gettime(CLOCK_REALTIME,&_T1)
#define timerElapsed() ((_T1.tv_sec - _T0.tv_sec) + ((_T1.tv_nsec - _T0.tv_nsec)/1.0e9))

#define MAINT_POLL_INTERVAL 5
#define CLIENT_IDLE_TIMEOUT 3600

using namespace std;

namespace SDMS {

//using namespace SDMS::Anon;
//using namespace SDMS::Auth;

namespace Core {


Server::Server( uint32_t a_port, const string & a_cert_dir, uint32_t a_timeout, uint32_t a_num_threads, const string & a_db_url, const std::string & a_db_user, const std::string & a_db_pass, const std::string & a_repo_address ) :
    m_port( a_port ),
    m_timeout(a_timeout),
    m_io_secure_thread(0),
    m_io_insecure_thread(0),
    m_maint_thread(0),
    m_num_threads(a_num_threads),
    m_io_running(false),
    //m_endpoint( asio::ip::tcp::v4(), m_port ),
    //m_acceptor( m_io_service, m_endpoint ),
    //m_context( asio::ssl::context::tlsv12 ),
    m_db_url(a_db_url),
    m_db_user(a_db_user),
    m_db_pass(a_db_pass),
    m_repo_address( a_repo_address ),
    m_zap_thread(0),
    m_xfr_mgr( *this ),
    m_msg_router_thread(0),
    m_num_workers(8)
{
    /*
    m_context.set_options(
        asio::ssl::context::default_workarounds |
        asio::ssl::context::no_sslv2 |
        asio::ssl::context::no_sslv3 |
        asio::ssl::context::no_tlsv1 |
        asio::ssl::context::no_tlsv1_1 |
        asio::ssl::context::single_dh_use );

    m_cert_file = a_cert_dir + "sdms-core-cert.pem";
    m_key_file = a_cert_dir + "sdms-core-key.pem";
    m_key_path = a_cert_dir + "ssh/";

    cout << "cert file: " << m_cert_file << "\n";
    cout << "key file: " << m_key_file << "\n";

    m_context.use_certificate_chain_file( m_cert_file.c_str() );
    m_context.use_private_key_file( m_key_file.c_str(), asio::ssl::context::pem );
    m_context.load_verify_file( m_cert_file.c_str() );

    //m_context.load_verify_file("/home/d3s/olcf/SDMS/client_cert.pem");
    //m_context.add_verify_path( m_verify_path.c_str() );
    //m_context.use_tmp_dh_file( "dh512.pem" );
    */

    m_sec_ctx.is_server = true;
    m_sec_ctx.public_key = "B8Bf9bleT89>9oR/EO#&j^6<F6g)JcXj0.<tMc9[";
    m_sec_ctx.private_key = "k*m3JEK{Ga@+8yDZcJavA*=[<rEa7>x2I>3HD84U";

    m_auth_clients["B8Bf9bleT89>9oR/EO#&j^6<F6g)JcXj0.<tMc9["] = "repo1";

    m_zap_thread = new thread( &Server::zapHandler, this );
}


Server::~Server()
{
    stop( true );

    m_zap_thread->join();
    delete m_zap_thread;
}


void
Server::run( bool a_async )
{
    unique_lock<mutex> lock(m_api_mutex);

    if ( m_io_running )
        throw runtime_error( "Only one worker router instance allowed" );

    m_io_running = true;

    if ( a_async )
    {
        //m_io_thread = new thread( &Server::ioRun, this );
        m_xfr_mgr.start();
        m_maint_thread = new thread( &Server::backgroundMaintenance, this );
        m_msg_router_thread = new thread( &Server::msgRouter, this );
        m_io_secure_thread = new thread( &Server::ioSecure, this );
        m_io_insecure_thread = new thread( &Server::ioInsecure, this );
    }
    else
    {
        lock.unlock();
        m_xfr_mgr.start();
        m_maint_thread = new thread( &Server::backgroundMaintenance, this );
        m_msg_router_thread = new thread( &Server::msgRouter, this );
        m_io_secure_thread = new thread( &Server::ioSecure, this );
        //m_io_insecure_thread = new thread( &Server::ioInsecure, this );
        ioInsecure();
        //ioRun();
        lock.lock();
        m_io_running = false;
        m_router_cvar.notify_all();

        m_msg_router_thread->join();
        delete m_msg_router_thread;
        m_msg_router_thread = 0;

        m_maint_thread->join();
        delete m_maint_thread;
        m_maint_thread = 0;
    }
}


void
Server::stop( bool a_wait )
{
    unique_lock<mutex> lock(m_api_mutex);

    if ( m_io_running )
    {
#if 0
        // Signal ioPump to stop
        m_io_service.stop();

        if ( a_wait )
        {
            if ( m_io_thread )
            {
                m_io_thread->join();
                delete m_io_thread;

                m_io_thread = 0;
                m_io_running = false;
            }
            else
            {
                while( m_io_running )
                    m_router_cvar.wait( lock );
            }

            m_msg_router_thread->join();
            delete m_msg_router_thread;
            m_msg_router_thread = 0;

            m_xfr_thread->join();
            delete m_xfr_thread;
            m_xfr_thread = 0;

            m_maint_thread->join();
            delete m_maint_thread;
            m_maint_thread = 0;
        }
#endif
    }
}


void
Server::wait()
{
    unique_lock<mutex> lock(m_api_mutex);

#if 0

    if ( m_io_running )
    {
        if ( m_io_thread )
        {
            m_io_thread->join();
            delete m_io_thread;

            m_io_thread = 0;
            m_io_running = false;

            m_msg_router_thread->join();
            delete m_msg_router_thread;
            m_msg_router_thread = 0;

            m_xfr_thread->join();
            delete m_xfr_thread;
            m_xfr_thread = 0;

            m_maint_thread->join();
            delete m_maint_thread;
            m_maint_thread = 0;
        }
        else
        {
            while( m_io_running )
                m_router_cvar.wait( lock );
        }
    }
#endif
}

/*
void
Server::ioRun()
{
    DL_INFO( "io thread started" );

    if ( m_io_service.stopped() )
        m_io_service.reset();
    
    if ( m_num_threads == 0 )
        m_num_threads = max( 1u, std::thread::hardware_concurrency() - 1 );

    accept();

    vector<thread*> io_threads;

    for ( uint32_t i = m_num_threads - 1; i > 0; i-- )
    {
        io_threads.push_back( new thread( [this](){ m_io_service.run(); } ));
        DL_DEBUG( "io extra thread started" );
    }

    m_io_service.run();

    for ( vector<thread*>::iterator t = io_threads.begin(); t != io_threads.end(); ++t )
    {
        (*t)->join();
        delete *t;
        DL_DEBUG( "io extra thread stopped" );
    }

    DL_INFO( "io thread stopped" );
}
*/

void
Server::msgRouter()
{
    void * ctx = MsgComm::getContext();

    void *frontend = zmq_socket( ctx, ZMQ_ROUTER );
    int linger = 100;
    zmq_setsockopt( frontend, ZMQ_LINGER, &linger, sizeof( int ));
    zmq_bind( frontend, "inproc://msg_proc" );

    void *backend = zmq_socket( ctx, ZMQ_DEALER );
    zmq_setsockopt( backend, ZMQ_LINGER, &linger, sizeof( int ));

    zmq_bind( backend, "inproc://workers" );

    void *control = zmq_socket( ctx, ZMQ_SUB );
    zmq_setsockopt( control, ZMQ_LINGER, &linger, sizeof( int ));
    zmq_connect( control, "inproc://control" );
    zmq_setsockopt( control, ZMQ_SUBSCRIBE, "", 0 );

    // Ceate worker threads
    for ( uint16_t t = 0; t < m_num_workers; ++t )
        m_workers.push_back( new Worker( *this, t+1 ));

    // Connect backend to frontend via a proxy
    zmq_proxy_steerable( frontend, backend, 0, control );

    zmq_close( backend );
    zmq_close( control );

    // Clean-up workers
    vector<Worker*>::iterator iwrk;

    for ( iwrk = m_workers.begin(); iwrk != m_workers.end(); ++iwrk )
        (*iwrk)->stop();

    for ( iwrk = m_workers.begin(); iwrk != m_workers.end(); ++iwrk )
        delete *iwrk;
}

void
Server::ioSecure()
{
    MsgComm::SecurityContext sec_ctx;
    sec_ctx.is_server = true;
    sec_ctx.public_key = "B8Bf9bleT89>9oR/EO#&j^6<F6g)JcXj0.<tMc9[";
    sec_ctx.private_key = "k*m3JEK{Ga@+8yDZcJavA*=[<rEa7>x2I>3HD84U";
    sec_ctx.server_key = "B8Bf9bleT89>9oR/EO#&j^6<F6g)JcXj0.<tMc9[";

    MsgComm frontend( "tcp://*:9002", ZMQ_ROUTER, true, &sec_ctx );
    MsgComm backend( "inproc://msg_proc", ZMQ_DEALER, false );

    frontend.proxy( backend, true );

    //zmq_proxy( comm.getSocket(), backend, 0 );
}

void
Server::ioInsecure()
{
    MsgComm comm( "tcp://*:9001", ZMQ_ROUTER, true );

    int linger = 100;
    void * ctx = MsgComm::getContext();
    void *backend = zmq_socket( ctx, ZMQ_DEALER );
    zmq_setsockopt( backend, ZMQ_LINGER, &linger, sizeof( int ));
    zmq_connect( backend, "inproc://msg_proc" );

    zmq_proxy( comm.getSocket(), backend, 0 );
}

/*
void
Server::accept()
{
    spSession session = make_shared<Session>( m_io_service, m_context, *this, m_db_url, m_db_user, m_db_pass );

    m_acceptor.async_accept( session->getSocket(),
        [this, session]( error_code ec )
            {
                if ( !ec )
                {
                    DL_INFO( "New connection from " << session->remoteAddress() );

                    unique_lock<mutex>  lock( m_data_mutex );
                    m_sessions.insert( session );
                    lock.unlock();

                    session->start();
                }

                accept();
            });
}
*/

void
Server::backgroundMaintenance()
{
    DL_DEBUG( "Maint thread started" );

    try
    {
        struct timespec             _t;
        double                      t;
        //set<spSession>::iterator    isess;
        vector<string>::iterator    idel;
        Auth::RepoDataDeleteRequest req;
        MsgBuf::Message *           reply;
        MsgBuf::Frame               frame;
        string                      uid;
        MsgComm                     repo_comm( m_repo_address, ZMQ_DEALER, false, &m_sec_ctx );
        map<string,pair<string,size_t>>::iterator itrans_client;

        //vector<spSession>           dead_sessions;
        //dead_sessions.reserve( 10 );

        while( m_io_running )
        {
            sleep( MAINT_POLL_INTERVAL );

            lock_guard<mutex> lock( m_data_mutex );

            clock_gettime( CLOCK_REALTIME, &_t );
            t = _t.tv_sec + (_t.tv_nsec*1e-9);

/*
            for ( isess = m_sessions.begin(); isess != m_sessions.end(); )
            {
                if ( t - (*isess)->lastAccessTime() > CLIENT_IDLE_TIMEOUT )
                {
                    cout << "CLOSING IDLE SESSION\n";
                    (*isess)->close();
                    isess = m_sessions.erase( isess );
                }
                else
                    ++isess;
            }
*/

            // Delete expired transient client credentials
            for ( itrans_client = m_trans_auth_clients.begin(); itrans_client != m_trans_auth_clients.end(); )
            {
                if ( itrans_client->second.second < t )
                {
                    cout << "Delete expired trans client " << itrans_client->second.first << "\n";
                    itrans_client = m_trans_auth_clients.erase( itrans_client );
                }
                else
                    itrans_client++;
            }

            // Process data deletion requests
            try
            {
                // TODO This needs to be re-written in an async manner
                if ( m_data_delete.size() )
                {
                    for ( idel = m_data_delete.begin(); idel !=  m_data_delete.end(); ++idel )
                    {
                        req.set_id( *idel );
                        repo_comm.send( req );
                        if ( !repo_comm.recv( reply, uid, frame, 5000 ))
                        {
                            cout << "No response from repo server!\n";
                            break;
                        }
                        else
                            delete reply;
                    }
                }
                m_data_delete.clear();
            }
            catch( ... )
            {
                cout << "Exception on delete data\n";
            }
    /*
            for ( isess = dead_sessions.begin(); isess != dead_sessions.end(); ++isess )
            {
                DL_INFO( "Deleting inactive client " << *isess );
                delete *isess;
            }

            dead_sessions.clear();
    */
        }
    }
    catch( TraceException & e )
    {
        DL_ERROR( "Maint thread: " << e.toString() );
    }
    catch( exception & e )
    {
        DL_ERROR( "Maint thread: " << e.what() );
    }
    catch( ... )
    {
        DL_ERROR( "Maint thread: unkown exception " );
    }

    DL_DEBUG( "Maint thread stopped" );
}




/*
void
Server::sessionClosed( spSession a_session )
{
    lock_guard<mutex> lock( m_data_mutex );
    set<spSession>::iterator isess = m_sessions.find( a_session );
    if ( isess != m_sessions.end() )
        m_sessions.erase( isess );
}
*/

void
Server::generateKeys( const std::string & a_uid, std::string & a_key_data )
{
    string key_file = m_key_path + a_uid + "-key";

    string cmd = "yes|ssh-keygen -q -t rsa -b 2048 -P '' -C \"SDMS SSH Key for " + a_uid + "\" -f " + key_file;
    //cout << "cmd: " << cmd << "\n";

    lock_guard<mutex> lock( m_key_mutex );

    if ( system( cmd.c_str() ))
        EXCEPT( ID_SERVICE_ERROR, "SSH key generation failed." );

    ifstream inf( key_file + ".pub" );
    if ( !inf.is_open() || !inf.good() )
        EXCEPT( ID_SERVICE_ERROR, "Could not open new ssh public key file" );

    a_key_data.assign(( istreambuf_iterator<char>(inf)), istreambuf_iterator<char>());

    inf.close();
}


void
Server::getPublicKey( const std::string & a_uid, std::string & a_key_data )
{
    string key_file = m_key_path + a_uid + "-key.pub";

    lock_guard<mutex> lock( m_key_mutex );

    ifstream inf( key_file );
    if ( !inf.is_open() || !inf.good() )
        EXCEPT( ID_SERVICE_ERROR, "No SSH key available" );

    a_key_data.assign(( istreambuf_iterator<char>(inf)), istreambuf_iterator<char>());

    inf.close();
}


void
Server::handleNewXfr( const XfrData & a_xfr, const string & a_uid )
{
    m_xfr_mgr.newXfr( a_xfr, a_uid );
}

void
Server::dataDelete( const std::string & a_data_id )
{
    lock_guard<mutex> lock( m_data_mutex );
    m_data_delete.push_back( a_data_id );
}


void
Server::zapHandler()
{
    DL_INFO( "ZAP handler thread starting" );
    
    try
    {
        void * ctx = MsgComm::getContext();

        char    client_key_text[41];
        void *  socket = zmq_socket( ctx, ZMQ_REP );
        int     rc;
        char    version[100];
        char    request_id[100];
        char    domain[100];
        char    address[100];
        char    identity_property[100];
        char    mechanism[100];
        char    client_key[100];
        map<string,string>::iterator iclient;
        map<string,pair<string,size_t>>::iterator itrans_client;
        zmq_pollitem_t poll_items[] = { socket, 0, ZMQ_POLLIN, 0 };
        string uid;
        DatabaseClient  db_client( m_db_url, m_db_user, m_db_pass );

        db_client.setClient( "sdms" );

        if (( rc = zmq_bind( socket, "inproc://zeromq.zap.01" )) == -1 )
            EXCEPT( 1, "Bind on ZAP failed." );

        while ( 1 )
        {
            try
            {
                if (( rc = zmq_poll( poll_items, 1, 2000 )) == -1 )
                    EXCEPT( 1, "Poll on ZAP socket failed." );

                if ( !(poll_items[0].revents & ZMQ_POLLIN ))
                    continue;

                cout << "Got zap data\n";

                if (( rc = zmq_recv( socket, version, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv version failed." );
                version[rc] = 0;
                if (( rc = zmq_recv( socket, request_id, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv request_id failed." );
                request_id[rc] = 0;
                if (( rc = zmq_recv( socket, domain, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv domain failed." );
                domain[rc] = 0;
                if (( rc = zmq_recv( socket, address, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv address failed." );
                address[rc] = 0;
                if (( rc = zmq_recv( socket, identity_property, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv identity_property failed." );
                identity_property[rc] = 0;
                if (( rc = zmq_recv( socket, mechanism, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv mechanism failed." );
                mechanism[rc] = 0;
                if (( rc = zmq_recv( socket, client_key, 100, 0 )) == -1 )
                    EXCEPT( 1, "Rcv client_key failed." );
                client_key[rc] = 0;

                if ( rc != 32 )
                    EXCEPT( 1, "Invalid client_key length." );

                if ( !zmq_z85_encode( client_key_text, (uint8_t*)client_key, 32 ))
                    EXCEPT( 1, "Encode of client_key failed." );

                cout << "ZAP request:" <<
                    "\n\tversion: " << version <<
                    "\n\trequest_id: " << request_id <<
                    "\n\tdomain: " << domain <<
                    "\n\taddress: " << address <<
                    "\n\tidentity_property: " << identity_property <<
                    "\n\tmechanism: " << mechanism <<
                    "\n\tclient_key: " << client_key_text << "\n";

                // Always accept - but only set UID if it's a known client (by key)
                if (( iclient = m_auth_clients.find( client_key_text )) != m_auth_clients.end())
                {
                    cout << "ZAP: Known pre-authorized client\n";
                    uid = iclient->second;
                }
                else if (( itrans_client = m_trans_auth_clients.find( client_key_text )) != m_trans_auth_clients.end())
                {
                    cout << "ZAP: Known transient client\n";
                    uid = itrans_client->second.first;
                }
                else
                {
                    if ( db_client.uidByPubKey( client_key_text, uid ) )
                    {
                        cout << "ZAP: Known client " << uid << "\n";
                    }
                    else
                    {
                        uid = string("anon_") + client_key_text;
                        cout << "ZAP: UNKNOWN client " << uid << "\n";
                    }
                }

                zmq_send( socket, "1.0", 3, ZMQ_SNDMORE );
                zmq_send( socket, request_id, strlen(request_id), ZMQ_SNDMORE );
                zmq_send( socket, "200", 3, ZMQ_SNDMORE );
                zmq_send( socket, "", 0, ZMQ_SNDMORE );
                zmq_send( socket, uid.c_str(), uid.size(), ZMQ_SNDMORE );
                zmq_send( socket, "", 0, 0 );
            }
            catch( TraceException & e )
            {
                cout << "ZAP handler:" << e.toString() << "\n";
            }
            catch( exception & e )
            {
                cout << "ZAP handler:" << e.what() << "\n";
            }
            catch( ... )
            {
                cout << "ZAP handler: unknown exception type\n";
            }
        }

        zmq_close( socket );
    }
    catch( TraceException & e )
    {
        DL_ERROR( "ZAP handler:" << e.toString() );
    }
    catch( exception & e )
    {
        DL_ERROR( "ZAP handler:" << e.what() );
    }
    catch( ... )
    {
        DL_ERROR( "ZAP handler: unknown exception type" );
    }
    DL_INFO( "ZAP handler thread exiting" );
}


void
Server::authorizeClient( const std::string & a_cert_uid, const std::string & a_uid )
{
    if ( strncmp( a_cert_uid.c_str(), "anon_", 5 ) == 0 )
    {
        struct timespec             _t;

        lock_guard<mutex> lock( m_data_mutex );
        clock_gettime( CLOCK_REALTIME, &_t );

        m_trans_auth_clients[a_cert_uid.substr( 5 )] = make_pair<>( a_uid, _t.tv_sec + 10 );
    }
}


}}
