#ifndef ViewMatrix_h_
#define ViewMatrix_h_

#include <d3d9.h>
#include <d3dx9.h>

namespace Core
{
    class ViewMatrix
    {
    public:

        ViewMatrix();

        void setDevice( IDirect3DDevice9* device );
        void apply();

        void ortohonal();
        void perspective( const D3DXVECTOR3& pos, const D3DXVECTOR3& target, const D3DXVECTOR3& up );

    private:

        D3DXMATRIX matrix;
        IDirect3DDevice9* device;
    };
}

#endif
