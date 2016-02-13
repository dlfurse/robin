#ifndef _robin_buffer_receiver_hh_
#define _robin_buffer_receiver_hh_

#include "bindable.hh"

#include <cstdint>

namespace robin
{

    class buffer_sender;

    class buffer_receiver :
        public receiver< buffer_sender, buffer_receiver >
    {
        public:
            buffer_receiver();
            virtual ~buffer_receiver();

        public:
            virtual void receive_buffer( size_t p_length, const uint8_t* p_data ) = 0;
    };

}

#endif
