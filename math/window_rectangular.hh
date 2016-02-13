#ifndef _robin_window_rectangular_hh_
#define _robin_window_rectangular_hh_

#include "window.hh"

namespace robin
{

    class window_rectangular :
        public window
    {
        public:
            window_rectangular();
            virtual ~window_rectangular();

        protected:
            void fill( const count_t& p_size, real_t*& p_raw );
    };
}

#endif
