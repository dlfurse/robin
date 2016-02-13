#ifndef _robin_window_blackman_hh_
#define _robin_window_blackman_hh_

#include "window.hh"

namespace robin
{

    class window_blackman :
        public window
    {
        public:
            window_blackman();
            virtual ~window_blackman();

        protected:
            void fill( const count_t& p_size, real_t*& p_raw );
    };
}

#endif
