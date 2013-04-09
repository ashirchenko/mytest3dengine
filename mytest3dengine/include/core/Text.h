#ifndef Text_h_
#define Text_h_

#include <string>

#include <IRenderable.h>
#include <IPositioned2d.h>

class IDirect3DDevice9;
class ID3DXFont;

namespace Core
{
    class Text : public ISpace::IRenderable,
                 public ISpace::IPositioned2d
    {
    public:
        static Text* newText( const std::string& name, IDirect3DDevice9* device );

    public:
        virtual ~Text();

        void setHeight( int );
        void setWidth( unsigned int );
        int getHeight() const;
        unsigned int getWidth() const;
        void setItalic( bool );
        bool getItalic() const;
        void setUnderline( bool );
        bool getUnderline() const;
        void setFontFamily( const std::string& );
        std::string getFontFamily() const;
        void setText( const std::string& );
        std::string getText() const;
        void setColor( unsigned char r, unsigned char g, unsigned char b );
        void getColor( unsigned char& r, unsigned char& g, unsigned char& b );

        virtual void render();

    private:

        Text();
        void init( IDirect3DDevice9* device );

    private:

        unsigned char colorR;
        unsigned char colorG;
        unsigned char colorB;

        ID3DXFont* font;
        std::string text;
	};
}


#endif
