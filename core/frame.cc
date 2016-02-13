#include "frame.hh"

#include <cstring>

namespace robin
{

    frame::frame() :
        f_length( 0 ),
        f_type( 0 ),
        f_flags( 0 ),
        f_stream( 0 ),
        f_read_ptr( f_data ),
        f_write_ptr( f_data )
    {
        memset( f_data, 0, e_data_size );
    }

    frame::frame( uint32_t p_length, uint32_t p_type, uint32_t p_flags, uint32_t p_stream ) :
        f_length( p_length ),
        f_type( p_type ),
        f_flags( p_flags ),
        f_stream( p_stream ),
        f_read_ptr( f_data ),
        f_write_ptr( f_data )
    {
        memset( f_data, 0, e_data_size );
    }

    frame::~frame()
    {
    }

}
