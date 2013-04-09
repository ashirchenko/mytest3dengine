#ifndef Point3d_h_
#define Point3d_h_

namespace support
{
    struct Point3d
    {
    public:

        Point3d ( void )
        : x ( 0 ),
          y ( 0 ),
          z ( 0 )
        {

        }
        Point3d ( int aX, int aY, int aZ )
        : x( aX ),
          y( aY ),
          z( aZ )
        {

        }

        int x;
        int y;
        int z;
    };
}

#endif
