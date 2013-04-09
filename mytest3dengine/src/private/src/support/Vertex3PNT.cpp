#include "../../include/support/Vertex3PNT.h"

namespace utils_private
{
	IDirect3DVertexDeclaration9* Vertex3PNT::declaration = NULL;

	Vertex3PNT::Vertex3PNT( D3DXVECTOR3& pos, D3DXVECTOR3& norm, D3DXVECTOR2& tex )
	{
		position = pos;
		normal = norm;
		texture = tex;
	}
}
