#include <Scene.h>

namespace Core
{
    Scene* Scene::newScene( const std::string& name, IDirect3DDevice9* device )
    {
        if ( name.empty() || !device )
            return NULL;

        Scene* s = new Scene;

        s->init( device );
        s->setName( name );
        s->setType( "Core::Scene" );

        return s;
    }

    void Scene::init( IDirect3DDevice9* device )
    {
        this->device = device;
    }

    Scene::Scene()
    {

    }

    Scene::~Scene()
    {

    }

    void Scene::render()
    {

    }
}
