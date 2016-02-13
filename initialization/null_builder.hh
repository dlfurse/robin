#ifndef _robin_null_builder_hh_
#define _robin_null_builder_hh_

#include "value.hh"
#include "null.hh"
#include "typelist.hh"

#include <map>
using std::map;

namespace robin
{

    template< class x_type = _ >
    class null_builder
    {
        public:
            null_builder()
            {
                f_type = new x_type();
            }
            virtual ~null_builder()
            {
                delete f_type;
            }

        public:
            void operator()( value* p_value )
            {
                if( p_value->is< ::robin::null >() == true )
                {
                    operator()( p_value->as< ::robin::null >() );
                }
                else
                {
                    throw error() << "null builder for <" << typeid(x_type).name() << "> received unknown value type";
                }
                return;
            }
            void operator()( ::robin::null* )
            {
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
    class null_builder< _ >
    {
        public:
            typedef typelist_1( void ) types;
    };

}

#endif
