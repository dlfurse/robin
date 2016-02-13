#ifndef _robin_typenode_hh_
#define _robin_typenode_hh_

namespace robin
{

    template< class x_head, class x_tail >
    class typenode
    {
        public:
            typedef x_head head_t;
            typedef x_tail tail_t;
    };

}

#endif
