// Copyright 2009 Minor Gordon.
// This source comes from the XtreemFS project. It is licensed under the GPLv2 (see COPYING for terms and conditions).

    #ifndef _XTREEMFS_INTERFACES_MRC_OSD_TYPES_H_
    #define _XTREEMFS_INTERFACES_MRC_OSD_TYPES_H_

    #include "types.h"
#include "yidl.h"
#include <vector>


namespace org
{
  namespace xtreemfs
  {
    namespace interfaces
    {
      enum AccessControlPolicyType { ACCESS_CONTROL_POLICY_NULL = 1, ACCESS_CONTROL_POLICY_POSIX = 2, ACCESS_CONTROL_POLICY_VOLUME = 3 };
      enum OSDSelectionPolicyType { OSD_SELECTION_POLICY_FILTER_DEFAULT = 1000, OSD_SELECTION_POLICY_FILTER_FQDN = 1001, OSD_SELECTION_POLICY_GROUP_DCMAP = 2000, OSD_SELECTION_POLICY_GROUP_FQDN = 2001, OSD_SELECTION_POLICY_SORT_RANDOM = 3000, OSD_SELECTION_POLICY_SORT_DCMAP = 3001, OSD_SELECTION_POLICY_SORT_FQDN = 3002 };
      enum ReplicaSelectionPolicyType { REPLICA_SELECTION_POLICY_SIMPLE = 1 };
      enum StripingPolicyType { STRIPING_POLICY_RAID0 = 0 };


      class NewFileSize : public ::yidl::runtime::Struct
      {
      public:
        NewFileSize() : size_in_bytes( 0 ), truncate_epoch( 0 ) { }
        NewFileSize( uint64_t size_in_bytes, uint32_t truncate_epoch ) : size_in_bytes( size_in_bytes ), truncate_epoch( truncate_epoch ) { }
        virtual ~NewFileSize() { }

        void set_size_in_bytes( uint64_t size_in_bytes ) { this->size_in_bytes = size_in_bytes; }
        uint64_t get_size_in_bytes() const { return size_in_bytes; }
        void set_truncate_epoch( uint32_t truncate_epoch ) { this->truncate_epoch = truncate_epoch; }
        uint32_t get_truncate_epoch() const { return truncate_epoch; }

        bool operator==( const NewFileSize& other ) const { return size_in_bytes == other.size_in_bytes && truncate_epoch == other.truncate_epoch; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( NewFileSize, 2009090220 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeUint64( "size_in_bytes", 0, size_in_bytes ); marshaller.writeUint32( "truncate_epoch", 0, truncate_epoch ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { size_in_bytes = unmarshaller.readUint64( "size_in_bytes", 0 ); truncate_epoch = unmarshaller.readUint32( "truncate_epoch", 0 ); }

      protected:
        uint64_t size_in_bytes;
        uint32_t truncate_epoch;
      };

      class NewFileSizeSet : public ::yidl::runtime::Sequence, public std::vector<org::xtreemfs::interfaces::NewFileSize>
      {
      public:
        NewFileSizeSet() { }
        NewFileSizeSet( const org::xtreemfs::interfaces::NewFileSize& first_value ) { std::vector<org::xtreemfs::interfaces::NewFileSize>::push_back( first_value ); }
        NewFileSizeSet( size_type size ) : std::vector<org::xtreemfs::interfaces::NewFileSize>( size ) { }
        virtual ~NewFileSizeSet() { }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( NewFileSizeSet, 2009090221 );

        // yidl::Sequence
        size_t get_size() const { return size(); }
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { size_type value_i_max = size(); for ( size_type value_i = 0; value_i < value_i_max; value_i++ ) { marshaller.writeStruct( "value", 0, ( *this )[value_i] ); } }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { org::xtreemfs::interfaces::NewFileSize value; unmarshaller.readStruct( "value", 0, value ); push_back( value ); }
      };

      class OSDtoMRCData : public ::yidl::runtime::Struct
      {
      public:
        OSDtoMRCData() : caching_policy( 0 ) { }
        OSDtoMRCData( uint8_t caching_policy, const std::string& data ) : caching_policy( caching_policy ), data( data ) { }
        OSDtoMRCData( uint8_t caching_policy, const char* data, size_t data_len ) : caching_policy( caching_policy ), data( data, data_len ) { }
        virtual ~OSDtoMRCData() { }

        void set_caching_policy( uint8_t caching_policy ) { this->caching_policy = caching_policy; }
        uint8_t get_caching_policy() const { return caching_policy; }
        void set_data( const std::string& data ) { set_data( data.c_str(), data.size() ); }
        void set_data( const char* data, size_t data_len ) { this->data.assign( data, data_len ); }
        const std::string& get_data() const { return data; }

        bool operator==( const OSDtoMRCData& other ) const { return caching_policy == other.caching_policy && data == other.data; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( OSDtoMRCData, 2009090222 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeUint8( "caching_policy", 0, caching_policy ); marshaller.writeString( "data", 0, data ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { caching_policy = unmarshaller.readUint8( "caching_policy", 0 ); unmarshaller.readString( "data", 0, data ); }

      protected:
        uint8_t caching_policy;
        std::string data;
      };

      class OSDtoMRCDataSet : public ::yidl::runtime::Sequence, public std::vector<org::xtreemfs::interfaces::OSDtoMRCData>
      {
      public:
        OSDtoMRCDataSet() { }
        OSDtoMRCDataSet( const org::xtreemfs::interfaces::OSDtoMRCData& first_value ) { std::vector<org::xtreemfs::interfaces::OSDtoMRCData>::push_back( first_value ); }
        OSDtoMRCDataSet( size_type size ) : std::vector<org::xtreemfs::interfaces::OSDtoMRCData>( size ) { }
        virtual ~OSDtoMRCDataSet() { }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( OSDtoMRCDataSet, 2009090223 );

        // yidl::Sequence
        size_t get_size() const { return size(); }
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { size_type value_i_max = size(); for ( size_type value_i = 0; value_i < value_i_max; value_i++ ) { marshaller.writeStruct( "value", 0, ( *this )[value_i] ); } }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { org::xtreemfs::interfaces::OSDtoMRCData value; unmarshaller.readStruct( "value", 0, value ); push_back( value ); }
      };

      class OSDWriteResponse : public ::yidl::runtime::Struct
      {
      public:
        OSDWriteResponse() { }
        OSDWriteResponse( const org::xtreemfs::interfaces::NewFileSizeSet& new_file_size, const org::xtreemfs::interfaces::OSDtoMRCDataSet& opaque_data ) : new_file_size( new_file_size ), opaque_data( opaque_data ) { }
        virtual ~OSDWriteResponse() { }

        void set_new_file_size( const org::xtreemfs::interfaces::NewFileSizeSet&  new_file_size ) { this->new_file_size = new_file_size; }
        const org::xtreemfs::interfaces::NewFileSizeSet& get_new_file_size() const { return new_file_size; }
        void set_opaque_data( const org::xtreemfs::interfaces::OSDtoMRCDataSet&  opaque_data ) { this->opaque_data = opaque_data; }
        const org::xtreemfs::interfaces::OSDtoMRCDataSet& get_opaque_data() const { return opaque_data; }

        bool operator==( const OSDWriteResponse& other ) const { return new_file_size == other.new_file_size && opaque_data == other.opaque_data; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( OSDWriteResponse, 2009090226 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeSequence( "new_file_size", 0, new_file_size ); marshaller.writeSequence( "opaque_data", 0, opaque_data ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { unmarshaller.readSequence( "new_file_size", 0, new_file_size ); unmarshaller.readSequence( "opaque_data", 0, opaque_data ); }

      protected:
        org::xtreemfs::interfaces::NewFileSizeSet new_file_size;
        org::xtreemfs::interfaces::OSDtoMRCDataSet opaque_data;
      };

      class StripingPolicy : public ::yidl::runtime::Struct
      {
      public:
        StripingPolicy() : type( STRIPING_POLICY_RAID0 ), stripe_size( 0 ), width( 0 ) { }
        StripingPolicy( org::xtreemfs::interfaces::StripingPolicyType type, uint32_t stripe_size, uint32_t width ) : type( type ), stripe_size( stripe_size ), width( width ) { }
        virtual ~StripingPolicy() { }

        void set_type( org::xtreemfs::interfaces::StripingPolicyType type ) { this->type = type; }
        org::xtreemfs::interfaces::StripingPolicyType get_type() const { return type; }
        void set_stripe_size( uint32_t stripe_size ) { this->stripe_size = stripe_size; }
        uint32_t get_stripe_size() const { return stripe_size; }
        void set_width( uint32_t width ) { this->width = width; }
        uint32_t get_width() const { return width; }

        bool operator==( const StripingPolicy& other ) const { return type == other.type && stripe_size == other.stripe_size && width == other.width; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( StripingPolicy, 2009090228 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeInt32( "type", 0, static_cast<int32_t>( type ) ); marshaller.writeUint32( "stripe_size", 0, stripe_size ); marshaller.writeUint32( "width", 0, width ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { type = ( org::xtreemfs::interfaces::StripingPolicyType )unmarshaller.readInt32( "type", 0 ); stripe_size = unmarshaller.readUint32( "stripe_size", 0 ); width = unmarshaller.readUint32( "width", 0 ); }

      protected:
        org::xtreemfs::interfaces::StripingPolicyType type;
        uint32_t stripe_size;
        uint32_t width;
      };

      class Replica : public ::yidl::runtime::Struct
      {
      public:
        Replica() : replication_flags( 0 ) { }
        Replica( const org::xtreemfs::interfaces::StripingPolicy& striping_policy, uint32_t replication_flags, const org::xtreemfs::interfaces::StringSet& osd_uuids ) : striping_policy( striping_policy ), replication_flags( replication_flags ), osd_uuids( osd_uuids ) { }
        virtual ~Replica() { }

        void set_striping_policy( const org::xtreemfs::interfaces::StripingPolicy&  striping_policy ) { this->striping_policy = striping_policy; }
        const org::xtreemfs::interfaces::StripingPolicy& get_striping_policy() const { return striping_policy; }
        void set_replication_flags( uint32_t replication_flags ) { this->replication_flags = replication_flags; }
        uint32_t get_replication_flags() const { return replication_flags; }
        void set_osd_uuids( const org::xtreemfs::interfaces::StringSet&  osd_uuids ) { this->osd_uuids = osd_uuids; }
        const org::xtreemfs::interfaces::StringSet& get_osd_uuids() const { return osd_uuids; }

        bool operator==( const Replica& other ) const { return striping_policy == other.striping_policy && replication_flags == other.replication_flags && osd_uuids == other.osd_uuids; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( Replica, 2009090229 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeStruct( "striping_policy", 0, striping_policy ); marshaller.writeUint32( "replication_flags", 0, replication_flags ); marshaller.writeSequence( "osd_uuids", 0, osd_uuids ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { unmarshaller.readStruct( "striping_policy", 0, striping_policy ); replication_flags = unmarshaller.readUint32( "replication_flags", 0 ); unmarshaller.readSequence( "osd_uuids", 0, osd_uuids ); }

      protected:
        org::xtreemfs::interfaces::StripingPolicy striping_policy;
        uint32_t replication_flags;
        org::xtreemfs::interfaces::StringSet osd_uuids;
      };

      class ReplicaSet : public ::yidl::runtime::Sequence, public std::vector<org::xtreemfs::interfaces::Replica>
      {
      public:
        ReplicaSet() { }
        ReplicaSet( const org::xtreemfs::interfaces::Replica& first_value ) { std::vector<org::xtreemfs::interfaces::Replica>::push_back( first_value ); }
        ReplicaSet( size_type size ) : std::vector<org::xtreemfs::interfaces::Replica>( size ) { }
        virtual ~ReplicaSet() { }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( ReplicaSet, 2009090230 );

        // yidl::Sequence
        size_t get_size() const { return size(); }
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { size_type value_i_max = size(); for ( size_type value_i = 0; value_i < value_i_max; value_i++ ) { marshaller.writeStruct( "value", 0, ( *this )[value_i] ); } }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { org::xtreemfs::interfaces::Replica value; unmarshaller.readStruct( "value", 0, value ); push_back( value ); }
      };

      class VivaldiCoordinates : public ::yidl::runtime::Struct
      {
      public:
        VivaldiCoordinates() : x_coordinate( 0 ), y_coordinate( 0 ), local_error( 0 ) { }
        VivaldiCoordinates( double x_coordinate, double y_coordinate, double local_error ) : x_coordinate( x_coordinate ), y_coordinate( y_coordinate ), local_error( local_error ) { }
        virtual ~VivaldiCoordinates() { }

        void set_x_coordinate( double x_coordinate ) { this->x_coordinate = x_coordinate; }
        double get_x_coordinate() const { return x_coordinate; }
        void set_y_coordinate( double y_coordinate ) { this->y_coordinate = y_coordinate; }
        double get_y_coordinate() const { return y_coordinate; }
        void set_local_error( double local_error ) { this->local_error = local_error; }
        double get_local_error() const { return local_error; }

        bool operator==( const VivaldiCoordinates& other ) const { return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate && local_error == other.local_error; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( VivaldiCoordinates, 2009090231 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeDouble( "x_coordinate", 0, x_coordinate ); marshaller.writeDouble( "y_coordinate", 0, y_coordinate ); marshaller.writeDouble( "local_error", 0, local_error ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { x_coordinate = unmarshaller.readDouble( "x_coordinate", 0 ); y_coordinate = unmarshaller.readDouble( "y_coordinate", 0 ); local_error = unmarshaller.readDouble( "local_error", 0 ); }

      protected:
        double x_coordinate;
        double y_coordinate;
        double local_error;
      };

      class XCap : public ::yidl::runtime::Struct
      {
      public:
        XCap() : access_mode( 0 ), expires_s( 0 ), truncate_epoch( 0 ), replicateOnClose( false ) { }
        XCap( const std::string& file_id, uint32_t access_mode, uint64_t expires_s, const std::string& client_identity, uint32_t truncate_epoch, bool replicateOnClose, const std::string& server_signature ) : file_id( file_id ), access_mode( access_mode ), expires_s( expires_s ), client_identity( client_identity ), truncate_epoch( truncate_epoch ), replicateOnClose( replicateOnClose ), server_signature( server_signature ) { }
        XCap( const char* file_id, size_t file_id_len, uint32_t access_mode, uint64_t expires_s, const char* client_identity, size_t client_identity_len, uint32_t truncate_epoch, bool replicateOnClose, const char* server_signature, size_t server_signature_len ) : file_id( file_id, file_id_len ), access_mode( access_mode ), expires_s( expires_s ), client_identity( client_identity, client_identity_len ), truncate_epoch( truncate_epoch ), replicateOnClose( replicateOnClose ), server_signature( server_signature, server_signature_len ) { }
        virtual ~XCap() { }

        void set_file_id( const std::string& file_id ) { set_file_id( file_id.c_str(), file_id.size() ); }
        void set_file_id( const char* file_id, size_t file_id_len ) { this->file_id.assign( file_id, file_id_len ); }
        const std::string& get_file_id() const { return file_id; }
        void set_access_mode( uint32_t access_mode ) { this->access_mode = access_mode; }
        uint32_t get_access_mode() const { return access_mode; }
        void set_expires_s( uint64_t expires_s ) { this->expires_s = expires_s; }
        uint64_t get_expires_s() const { return expires_s; }
        void set_client_identity( const std::string& client_identity ) { set_client_identity( client_identity.c_str(), client_identity.size() ); }
        void set_client_identity( const char* client_identity, size_t client_identity_len ) { this->client_identity.assign( client_identity, client_identity_len ); }
        const std::string& get_client_identity() const { return client_identity; }
        void set_truncate_epoch( uint32_t truncate_epoch ) { this->truncate_epoch = truncate_epoch; }
        uint32_t get_truncate_epoch() const { return truncate_epoch; }
        void set_replicateOnClose( bool replicateOnClose ) { this->replicateOnClose = replicateOnClose; }
        bool get_replicateOnClose() const { return replicateOnClose; }
        void set_server_signature( const std::string& server_signature ) { set_server_signature( server_signature.c_str(), server_signature.size() ); }
        void set_server_signature( const char* server_signature, size_t server_signature_len ) { this->server_signature.assign( server_signature, server_signature_len ); }
        const std::string& get_server_signature() const { return server_signature; }

        bool operator==( const XCap& other ) const { return file_id == other.file_id && access_mode == other.access_mode && expires_s == other.expires_s && client_identity == other.client_identity && truncate_epoch == other.truncate_epoch && replicateOnClose == other.replicateOnClose && server_signature == other.server_signature; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( XCap, 2009090232 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeString( "file_id", 0, file_id ); marshaller.writeUint32( "access_mode", 0, access_mode ); marshaller.writeUint64( "expires_s", 0, expires_s ); marshaller.writeString( "client_identity", 0, client_identity ); marshaller.writeUint32( "truncate_epoch", 0, truncate_epoch ); marshaller.writeBoolean( "replicateOnClose", 0, replicateOnClose ); marshaller.writeString( "server_signature", 0, server_signature ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { unmarshaller.readString( "file_id", 0, file_id ); access_mode = unmarshaller.readUint32( "access_mode", 0 ); expires_s = unmarshaller.readUint64( "expires_s", 0 ); unmarshaller.readString( "client_identity", 0, client_identity ); truncate_epoch = unmarshaller.readUint32( "truncate_epoch", 0 ); replicateOnClose = unmarshaller.readBoolean( "replicateOnClose", 0 ); unmarshaller.readString( "server_signature", 0, server_signature ); }

      protected:
        std::string file_id;
        uint32_t access_mode;
        uint64_t expires_s;
        std::string client_identity;
        uint32_t truncate_epoch;
        bool replicateOnClose;
        std::string server_signature;
      };

      class XLocSet : public ::yidl::runtime::Struct
      {
      public:
        XLocSet() : version( 0 ), read_only_file_size( 0 ) { }
        XLocSet( const org::xtreemfs::interfaces::ReplicaSet& replicas, uint32_t version, const std::string& repUpdatePolicy, uint64_t read_only_file_size ) : replicas( replicas ), version( version ), repUpdatePolicy( repUpdatePolicy ), read_only_file_size( read_only_file_size ) { }
        XLocSet( const org::xtreemfs::interfaces::ReplicaSet& replicas, uint32_t version, const char* repUpdatePolicy, size_t repUpdatePolicy_len, uint64_t read_only_file_size ) : replicas( replicas ), version( version ), repUpdatePolicy( repUpdatePolicy, repUpdatePolicy_len ), read_only_file_size( read_only_file_size ) { }
        virtual ~XLocSet() { }

        void set_replicas( const org::xtreemfs::interfaces::ReplicaSet&  replicas ) { this->replicas = replicas; }
        const org::xtreemfs::interfaces::ReplicaSet& get_replicas() const { return replicas; }
        void set_version( uint32_t version ) { this->version = version; }
        uint32_t get_version() const { return version; }
        void set_repUpdatePolicy( const std::string& repUpdatePolicy ) { set_repUpdatePolicy( repUpdatePolicy.c_str(), repUpdatePolicy.size() ); }
        void set_repUpdatePolicy( const char* repUpdatePolicy, size_t repUpdatePolicy_len ) { this->repUpdatePolicy.assign( repUpdatePolicy, repUpdatePolicy_len ); }
        const std::string& get_repUpdatePolicy() const { return repUpdatePolicy; }
        void set_read_only_file_size( uint64_t read_only_file_size ) { this->read_only_file_size = read_only_file_size; }
        uint64_t get_read_only_file_size() const { return read_only_file_size; }

        bool operator==( const XLocSet& other ) const { return replicas == other.replicas && version == other.version && repUpdatePolicy == other.repUpdatePolicy && read_only_file_size == other.read_only_file_size; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( XLocSet, 2009090233 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeSequence( "replicas", 0, replicas ); marshaller.writeUint32( "version", 0, version ); marshaller.writeString( "repUpdatePolicy", 0, repUpdatePolicy ); marshaller.writeUint64( "read_only_file_size", 0, read_only_file_size ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { unmarshaller.readSequence( "replicas", 0, replicas ); version = unmarshaller.readUint32( "version", 0 ); unmarshaller.readString( "repUpdatePolicy", 0, repUpdatePolicy ); read_only_file_size = unmarshaller.readUint64( "read_only_file_size", 0 ); }

      protected:
        org::xtreemfs::interfaces::ReplicaSet replicas;
        uint32_t version;
        std::string repUpdatePolicy;
        uint64_t read_only_file_size;
      };

      class FileCredentials : public ::yidl::runtime::Struct
      {
      public:
        FileCredentials() { }
        FileCredentials( const org::xtreemfs::interfaces::XLocSet& xlocs, const org::xtreemfs::interfaces::XCap& xcap ) : xlocs( xlocs ), xcap( xcap ) { }
        virtual ~FileCredentials() { }

        void set_xlocs( const org::xtreemfs::interfaces::XLocSet&  xlocs ) { this->xlocs = xlocs; }
        const org::xtreemfs::interfaces::XLocSet& get_xlocs() const { return xlocs; }
        void set_xcap( const org::xtreemfs::interfaces::XCap&  xcap ) { this->xcap = xcap; }
        const org::xtreemfs::interfaces::XCap& get_xcap() const { return xcap; }

        bool operator==( const FileCredentials& other ) const { return xlocs == other.xlocs && xcap == other.xcap; }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( FileCredentials, 2009090234 );

        // yidl::Struct
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { marshaller.writeStruct( "xlocs", 0, xlocs ); marshaller.writeStruct( "xcap", 0, xcap ); }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { unmarshaller.readStruct( "xlocs", 0, xlocs ); unmarshaller.readStruct( "xcap", 0, xcap ); }

      protected:
        org::xtreemfs::interfaces::XLocSet xlocs;
        org::xtreemfs::interfaces::XCap xcap;
      };

      class FileCredentialsSet : public ::yidl::runtime::Sequence, public std::vector<org::xtreemfs::interfaces::FileCredentials>
      {
      public:
        FileCredentialsSet() { }
        FileCredentialsSet( const org::xtreemfs::interfaces::FileCredentials& first_value ) { std::vector<org::xtreemfs::interfaces::FileCredentials>::push_back( first_value ); }
        FileCredentialsSet( size_type size ) : std::vector<org::xtreemfs::interfaces::FileCredentials>( size ) { }
        virtual ~FileCredentialsSet() { }

        // yidl::runtime::Object
        YIDL_RUNTIME_OBJECT_PROTOTYPES( FileCredentialsSet, 2009090235 );

        // yidl::Sequence
        size_t get_size() const { return size(); }
        void marshal( ::yidl::runtime::Marshaller& marshaller ) const { size_type value_i_max = size(); for ( size_type value_i = 0; value_i < value_i_max; value_i++ ) { marshaller.writeStruct( "value", 0, ( *this )[value_i] ); } }
        void unmarshal( ::yidl::runtime::Unmarshaller& unmarshaller ) { org::xtreemfs::interfaces::FileCredentials value; unmarshaller.readStruct( "value", 0, value ); push_back( value ); }
      };



    };



  };



};
#endif
