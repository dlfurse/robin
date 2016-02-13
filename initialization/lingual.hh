#ifndef _robin_lingual_hh_
#define _robin_lingual_hh_

#include "value.hh"

namespace robin
{

    class lingual :
        public value
    {
        public:
            lingual( const string& p_value );
            virtual ~lingual();
            lingual* clone() const;

        public:
            size_t size() const;
            const value* at( const string& p_key ) const;
            const value* at( const size_t& p_index ) const;

        public:
            string& str();
            const string& str() const;

        private:
            string f_string;
    };
}

#endif
