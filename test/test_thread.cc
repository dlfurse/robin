#include "thread.hh"
#include "message.hh"

#include <chrono>
using std::chrono::system_clock;

#include <random>
using std::mt19937;
using std::uniform_real_distribution;

#include <cmath>
#include <unistd.h>

message_declare( sleepmsg )
message_define( sleepmsg, sleep, sleep )

namespace robin
{
    namespace test
    {
        class sleeper
        {
            public:
                sleeper( const size_t& p_seed ) :
                            f_seed( p_seed ),
                            f_engine( system_clock::now().time_since_epoch().count() ),
                            f_distribution( 250000., 750000. )
                {
                }
                ~sleeper()
                {
                }

                void start()
                {
                    size_t t_time;
                    while( true )
                    {
                        t_time = (useconds_t) (round( f_distribution( f_engine ) ));
                        sleepmsg( s_normal ) << "<" << f_seed << "> says: yawn! just let me sleep for <" << t_time << "> more microseconds..." << eom;
                        usleep( t_time );
                    }

                    return;
                }
                void stop()
                {
                    sleepmsg( s_warning ) << "<" << f_seed << "> says: how rude! fine, fine, i'll get up..." << eom;
                    return;
                }

            private:
                size_t f_seed;
                mt19937 f_engine;
                uniform_real_distribution< double_t > f_distribution;
        };
    }
}

using namespace robin;
using namespace robin::test;

int main()
{
    sleeper t_sleeper_one( 51385 );
    thread t_thread_one;
    t_thread_one.start( &t_sleeper_one, &sleeper::start );
    t_thread_one.stop( &t_sleeper_one, &sleeper::stop );

    sleeper t_sleeper_two( 112383 );
    thread t_thread_two;
    t_thread_two.start( &t_sleeper_two, &sleeper::start );
    t_thread_two.stop( &t_sleeper_two, &sleeper::stop );

    sleeper t_sleeper_three( 31387 );
    thread t_thread_three;
    t_thread_three.start( &t_sleeper_three, &sleeper::start );
    t_thread_three.stop( &t_sleeper_three, &sleeper::stop );

    sleepmsg( s_normal ) << "<master> says: starting sleepers..." << eom;

    t_thread_one.start();
    t_thread_two.start();
    t_thread_three.start();

    sleepmsg << "<master> says: you guys have five seconds..." << eom;
    usleep( 5000000 );

    sleepmsg << "<master> says: get up!" << eom;
    t_thread_one.stop();
    t_thread_two.stop();
    t_thread_three.stop();

    usleep( 1000000 );

    return 0;
}

