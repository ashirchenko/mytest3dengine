#ifndef IPositioned2de_h_
#define IPositioned2de_h_

#include <Point2d.h>

namespace ISpace
{
    class IPositioned2d
    {
    public:
        void setPos( const support::Point2d& pos )
        {
            point = pos;
        }

        const support::Point2d& getPos() const
        {
            return point;
        }

    protected:
        IPositioned2d() { }
        virtual ~IPositioned2d() { }

    private:
        support::Point2d point;
    };
}

#endif
