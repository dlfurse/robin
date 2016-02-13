#ifndef _robin_numerical_builder_hh_
#define _robin_numerical_builder_hh_

#include "value.hh"
#include "numerical.hh"
#include "typelist.hh"

#include <map>
using std::map;

namespace robin
{

    template< class x_type = _ >
    class numerical_builder
    {
        public:
            numerical_builder()
            {
                f_type = new x_type();
            }
            virtual ~numerical_builder()
            {
                delete f_type;
            }

        public:
            void operator()( value* p_value )
            {
                if( p_value->is< ::robin::numerical >() == true )
                {
                    operator()( p_value->as< ::robin::numerical >() );
                }
                else
                {
                    throw error() << "numerical builder for <" << typeid(x_type).name() << "> received unknown value type";
                }
                return;
            }
            void operator()( ::robin::numerical* p_numerical )
            {
                stringstream t_stream;
                (void) (t_stream << p_numerical->str());
                (void) (t_stream >> (*f_type));
                return;
            }

            x_type* operator()()
            {
                return f_type;
            }

        private:
            x_type* f_type;
    };

    template< >
    class numerical_builder< _ >
    {
        public:
            typedef typelist_10( unsigned char, char, unsigned short, short, unsigned int, int, unsigned long, long, float, double ) types;
    };

}

#endif
