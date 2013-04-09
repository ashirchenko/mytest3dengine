#ifndef Vertex3PN_h_
#define Vertex3PN_h_

#include <d3d9.h>
#include <d3dx9.h>

namespace utils_private
{
    struct Vertex3PN
    {
        Vertex3PN( float x, float y, float z, float nx, float ny, float nz );
        Vertex3PN( const D3DXVECTOR3& pos, const D3DXVECTOR3& norm );

        D3DXVECTOR3 position;
        D3DXVECTOR3 normal;

        static IDirect3DVertexDeclaration9* declaration;
    };
}

#endif
