#ifndef IPositioned3d_h_
#define IPositioned3d_h_

#include <Point3d.h>

namespace ISpace
{
    class IPositioned3d
    {
    public:
        void setPos( const support::Point3d& pos )
        {
            point = pos;
        }

        const support::Point3d& getPos() const
        {
            return point;
        }

    protected:
        IPositioned3d() { }
        virtual ~IPositioned3d() { }

    private:
        support::Point3d point;
    };
}

#endif
