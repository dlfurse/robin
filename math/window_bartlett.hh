#ifndef _robin_window_bartlett_hh_
#define _robin_window_bartlett_hh_

#include "window.hh"

namespace robin
{

    class window_bartlett :
        public window
    {
        public:
            window_bartlett();
            virtual ~window_bartlett();

        protected:
            void fill( const count_t& p_size, real_t*& p_raw );
    };
}

#endif
