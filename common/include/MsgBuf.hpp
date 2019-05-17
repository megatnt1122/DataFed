#ifndef MSGBUF_HPP
#define MSGBUF_HPP

#include <iostream>
#include <string>
#include <map>
#include <stdint.h>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include "TraceException.hpp"

// TODO Need to add host-network conversions for buffer frame fields


// typically 5 bytes per router (internal), or larger for external
#define MAX_ROUTE_LEN   50
// Able to store a UUID string
#define MAX_UID_LEN     100
#define REG_PROTO(ns) MsgBuf::registerProtocol( ns::Protocol_descriptor() )

class MsgBuf
{
public:
    typedef ::google::protobuf::Descriptor                  DescriptorType;
    typedef ::google::protobuf::FileDescriptor              FileDescriptorType;
    typedef ::google::protobuf::MessageFactory              Factory;
    typedef ::google::protobuf::Message                     Message;
    typedef std::map<uint8_t,const FileDescriptorType *>    FileDescriptorMap;
    typedef std::map<uint16_t,const DescriptorType *>       DescriptorMap;
    typedef std::map<const DescriptorType *,uint16_t>       MsgTypeMap;

    enum ErrorCode
    {
        EC_OK = 0,
        EC_PROTO_INIT,
        EC_INVALID_PARAM,
        EC_INVALID_STATE,
        EC_SERIALIZE,
        EC_UNSERIALIZE
    };

    struct Frame
    {
        Frame() : size(0), proto_id(0), msg_id(0), context(0) {}

        void clear()
        { 
            size = 0;
            proto_id = 0;
            msg_id = 0;
            context = 0;
        }

        inline uint16_t getMsgType() const
        {
            return ( ((uint16_t)proto_id) << 8 ) | msg_id;
        }

        uint32_t    size;       // Size of buffer
        uint8_t     proto_id;
        uint8_t     msg_id;
        uint16_t    context;
    };


    MsgBuf( uint32_t a_capacity = 0 ) : m_buffer(0), m_capacity(0)
    {
        m_route[0] = 0;

        if ( a_capacity )
            ensureCapacity( a_capacity );
    }

    MsgBuf( const std::string & a_uid, uint16_t a_context = 0, uint32_t a_capacity = 0 ) : m_buffer(0), m_capacity(0), m_uid(a_uid)
    {
        m_frame.context = a_context;
        m_route[0] = 0;

        if ( a_capacity )
            ensureCapacity( a_capacity );
    }

    ~MsgBuf()
    {
        if ( m_buffer )
            delete[] m_buffer;
    }


    void clear()
    {
        m_route[0] = 0;
        m_uid.clear();
        m_frame.clear();

        if ( m_buffer )
        {
            delete[] m_buffer;
            m_buffer = 0;
            m_capacity = 0;
        }
    }


    inline Frame & getFrame()
    {
        return m_frame;
    }

    inline const Frame & getFrame() const
    {
        return m_frame;
    }

    inline uint16_t getMsgType() const
    {
        return ( ((uint16_t)m_frame.proto_id) << 8 ) | m_frame.msg_id;
    }

    inline char * getBuffer()
    {
        return m_buffer;
    }

    inline const char * getBuffer() const
    {
        return m_buffer;
    }

    inline const uint8_t * getRouteBuffer() const
    {
        return m_route;
    }

    inline uint8_t * getRouteBuffer()
    {
        return m_route;
    }

    inline uint8_t getRouteMaxLen() const
    {
        return MAX_ROUTE_LEN;
    }

    inline const std::string & getUID() const
    {
        return m_uid;
    }

    inline void setUID( const char * a_uid, size_t a_len = 0 )
    {
        if ( a_len )
            m_uid.assign( a_uid, a_len );
        else
            m_uid = a_uid; // Null-term str
    }

    inline void setUID( const std::string & a_uid )
    {
        m_uid = a_uid;
    }

    inline void clearUID()
    {
        m_uid.clear();
    }

    char * acquireBuffer()
    {
        if ( !m_buffer )
            EXCEPT_PARAM( EC_INVALID_STATE, "Attempt to acquire empty/null buffer." );

        char * buffer = m_buffer;

        m_buffer = 0;
        m_capacity = 0;
        m_frame.clear();

        return buffer;
    }

    void ensureCapacity( uint32_t a_size )
    {
        if ( a_size > m_capacity )
        {
            char *new_buffer = new char[a_size];
            if ( m_buffer )
                delete[] m_buffer;
            m_buffer = new_buffer;
            m_capacity = a_size;
        }
    }

    static uint8_t registerProtocol( const ::google::protobuf::EnumDescriptor * a_enum_desc )
    {
        if ( a_enum_desc->name() != "Protocol" )
            EXCEPT( EC_PROTO_INIT, "Must register with Protocol EnumDescriptor." );

        const FileDescriptorType * file = a_enum_desc->file();
        if ( !file )
            EXCEPT( EC_PROTO_INIT, "Failed to acquire protocol buffer file descriptor." );

        const google::protobuf::EnumValueDescriptor * val_desc = a_enum_desc->FindValueByName("ID");
        if ( !val_desc )
            EXCEPT( EC_PROTO_INIT, "Protocol enum missing required ID field." );

        uint16_t id = val_desc->number();
        getFileDescriptorMap()[id] = file;

        int count = file->message_type_count();
        const DescriptorType * desc;
        std::map<std::string,const DescriptorType*> msg_types;
        DescriptorMap & desc_map = getDescriptorMap();
        MsgTypeMap & mt_map = getMsgTypeMap();

        for ( int i = 0; i < count; i++ )
        {
            desc = file->message_type(i);
            msg_types[desc->name()] = desc;
        }

        uint16_t msg_type = id << 8;
        for ( std::map<std::string,const DescriptorType*>::iterator m = msg_types.begin(); m != msg_types.end(); m++, msg_type++ )
        {
            //std::cout << "MT: " << msg_type << " = " << m->second->name() << "\n";
            desc_map[msg_type] = m->second;
            mt_map[m->second] = msg_type;
        }

        
/*
        DescriptorMap::iterator iProto = getDescriptorMap().find( id );
        if ( iProto == getDescriptorMap().end() )
            getDescriptorMap()[id] = file;
*/
        return id;
    }


    static uint16_t findMessageType( uint8_t a_proto_id, const std::string & a_message_name )
    {
        FileDescriptorMap::iterator iProto = getFileDescriptorMap().find( a_proto_id );

        if ( iProto == getFileDescriptorMap().end() )
            EXCEPT_PARAM( EC_INVALID_PARAM, "Protocol ID " << a_proto_id << " has not been registered." );

        const DescriptorType *desc = iProto->second->FindMessageTypeByName( a_message_name );
        if ( !desc )
            EXCEPT_PARAM( EC_PROTO_INIT, "Could not find specified message: " << a_message_name << " for protocol: " << (unsigned int)a_proto_id );

        MsgTypeMap & mt_map = getMsgTypeMap();
        MsgTypeMap::iterator i_mt = mt_map.find( desc );
        if ( i_mt == mt_map.end() )
            EXCEPT_PARAM( EC_INVALID_PARAM, "Message name \"" << a_message_name << "\" is not registered with protocol " << a_proto_id );

        return i_mt->second;
    }


    inline Message* unserialize() const
    {
        return unserialize( m_frame, m_buffer );
    }


    static Message* unserialize( const Frame & a_frame, const char * a_buffer )
    {
        //if ( !a_buffer )
        //    EXCEPT_PARAM( EC_UNSERIALIZE, "Attempt to unserialize empty/null buffer." );
        //std::cout << "unserialize msg type " << a_frame.getMsgType() << "\n";

        //DescriptorMap::iterator iProto = getDescriptorMap().find( a_frame.proto_id );
        DescriptorMap::iterator iDesc = getDescriptorMap().find( a_frame.getMsgType() );
        if ( iDesc != getDescriptorMap().end() )
        {
            //std::cout << "msg class " << iDesc->second->name() << "\n";

            //if ( a_frame.msg_id < (uint8_t)iProto->second->message_type_count())
            //{
                //cout << "proto " << a_msg_buffer.a_frame.proto_id << "found" << endl;

                const DescriptorType * msg_descriptor = iDesc->second; //iProto->second->message_type( a_frame.msg_id );
                const Message * default_msg = getFactory().GetPrototype( msg_descriptor );

                Message * msg = default_msg->New();

                if ( msg )
                {
                    // Some message types do not have any content and will not need to be parsed (and buffer may be null/empty)
                    if ( msg->ParseFromArray( a_buffer, a_frame.size ))
                        return msg;
                    else
                        delete msg;
                }
            //}
            //else
            //{
            //    EXCEPT_PARAM( EC_PROTO_INIT, "Unserialize failed: invalid message type " << (unsigned int)a_frame.msg_id );
            //}
        }
        else
        {
            EXCEPT_PARAM( EC_PROTO_INIT, "Unserialize failed: unregistered message type " << a_frame.getMsgType());
        }

        return 0;
    }


    void serialize( Message & a_msg )
    {
        if ( !a_msg.IsInitialized() )
            EXCEPT( EC_SERIALIZE, "Message is missing required fields" );

        const DescriptorType * desc = a_msg.GetDescriptor();
        MsgTypeMap & mt_map = getMsgTypeMap();
        MsgTypeMap::iterator i_mt = mt_map.find( desc );
        if ( i_mt == mt_map.end() )
            EXCEPT_PARAM( EC_SERIALIZE, "Attempt to serialize unregistered message type: " << desc->name() )

        //std::cout << "serialize msg type: " << i_mt->second << ", " << desc->name() << "\n";

        m_frame.proto_id = i_mt->second >> 8;
        m_frame.msg_id = i_mt->second & 0xFF;
        m_frame.size = a_msg.ByteSize();

        // Only serialize if message type has content
        if ( m_frame.size )
        {
            ensureCapacity( m_frame.size );

            // Serialize message - may fail if required fields are missing
            if ( !a_msg.SerializeToArray( m_buffer, m_frame.size ))
                EXCEPT( EC_SERIALIZE, "SerializeToArray for message failed." );
        }
    }

private:
    static google::protobuf::MessageFactory & getFactory()
    {
        static Factory * _factory = Factory::generated_factory();

        return *_factory;
    }

    static FileDescriptorMap & getFileDescriptorMap()
    {
        static FileDescriptorMap _descriptor_map;
        
        return _descriptor_map;
    }

    static DescriptorMap & getDescriptorMap()
    {
        static DescriptorMap _descriptor_map;
        
        return _descriptor_map;
    }

    static MsgTypeMap & getMsgTypeMap()
    {
        static MsgTypeMap _msg_type_map;
        
        return _msg_type_map;
    }


    Frame       m_frame;
    char *      m_buffer;
    uint32_t    m_capacity;
    uint8_t     m_route[MAX_ROUTE_LEN]; // Byte 0 = length
    std::string m_uid;
};


#endif // MSGBUF_HPP