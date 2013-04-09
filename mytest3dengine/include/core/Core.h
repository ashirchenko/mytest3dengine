
#pragma once

#include <Windows.h>

#include <stdlib.h>
#include <vector>

#include "../export/export.h"
#include "../interfaces/IRenderable.h"

struct IDirect3DDevice9;

namespace core_private
{
	class Timer;
}

namespace Core
{
	class Engine;

	class MY3DENGINE_EXPORT Core : public ISpace::IRenderable
	{
	public:
		static Core* init ( HWND hWnd, size_t wndWidth, size_t wndHeight );

	public:
		void updateFrame( const MSG& msg );
        virtual void render();

	private:
        Core ( HWND hWnd, size_t wndWidth, size_t wndHeight );

        void registerVertexDeclarations();

	private:

		static Core* instance;

		IDirect3DDevice9* device;
		HWND hWnd;

		core_private::Timer* timer;
	};
}
