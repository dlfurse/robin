#ifndef _robin_lingual_builder_hh_
#define _robin_lingual_builder_hh_

#include "value.hh"
#include "lingual.hh"
#include "typelist.hh"

#include <map>
using std::map;

namespace robin
{

    template< class x_type = _ >
    class lingual_builder
    {
        public:
            lingual_builder()
            {
                f_type = new x_type();
            }
            virtual ~lingual_builder()
            {
                delete f_type;
            }

        public:
            void operator()( value* p_value )
            {
                if( p_value->is< ::robin::lingual >() == true )
                {
                    operator()( p_value->as< ::robin::lingual >() );
                }
                else
                {
                    throw error() << "lingual builder for <" << typeid(x_type).name() << "> received unknown value type";
                }
                return;
            }
            void operator()( ::robin::lingual* p_lingual )
            {
                f_type->assign( p_lingual->str() );
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
    class lingual_builder< _ >
    {
        public:
            typedef typelist_1( string ) types;
    };

}

#endif
