#ifndef Point2d_h_
#define Point2d_h_

namespace support
{
    struct Point2d
    {
    public:

        Point2d ( void )
        : x ( 0 ),
          y ( 0 )
        {

        }
        Point2d ( int aX, int aY )
        : x( aX ),
          y( aY )
        {

        }

        int x;
        int y;
    };
}

#endif
