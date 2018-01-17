#include <iostream>
#include <unistd.h>

#include <time.h>

#define timerDef() struct timespec _T0 = {0,0}, _T1 = {0,0}
#define timerStart() clock_gettime(CLOCK_REALTIME,&_T0)
#define timerStop() clock_gettime(CLOCK_REALTIME,&_T1)
#define timerElapsed() ((_T1.tv_sec - _T0.tv_sec) + ((_T1.tv_nsec - _T0.tv_nsec)/1.0e9))

#include "Client.hpp"

using namespace std;
using namespace SDMS;
using namespace SDMS::Facility;

int main( int a_argc, char ** a_argv )
{
    try
    {
        const char * host = "localhost";
        int port = 5800;
        int timeout = 5;
        int opt;

        while (( opt = getopt( a_argc, a_argv, "?h:p:t:" )) != -1 )
        {
            switch( opt )
            {
            case '?':
                cout << "options:" << endl;
                cout << "? - show help" << endl;
                cout << "h - server hostname" << endl;
                cout << "p - server port" << endl;
                cout << "t - timeout (sec)" << endl;
                return 0;
            case 'h':
                host = optarg;
                break;
            case 'p':
                port = atoi( optarg );
                break;
            case 't':
                timeout = atoi( optarg );
                break;
            }
        }

        Client client( host, port, timeout );

        client.ping();

        client.login();

/*
        timerDef();
        timerStart();

        for ( int i = 0; i < 10000; ++i )
            client.ping();

        timerStop();
        cout << "ping rate: " << 10000/timerElapsed() << " p/s\n";
*/

    }
    catch( exception &e )
    {
        cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
