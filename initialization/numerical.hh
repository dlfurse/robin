#ifndef _robin_numerical_hh_
#define _robin_numerical_hh_

#include "value.hh"

namespace robin
{

    class numerical :
        public value
    {
        public:
            numerical( const string& p_string );
            virtual ~numerical();
            numerical* clone() const;

        public:
            string& str();
            const string& str() const;

            double& get();
            const double& get() const;

        private:
            string f_string;
            double f_value;
    };
}

#endif
