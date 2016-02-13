#ifndef _robin_value_hh_
#define _robin_value_hh_

#include "error.hh"

#include <string>
using std::string;

namespace robin
{

    class value
    {
        private:

        public:
            value();
            virtual ~value();
            virtual value* clone() const = 0;

        public:
            template< class x_type >
            x_type* as();

            template< class x_type >
            const x_type* as() const;

            template< class x_type >
            bool is() const;

        protected:
            template< class x_type >
            void set( x_type* p_type );

        private:
            class holder
            {
                public:
                    holder();
                    virtual ~holder();

                public:
                    virtual void open() const = 0;
            };

            template< class x_type >
            class _holder :
                public holder
            {
                public:
                    _holder( x_type* p_type );
                    virtual ~_holder();

                public:
                    void open() const;

                private:
                    x_type* f_type;
            };

            holder* f_holder;
    };

    inline value::holder::holder()
    {
    }
    inline value::holder::~holder()
    {
    }

    template< class x_type >
    inline value::_holder< x_type >::_holder( x_type* p_type ) :
            holder(),
            f_type( p_type )
    {
    }
    template< class x_type >
    inline value::_holder< x_type >::~_holder()
    {
    }
    template< class x_type >
    inline void value::_holder< x_type >::open() const
    {
        throw f_type;
    }

    template< class x_type >
    inline x_type* value::as()
    {
        if( f_holder != NULL )
        {
            try
            {
                f_holder->open();
            }
            catch( x_type* t_type )
            {
                return t_type;
            }
            catch( ... )
            {
            }
        }

        throw error() << "cannot resolve value to type <" << typeid(x_type).name() << ">";
        return NULL;
    }

    template< class x_type >
    inline const x_type* value::as() const
    {
        if( f_holder != NULL )
        {
            try
            {
                f_holder->open();
            }
            catch( x_type* t_type )
            {
                return t_type;
            }
            catch( ... )
            {
            }
        }

        throw error() << "cannot resolve value to type <" << typeid(x_type).name() << ">";
        return NULL;
    }

    template< class x_type >
    inline bool value::is() const
    {
        if( f_holder != NULL )
        {

            try
            {
                f_holder->open();
            }
            catch( x_type* )
            {
                return true;
            }
            catch( ... )
            {
            }
        }
        return false;
    }

    template< class x_type >
    inline void value::set( x_type* p_type )
    {
        delete f_holder;
        f_holder = new _holder< x_type >( p_type );
        return;
    }

}

#endif
