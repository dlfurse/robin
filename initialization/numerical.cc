#include "numerical.hh"

#include <sstream>
using std::stringstream;

namespace robin
{

    numerical::numerical( const string& p_string ) :
            f_string( p_string ),
            f_value( 0. )
    {
        set( this );

        stringstream t_stream;
        t_stream << f_string;
        t_stream >> f_value;
    }
    numerical::~numerical()
    {
    }
    numerical* numerical::clone() const
    {
        return (new numerical( f_string ));
    }

    string& numerical::str()
    {
        return f_string;
    }
    const string& numerical::str() const
    {
        return f_string;
    }

    double& numerical::get()
    {
        return f_value;
    }
    const double& numerical::get() const
    {
        return f_value;
    }

}
