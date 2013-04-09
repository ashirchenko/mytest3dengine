#ifndef Vertex3PNT_h_
#define Vertex3PNT_h_

#include <d3d9.h>
#include <d3dx9.h>

namespace utils_private
{
	struct Vertex3PNT
	{
		Vertex3PNT( D3DXVECTOR3& pos, D3DXVECTOR3& norm, D3DXVECTOR2& tex );

		D3DXVECTOR3 position;
		D3DXVECTOR3 normal;
		D3DXVECTOR2 texture;

		static IDirect3DVertexDeclaration9* declaration;
	};
}

#endif
