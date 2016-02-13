#ifndef _robin_frame_hh_
#define _robin_frame_hh_

#include <cstdint>

namespace robin
{

    class frame
    {
        protected:
            frame();
            frame( uint32_t p_length, uint32_t p_type, uint32_t p_flags, uint32_t p_stream );

        public:
            virtual ~frame();

        public:
            const uint32_t& length() const
            {
                return f_length;
            }

            const uint32_t& type() const
            {
                return f_type;
            }

            const uint32_t& flags() const
            {
                return f_flags;
            }

            const uint32_t& stream() const
            {
                return f_stream;
            }

            uint8_t* data()
            {
                return f_data;
            }
            const uint8_t* data() const
            {
                return f_data;
            }

        private:
            enum
            {
                e_frame_size = 32768,
                e_data_size = e_frame_size - 4 * sizeof(uint32_t) - 2 * sizeof(uint8_t*)
            };

            template< class x_type >
            int32_t write( const x_type& p_object )
            {
                memcpy( f_write_ptr, &p_object, sizeof(x_type) );
                f_write_ptr += sizeof(x_type);
                return;
            }

            template< class x_type >
            int32_t write( const x_type* p_object, int32_t p_length )
            {
                int32_t t_size = p_length * sizeof(x_type);
                memcpy( f_write_ptr, &p_object, t_size );
                f_write_ptr += t_size;
                return;
            }

            uint32_t f_length;
            uint32_t f_type;
            uint32_t f_flags;
            uint32_t f_stream;
            uint8_t* f_read_ptr;
            uint8_t* f_write_ptr;
            uint8_t f_data[e_data_size];
    };

}

#endif
