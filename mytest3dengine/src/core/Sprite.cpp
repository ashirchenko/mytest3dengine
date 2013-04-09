#include <Sprite.h>

#include "../../include/interfaces/listeners/ISpriteListener.h"
#include <Vertex3PNT.h>
#include <Point2d.h>

namespace Core
{
    Sprite* Sprite::newSprite( const std::string& name, IDirect3DDevice9* device )
    {
        if ( name.empty() || !device )
            return NULL;

        Sprite* s = new Sprite;

        s->init( device );
        s->setName( name );
        s->setType( "Core::Sprite" );

        return s;
    }

    void Sprite::init( IDirect3DDevice9* device )
    {
        this->device = device;
    }

    Sprite::Sprite()
        : device( NULL ),
          buffer( NULL ),
          texture( NULL ),
          listener( NULL ),
          width( 0 ),
          height( 0 )
    {

    }

    Sprite::~Sprite()
    {

    }

    void Sprite::render()
    {
        D3DXMATRIX matScale, matWorld;

        D3DVIEWPORT9* vp = new D3DVIEWPORT9;
        device->GetViewport( vp );

        D3DXMatrixScaling( &matScale, width, height, 0 );

        const support::Point2d& pos = getPos();

        float xTranslation = (float)( - ( vp->Width / 2.0f ) ) + pos.x ;
        float yTranslation = (float)( ( vp->Height / 2.0f ) ) - pos.y - height;

        D3DXMatrixTranslation( &matWorld, xTranslation, yTranslation, 0.1f );
        device->SetTransform( D3DTS_WORLD, &( matScale * matWorld ) );

        device->SetStreamSource( 0, buffer, 0, sizeof( utils_private::Vertex3PNT ) );
        device->SetVertexDeclaration( utils_private::Vertex3PNT::declaration );
        device->SetTexture( 0, texture );
        device->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 2 );

        device->SetTexture( 0, NULL );
    }

    void Sprite::setListener( ISpace::ISpriteListener* listener )
    {
        this->listener = listener;
    }

    void Sprite::setWidht( unsigned int width )
    {
        this->width = width;
    }

    void Sprite::setHeight( unsigned int height )
    {
        this->height = height;
    }

    unsigned int Sprite::getWidth() const
    {
        return width;
    }

    unsigned int Sprite::getHeight() const
    {
        return height;
    }

    support::Rect Sprite::getBoundRect() const
    {
        const support::Point2d& pos = getPos();
        return support::Rect( pos.x, pos.y, pos.x + width, pos.y + height );
    }

    void Sprite::click()
    {
        listener->onClick();
    }

    void Sprite::over()
    {
        listener->onOver();
    }
}
