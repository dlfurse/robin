#ifndef _robin_typeif_hh_
#define _robin_typeif_hh_

#include "typenode.hh"
#include "typenull.hh"

namespace robin
{

    template< bool x_condition, class x_then, class x_else >
    class typeif
    {
        public:
            typedef x_then result;
    };

    template< class x_then, class x_else >
    class typeif< false, x_then, x_else >
    {
        public:
            typedef x_else result;
    };

}

#endif
