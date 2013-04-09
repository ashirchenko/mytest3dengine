#ifndef Scene_h_
#define Scene_h_

#include "../interfaces/IRenderable.h"

namespace Core
{
    class Scene : public ISpace::IRenderable
    {
    public:

        static Scene* newScene( const std::string& name, IDirect3DDevice9* device );

    public:

        virtual ~Scene();

        virtual void render();

    private:

        Scene();
        void init( IDirect3DDevice9* device );

        IDirect3DDevice9* device;
    };
}

#endif
