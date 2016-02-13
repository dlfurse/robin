#ifndef _robin_boolean_builder_hh_
#define _robin_boolean_builder_hh_

#include "value.hh"
#include "boolean.hh"
#include "typelist.hh"

#include <map>
using std::map;

namespace robin
{

    template< class x_type = _ >
    class boolean_builder
    {
        public:
            boolean_builder()
            {
                f_type = new x_type();
            }
            virtual ~boolean_builder()
            {
                delete f_type;
            }

        public:
            void operator()( value* p_value )
            {
                if( p_value->is< ::robin::boolean >() == true )
                {
                    operator()( p_value->as< ::robin::boolean >() );
                }
                else
                {
                    throw error() << "boolean builder for <" << typeid(x_type).name() << "> received unknown value type";
                }
                return;
            }
            void operator()( ::robin::boolean* p_boolean )
            {
                stringstream t_stream;
                (void) (t_stream << p_boolean->str());
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
    class boolean_builder< _ >
    {
        public:
            typedef typelist_1( bool ) types;
    };

}

#endif
