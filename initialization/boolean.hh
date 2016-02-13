#ifndef _robin_boolean_hh_
#define _robin_boolean_hh_

#include "value.hh"

namespace robin
{

    class boolean :
        public value
    {
        public:
            boolean( const string& p_string );
            virtual ~boolean();
            boolean* clone() const;

        public:
            string& str();
            const string& str() const;

            bool& get();
            const bool& get() const;

        private:
            string f_string;
            bool f_value;
    };
}

#endif
