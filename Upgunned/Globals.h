#pragma once


#ifndef __GLOBALS_VARIABLES__
#define __GLOBALS_VARIABLES__

#include "pch.h"




namespace Globals {
	inline HWND window = NULL;
	inline WNDPROC oWndProc;
	inline ID3D11Device* pDevice = NULL;
	inline ID3D11DeviceContext* pContext = NULL;
	inline ID3D11RenderTargetView* mainRenderTargetView;
	inline IDXGISwapChain* swapChain = nullptr;
	bool showMenu = true;
	bool init = false;
	bool bCanBeDamaged = false;
	int tab = 0;
	int FOV = 90;
};

#endif