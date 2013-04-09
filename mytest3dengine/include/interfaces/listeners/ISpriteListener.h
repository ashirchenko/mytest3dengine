#ifndef ISpriteListener_h_
#define ISpriteListener_h_

namespace ISpace
{
    class ISpriteListener
    {
    public:

        virtual ~ISpriteListener() { }
        virtual void onClick() = 0;
        virtual void onOver() = 0;

    };
}

#endif
