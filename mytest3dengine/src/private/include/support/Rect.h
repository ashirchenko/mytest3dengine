#ifndef Rect_h_
#define Rect_h_

namespace support
{

    class Rect
    {
    public:

    Rect ( void )
    : left ( 0 ),
      right ( 0 ),
      top ( 0 ),
      bottom ( 0 )
    {

    }
    Rect ( int aLeft, int aTop, int aRight, int aBottom )
    : left ( aLeft ),
      right ( aRight ),
      top ( aTop ),
      bottom ( aBottom )
    {

    }

    int getLeft( void ) const;
    void setLeft(int val);
    int getRight( void ) const;
    void setRight(int val);
    int getTop( void ) const;
    void setTop(int val);
    int getBottom( void ) const;
    void setBottom(int val);

    int getWidth( void ) const;
    int getHeight( void ) const;

    private:

    int left;
    int right;
    int top;
    int bottom;
    };

    inline int Rect::getLeft() const { return left; }
    inline void Rect::setLeft(int val) { left = val; }
    inline int Rect::getRight() const { return right; }
    inline void Rect::setRight(int val) { right = val; }
    inline int Rect::getTop() const { return top; }
    inline void Rect::setTop(int val) { top = val; }
    inline int Rect::getBottom() const { return bottom; }
    inline void Rect::setBottom(int val) { bottom = val; }
    inline int Rect::getWidth( void ) const { return right - left; }
    inline int Rect::getHeight( void ) const { return bottom - top; }

}

#endif
