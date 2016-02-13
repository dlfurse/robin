#ifndef _robin_object_builder_hh_
#define _robin_object_builder_hh_

#include "value.hh"
#include "object.hh"
#include "array.hh"
#include "typelist.hh"
#include "typein.hh"
#include "typeif.hh"

#include "lingual_builder.hh"
#include "numerical_builder.hh"
#include "boolean_builder.hh"
#include "null_builder.hh"

#include <map>
using std::map;

namespace robin
{

    template< class x_type >
    class object_builder
    {
        public:
            object_builder()
            {
                if( f_entries == NULL )
                {
                    f_entries = new map_t();
                }

                f_type = new x_type();
            }
            virtual ~object_builder()
            {
                delete f_type;
            }

        public:
            void operator()( value* p_value )
            {
                if( p_value->is< ::robin::object >() == true )
                {
                    operator()( p_value->as< ::robin::object >() );
                }
                else
                {
                    throw error() << "object builder for <" << typeid(x_type).name() << "> received unknown value type";
                }
                return;
            }
            void operator()( ::robin::object* p_object )
            {
                pair< string, value* > t_pair;
                size_t t_obj_index;
                size_t t_arr_index;
                string t_label;
                value* t_value;
                array* t_array;

                map_it_t t_it;

                for( t_obj_index = 0; t_obj_index < p_object->size(); t_obj_index++ )
                {
                    t_pair = p_object->at( t_obj_index );
                    t_label = t_pair.first;
                    t_value = t_pair.second;

                    t_it = f_entries->find( t_label );

                    if( t_it != f_entries->end() )
                    {
                        if( t_value->is< ::robin::array >() )
                        {
                            t_array = t_value->as< ::robin::array >();
                            for( t_arr_index = 0; t_arr_index < t_array->size(); t_arr_index++ )
                            {
                                t_it->second->bind( f_type, t_array->at( t_arr_index ) );
                            }
                        }
                        else
                        {
                            t_it->second->bind( f_type, t_value );
                        }
                    }
                    else
                    {
                        throw error() << "object builder for <" << typeid(x_type).name() << "> has no entry for label <" << t_label << ">";
                    }
                }
            }

            x_type* operator()()
            {
                x_type* t_type = f_type;
                f_type = NULL;
                return t_type;
            }

        private:
            x_type* f_type;

        public:
            template< class x_child, class x_target, class x_argument >
            static int field( void (x_target::*p_member)( x_argument ), const string& p_label )
            {
                if( f_entries == NULL )
                {
                    f_entries = new map< string, entry* >();
                }

                typedef typename typeif< typein< typename null_builder< >::types, x_child >::result, null_builder< x_child >, typename typeif< typein< typename boolean_builder< >::types, x_child >::result, boolean_builder< x_child >, typename typeif< typein< typename numerical_builder< >::types, x_child >::result, numerical_builder< x_child >, typename typeif< typein< typename lingual_builder< >::types, x_child >::result, lingual_builder< x_child >, object_builder< x_child > >::result >::result >::result >::result builder_t;

                map_it_t t_it = f_entries->find( p_label );
                if( t_it == f_entries->end() )
                {
                    f_entries->insert( map_entry_t( p_label, new member< builder_t, void (x_target::*)( x_argument ) >( p_member ) ) );
                }
                else
                {
                    throw error() << "object builder for <" << typeid(x_type).name() << "> already has entry for label <" << p_label << ">";
                }

                return 0;
            }

        private:
            class entry
            {
                public:
                    entry()
                    {
                    }
                    virtual ~entry()
                    {
                    }

                public:
                    virtual void bind( x_type* p_type, value* p_value ) = 0;
            };

            template< class x_builder, class x_member >
            class member;

            template< class x_builder, class x_target, class x_argument >
            class member< x_builder, void (x_target::*)( x_argument ) > :
                public entry
            {
                public:
                    member( void (x_target::*p_member)( x_argument ) ) :
                                f_member( p_member )
                    {
                    }
                    virtual ~member()
                    {
                    }

                public:
                    void bind( x_type* p_type, value* p_value )
                    {
                        x_builder t_builder;
                        t_builder( p_value );
                        (p_type->*f_member)( *(t_builder()) );
                        return;
                    }

                private:
                    void (x_target::*f_member)( x_argument );
            };

            template< class x_builder, class x_target, class x_argument >
            class member< x_builder, void (x_target::*)( x_argument* ) > :
                public entry
            {
                public:
                    member( void (x_target::*p_member)( x_argument* ) ) :
                                f_member( p_member )
                    {
                    }
                    virtual ~member()
                    {
                    }

                public:
                    void bind( x_type* p_type, value* p_value )
                    {
                        x_builder t_builder;
                        t_builder( p_value );
                        (p_type->*f_member)( t_builder() );
                        return;
                    }

                private:
                    void (x_target::*f_member)( x_argument* );
            };

            typedef map< string, entry* > map_t;
            typedef typename map_t::iterator map_it_t;
            typedef typename map_t::const_iterator map_cit_t;
            typedef typename map_t::value_type map_entry_t;

            static map_t* f_entries;
    };

    template< class x_type >
    typename object_builder< x_type >::map_t* object_builder< x_type >::f_entries = NULL;

}

#endif
