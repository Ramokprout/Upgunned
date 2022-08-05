#pragma once


#ifndef __GLOBALS_VARIABLES__
#define __GLOBALS_VARIABLES__

#include "pch.h"

class ValueMultiplier;


namespace Globals {
	inline HWND window = NULL;
	inline WNDPROC oWndProc;
	inline ID3D11Device* pDevice = NULL;
	inline ID3D11DeviceContext* pContext = NULL;
	inline ID3D11RenderTargetView* mainRenderTargetView;
	inline IDXGISwapChain* swapChain = nullptr;
	bool showMenu = true;
	bool init = false;
//	bool bCanBeDamaged = false;
	ValueMultiplier* noSpread = nullptr;
	ValueMultiplier* RifleFireRateMultiplier = nullptr;
	ValueMultiplier* BulletSpeedMultiplier = nullptr;
	ValueMultiplier* RifleCriticalHitChanceMultiplier = nullptr;
	ValueMultiplier* HealthMultiplier = nullptr;
	ValueMultiplier* WalkSpeedMultiplier = nullptr;
	void* GWorldTrigger = nullptr;
	int RifleMagazine = 20;
	int tab = 0;
	int FOV = 90;
};

class ValueMultiplier {
public:
	float OriginalValue = 0.00f;
	float Multiplier = 1.00f;
	bool enabled = false;
	bool enabledCheckbox = false;
	void* GWorldAssociated = Globals::GWorldTrigger;
};

#endif