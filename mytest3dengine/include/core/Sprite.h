#ifndef Sprite_h_
#define Sprite_h_

#include "../interfaces/IRenderable.h"
#include <IPositioned2d.h>

#include <Rect.h>

class IDirect3DDevice9;
class IDirect3DVertexBuffer9;
class IDirect3DTexture9;

namespace ISpace
{
    class ISpriteListener;
}

namespace Core
{
    class Sprite : public ISpace::IRenderable,
                   public ISpace::IPositioned2d
    {
    public:
        static Sprite* newSprite( const std::string& name, IDirect3DDevice9* device );

    public:

        virtual ~Sprite();

        virtual void render();

        void setListener( ISpace::ISpriteListener* listener );
        void setWidht( unsigned int width );
        void setHeight( unsigned int height );
        unsigned int getWidth() const;
        unsigned int getHeight() const;

        support::Rect getBoundRect() const;

        void click();
        void over();

    private:

        Sprite();
        void init( IDirect3DDevice9* device );

        IDirect3DDevice9* device;
        IDirect3DVertexBuffer9* buffer;
        IDirect3DTexture9* texture;
        ISpace::ISpriteListener* listener;

        unsigned int width;
        unsigned int height;
    };
}

#endif
