#include "../../include/core/Core.h"

#include <d3d9.h>
#include <d3dx9.h>

#include "../../src/private/include/core/Timer.h"

#include <Vertex3PN.h>
#include <Vertex3PNT.h>

Core::Core* Core::Core::instance = NULL;

namespace Core
{
	Core* Core::init ( HWND hWnd, size_t wndWidth, size_t wndHeight )
	{
		if ( instance || !hWnd )
			return NULL;

		instance = new Core ( hWnd, wndWidth, wndHeight );

		return instance;
	}

	Core::Core ( HWND hWnd, size_t wndWidth, size_t wndHeight )
		: timer( new core_private::Timer )
	{

	    this->hWnd = hWnd;

		IDirect3D9 * d3d;
		d3d = Direct3DCreate9( D3D_SDK_VERSION );

		D3DPRESENT_PARAMETERS d3dpp;
		d3dpp.BackBufferWidth            = ( UINT )wndWidth;
		d3dpp.BackBufferHeight           = ( UINT )wndHeight;
		d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
		d3dpp.BackBufferCount            = 1;
		d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
		d3dpp.MultiSampleQuality         = 0;
		d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
		d3dpp.hDeviceWindow              = hWnd;
		d3dpp.Windowed                   = true;
		d3dpp.EnableAutoDepthStencil     = true;
		d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
		d3dpp.Flags                      = 0;
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

		d3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &device );

		D3DMULTISAMPLE_TYPE mst = D3DMULTISAMPLE_2_SAMPLES;
		DWORD quality = 0;

		d3d->CheckDeviceMultiSampleType( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DFMT_X8R8G8B8, true, mst, &quality );

		d3dpp.MultiSampleType = mst;
		d3dpp.MultiSampleQuality = quality;

		registerVertexDeclarations();
	}

    void Core::updateFrame( const MSG& msg )
    {
        // TODO
    }

    void Core::render()
    {
        device->Clear( 0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DXCOLOR( 0, 0, 0, 1.0f ), 1.0f, 0 );
        device->BeginScene();

        device->EndScene();
        device->Present( 0, 0, 0, 0 );
    }

    void Core::registerVertexDeclarations()
    {
        D3DVERTEXELEMENT9 VertexPNT[] =
        {
                {0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
                {0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0},
                {0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
                D3DDECL_END()
        };

        device->CreateVertexDeclaration( VertexPNT, &utils_private::Vertex3PNT::declaration );

        D3DVERTEXELEMENT9 VertexPN[] =
        {
                {0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
                {0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0},
                D3DDECL_END()
        };

        device->CreateVertexDeclaration( VertexPN, &utils_private::Vertex3PN::declaration );
    }
}
