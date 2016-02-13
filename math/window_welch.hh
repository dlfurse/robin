#ifndef _robin_window_welch_hh_
#define _robin_window_welch_hh_

#include "window.hh"

namespace robin
{

    class window_welch :
        public window
    {
        public:
            window_welch();
            virtual ~window_welch();

        protected:
            void fill( const count_t& p_size, real_t*& p_raw );
    };
}

#endif
