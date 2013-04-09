#pragma once

#include <windows.h>

#define MYTEST3DENGINEDLL_EXPORTS

#ifdef MYTEST3DENGINEDLL_EXPORTS
#define MY3DENGINE_EXPORT __declspec(dllexport) 
#else
#define MY3DENGINE_EXPORT __declspec(dllimport) 
#endif
