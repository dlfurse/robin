#ifndef _robin_bindable_hh_
#define _robin_bindable_hh_

#include <cstddef>

namespace robin
{

    template< class x_sender, class x_receiver >
    class sender;

    template< class x_sender, class x_receiver >
    class receiver;

    template< class x_sender, class x_receiver >
    class sender
    {
        public:
            friend class receiver< x_sender, x_receiver > ;

        public:
            sender() :
                f_receiver( NULL )
            {
            }
            virtual ~sender()
            {

            }

        public:
            void bind( x_receiver* p_receiver );
            void unbind();

        protected:
            x_receiver* f_receiver;
    };

    template< class x_sender, class x_receiver >
    class receiver
    {
        public:
            friend class sender< x_sender, x_receiver > ;

        public:
            receiver() :
                f_sender( NULL )
            {
            }
            virtual ~receiver()
            {
            }

        public:
            void bind( x_sender* p_sender );
            void unbind();

        protected:
            x_sender* f_sender;
    };

    template< class x_sender, class x_receiver >
    void sender< x_sender, x_receiver >::bind( x_receiver* p_receiver )
    {
        this->sender< x_sender, x_receiver >::unbind();
        p_receiver->receiver< x_sender, x_receiver >::unbind();

        this->sender< x_sender, x_receiver >::f_receiver = p_receiver;
        p_receiver->receiver< x_sender, x_receiver >::f_sender = this;

        return;
    }

    template< class x_sender, class x_receiver >
    void sender< x_sender, x_receiver >::unbind()
    {
        if( this->sender< x_sender, x_receiver >::f_receiver != NULL )
        {
            this->sender< x_sender, x_receiver >::f_receiver->receiver< x_receiver, x_sender >::f_sender = NULL;
            this->sender< x_sender, x_receiver >::f_receiver = NULL;
        }
        return;
    }


    template< class x_sender, class x_receiver >
    void receiver< x_sender, x_receiver >::bind( x_sender* p_sender )
    {
        this->receiver< x_sender, x_receiver >::unbind();
        p_sender->sender< x_sender, x_receiver >::unbind();

        this->receiver< x_sender, x_receiver >::f_sender = p_sender;
        p_sender->sender< x_sender, x_receiver >::f_receiver = this;

        return;
    }

    template< class x_sender, class x_receiver >
    void receiver< x_sender, x_receiver >::unbind()
    {
        if( this->receiver< x_sender, x_receiver >::f_sender != NULL )
        {
            this->receiver< x_sender, x_receiver >::f_sender->sender< x_receiver, x_sender >::f_receiver = NULL;
            this->receiver< x_sender, x_receiver >::f_sender = NULL;
        }
        return;
    }

}

#endif
