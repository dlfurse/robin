#ifndef _robin_headers_frame_hh_
#define _robin_headers_frame_hh_

#include "frame.hh"

namespace robin
{

    class headers_frame :
        public frame
    {
        public:
            headers_frame( uint32_t p_length, uint32_t p_type, uint32_t p_flags, uint32_t p_stream );
            virtual ~headers_frame();

        public:
            void add_header( const uint8_t* p_name, size_t p_length, const uint8_t* p_value, size_t p_length )
            {

            }
            void get_header( uint8_t*& p_name, size_t& p_length, uint8_t*& p_value, size_t& p_length )
            {

            }

    };

}

#endif
