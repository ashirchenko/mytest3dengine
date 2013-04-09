#include <ViewMatrix.h>

namespace Core
{
    ViewMatrix::ViewMatrix()
        : device( NULL )
    {

    }

    void ViewMatrix::setDevice( IDirect3DDevice9* device )
    {
        this->device = device;
    }

    void ViewMatrix::apply()
    {
        if ( device )
            device->SetTransform( D3DTS_VIEW, &matrix );
    }

    void ViewMatrix::ortohonal()
    {
        D3DXMatrixIdentity( &matrix );
    }

    void ViewMatrix::perspective( const D3DXVECTOR3& pos, const D3DXVECTOR3& target, const D3DXVECTOR3& up )
    {
        D3DXMatrixLookAtLH( &matrix, &pos, &target, &up );
    }
}
