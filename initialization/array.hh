#ifndef _robin_array_hh_
#define _robin_array_hh_

#include "value.hh"

#include <vector>
using std::vector;

namespace robin
{

    class array :
        public value
    {
        public:
            array();
            virtual ~array();
            array* clone() const;

        public:
            size_t size() const;
            void add( value* p_value );

            value* at( const size_t& p_index );
            const value* at( const size_t& p_index ) const;

        private:
            typedef vector< value* > vector_t;
            typedef vector_t::iterator vector_it_t;
            typedef vector_t::const_iterator vector_cit_t;
            typedef vector_t::value_type vector_entry_t;

            vector_t f_vector;
    };

}

#endif
