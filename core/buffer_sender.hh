#ifndef _robin_buffer_sender_hh_
#define _robin_buffer_sender_hh_

#include "bindable.hh"

#include <cstdint>

namespace robin
{

    class buffer_receiver;

    class buffer_sender :
        public sender< buffer_sender, buffer_receiver >
    {
        public:
            buffer_sender();
            virtual ~buffer_sender();

        public:
            virtual void send_buffer( size_t p_length, uint8_t* p_data ) = 0;
    };

}

#endif
