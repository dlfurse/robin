#ifndef _robin_typeint_hh_
#define _robin_typeint_hh_

namespace robin
{

    template< int x_result >
    class typeint
    {
        public:
            enum
            {
                result = x_result
            };
    };

}

#endif
