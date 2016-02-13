#ifndef _robin_frame_sender_hh_
#define _robin_frame_sender_hh_

#include "bindable.hh"

namespace robin
{

    class frame_receiver;

    class frame_sender :
        public sender< frame_sender, frame_receiver >
    {
        public:
            frame_sender();
            virtual ~frame_sender();

        public:
            void send_settings_frame();
            void send_window_frame();
            void send_header_frame();
            void send_data_frame();
            void send_push_frame();
            void send_ping_frame();
    };

}

#endif
