#ifndef _robin_alignment_hh_
#define _robin_alignment_hh_

namespace robin
{

    template< class x_type >
    class alignment
    {
        private:
            struct calculator
            {
                char f_char;
                x_type f_type;
            };

        public:
            enum
            {
                result = sizeof( calculator ) - sizeof( x_type )
            };
    };

}

#endif
