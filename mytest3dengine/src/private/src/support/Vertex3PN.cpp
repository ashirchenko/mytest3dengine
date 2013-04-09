#include "../../include/support/Vertex3PN.h"

namespace utils_private
{
	IDirect3DVertexDeclaration9* Vertex3PN::declaration = NULL;

	Vertex3PN::Vertex3PN(float x, float y, float z, float nx, float ny, float nz)
	{
		position = D3DXVECTOR3( x, y, z );
		normal = D3DXVECTOR3( nx, ny, nz );
	}

	Vertex3PN::Vertex3PN( const D3DXVECTOR3& v, const D3DXVECTOR3& nv )
	{
		position = v;
		normal = nv;
	}
}
