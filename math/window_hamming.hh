#ifndef _robin_window_hamming_hh_
#define _robin_window_hamming_hh_

#include "window.hh"

namespace robin
{

    class window_hamming :
        public window
    {
        public:
            window_hamming();
            virtual ~window_hamming();

        protected:
            void fill( const count_t& p_size, real_t*& p_raw );
    };
}

#endif
