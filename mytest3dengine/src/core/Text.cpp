#include <Text.h>

#include <stdlib.h>

#include <d3d9.h>
#include <d3dx9.h>

#include <assert.h>

#include <Point2d.h>

namespace Core
{
    Text* Text::newText( const std::string& name, IDirect3DDevice9* device )
    {
        if ( !device || name.empty() )
            return NULL;

        Text* t = new Text;
        t->init( device );

        t->setName( name );
        t->setType( "Core::Text" );

        return  t;
    }

    Text::Text()
      : colorR( 0 ),
        colorG( 0 ),
        colorB( 0 )
    {

    }

    void Text::init( IDirect3DDevice9* device )
    {
        LOGFONT lf;
        ZeroMemory( &lf, sizeof( LOGFONT ) );

        lf.lfHeight         = 30;
        lf.lfWidth          = 20;
        lf.lfEscapement     = 0;
        lf.lfOrientation    = 0;
        lf.lfWeight         = 500;
        lf.lfItalic         = false;
        lf.lfUnderline      = false;
        lf.lfStrikeOut      = false;
        lf.lfCharSet        = DEFAULT_CHARSET;
        lf.lfOutPrecision   = 0;
        lf.lfClipPrecision  = 0;
        lf.lfQuality        = 0;
        lf.lfPitchAndFamily = 0;
        strcpy( lf.lfFaceName, "Arial" );

        D3DXCreateFontIndirect( device, (D3DXFONT_DESC*)&lf, &font );
    }

    Text::~Text(void)
    {
        if ( font )
            font->Release();
    }

    void Text::setHeight( int height )
    {
        D3DXFONT_DESC* desc;
        font->GetDesc( desc );

        desc->Height = height;
    }

    void Text::setWidth( unsigned int width )
    {
        D3DXFONT_DESC* desc;
        font->GetDesc( desc );

        desc->Width = width;
    }

    int Text::getHeight() const
    {
        D3DXFONT_DESC* desc;
        font->GetDesc( desc );

        return desc->Height;
    }

    unsigned int Text::getWidth() const
    {
        D3DXFONT_DESC* desc;
        font->GetDesc( desc );

        return desc->Width;
    }

    void Text::setItalic( bool italic )
    {
        D3DXFONT_DESC* desc;
        font->GetDesc( desc );

        desc->Italic = italic;
    }

    bool Text::getItalic() const
    {
        D3DXFONT_DESC* desc;
        font->GetDesc( desc );

        return desc->Italic;
    }

    void Text::setUnderline( bool )
    {
        // TODO
    }

    bool Text::getUnderline() const
    {
        return false; // TODO
    }

    void Text::setFontFamily( const std::string& )
    {
        // TODO
    }

    std::string Text::getFontFamily() const
    {
        return std::string();
    }

    void Text::setText( const std::string& atext )
    {
        text = atext;
    }

    std::string Text::getText() const
    {
        return text;
    }

    void Text::setColor( unsigned char r, unsigned char g, unsigned char b )
    {
        colorR = r;
        colorG = g;
        colorB = b;
    }

    void Text::getColor( unsigned char& r, unsigned char& g, unsigned char& b )
    {
        r = colorR;
        g = colorG;
        b = colorB;
    }

    void Text::render()
    {
        assert( font != NULL );
        const support::Point2d& pos = getPos();

        RECT r = { pos.x, pos.y, 0, 0 };
        font->DrawText( 0, text.c_str(), -1, &r, DT_NOCLIP, D3DCOLOR_XRGB( colorR, colorG, colorB ) );
    }

}
