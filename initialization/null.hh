#ifndef _robin_null_hh_
#define _robin_null_hh_

#include "value.hh"

namespace robin
{

    class null :
        public value
    {
        public:
            null();
            virtual ~null();
            null* clone() const;
    };
}

#endif
