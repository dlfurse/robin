#include "lingual.hh"

namespace robin
{

    lingual::lingual( const string& p_value ) :
            f_string( p_value )
    {
        set( this );
    }
    lingual::~lingual()
    {
    }
    lingual* lingual::clone() const
    {
        return (new lingual( f_string ));
    }

    size_t lingual::size() const
    {
        return 0;
    }
    const value* lingual::at( const string& ) const
    {
        throw error() << "lingual has no aggregated values";
        return this;
    }
    const value* lingual::at( const size_t& ) const
    {
        throw error() << "lingual has no aggregated values";
        return this;
    }

    string& lingual::str()
    {
        return f_string;
    }
    const string& lingual::str() const
    {
        return f_string;
    }

}
