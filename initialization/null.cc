#include "null.hh"

namespace robin
{

    null::null()
    {
        set( this );
    }
    null::~null()
    {
    }
    null* null::clone() const
    {
        return (new null());
    }

}
