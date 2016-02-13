#ifndef _robin_reporter_hh_
#define _robin_reporter_hh_

#include "value.hh"
#include "processor.hh"

#include <stack>
using std::stack;

namespace robin
{

    class reporter :
        public processor
    {
        public:
            reporter();
            virtual ~reporter();

        public:
            void operator()( value* f_value );

        private:
            void dispatch( value* f_value );

        public:
            virtual void process_key( string p_string );
            virtual void process_lingual( string p_string );
            virtual void process_numerical( string p_string );
            virtual void process_boolean( string p_string );
            virtual void process_null();
            virtual void process_object_start();
            virtual void process_object_stop();
            virtual void process_array_start();
            virtual void process_array_stop();
            virtual void process_start();
            virtual void process_stop();

        private:
            class context
            {
                public:
                    context();
                    ~context();

                    string pad;
                    string key;
                    string comma;
            };

            stack< context > f_contexts;
    };
}

#endif
