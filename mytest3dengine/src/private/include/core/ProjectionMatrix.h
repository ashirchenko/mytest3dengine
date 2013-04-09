#ifndef ProjectionMatrix_h_
#define ProjectionMatrix_h_

#include <d3d9.h>
#include <d3dx9.h>

namespace Core
{
    class ProjectionMatrix
    {
    public:

        ProjectionMatrix();

        void setDevice( IDirect3DDevice9* device );
        void apply();

        void perspective( unsigned int width, unsigned int height, float viewField, float nearZ, float farZ );
        void ortohonal( unsigned int width, unsigned int height, float nearZ, float farZ );

    private:

        D3DXMATRIX matrix;
        IDirect3DDevice9* device;
    };
}

#endif
