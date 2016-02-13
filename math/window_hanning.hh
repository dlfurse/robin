#ifndef _robin_window_hanning_hh_
#define _robin_window_hanning_hh_

#include "window.hh"

namespace robin
{

    class window_hanning :
        public window
    {
        public:
            window_hanning();
            virtual ~window_hanning();

        protected:
            void fill( const count_t& p_size, real_t*& p_raw );
    };
}

#endif
