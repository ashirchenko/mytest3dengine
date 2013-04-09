#include <ProjectionMatrix.h>

namespace Core
{
    ProjectionMatrix::ProjectionMatrix()
        : device( NULL )
    {

    }

    void ProjectionMatrix::setDevice( IDirect3DDevice9* device )
    {
        this->device = device;
    }

    void ProjectionMatrix::apply()
    {
        if ( device )
            device->SetTransform( D3DTS_PROJECTION, &matrix );
    }

    void ProjectionMatrix::perspective( unsigned int width, unsigned int height, float viewField, float nearZ, float farZ )
    {
        D3DXMatrixPerspectiveFovLH( &matrix, D3DX_PI * 0.5f, (float)width / (float)height, nearZ, farZ );
    }

    void ProjectionMatrix::ortohonal( unsigned int width, unsigned int height, float nearZ, float farZ )
    {
        D3DXMatrixOrthoLH( &matrix, (float)width, (float)height, nearZ, farZ );
    }
}
