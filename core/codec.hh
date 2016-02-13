#ifndef _robin_codec_hh_
#define _robin_codec_hh_

namespace robin
{

    class frame;

    class codec
    {
        public:
            class receiver
            {
                public:
                    receiver();
                    virtual ~receiver();

                public:
                    void on_frame( frame* );
            };
    };

}

#endif
