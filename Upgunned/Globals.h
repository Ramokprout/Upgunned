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
	int FOV = 110;
	float width = 0;
	float height = 0;
	ImFont* font = nullptr;
	DWORD ProcessPid = 0;

	//AIMBOT
	float AimbotFOV = 180;
	bool renderFOVCircle = false;
	bool AimbotEnabled = false;
	int AimbotSpeedX = 5;
	int AimbotSpeedY = 5;
	float FOVCircleColor[3] = { 255, 0, 0 };
	//ESP
	bool boxesESP = false;
	bool boxesESPVischeck = false;
	float ESPMaxDistance = 600;
	float ESPColor[3] = { 255, 0, 0 };
	float ESPVisibleColor[3] = { 0, 255, 0 };
	//SNAPLINES
	bool snapLines = false;
	bool snapLinesVischeck = false;
	float SnaplinesMaxDistance = 600;
	float SnaplinesColor[3] = { 255, 0, 0 };
	float SnaplinesVisibleColor[3] = { 0, 255, 0 };

	//WATERMARK
	bool showWatermark = false;
	//FPS
	bool showFPS = false;

	bool bonesESP = false;

	AimbotKey Aimbot_Key = AimbotKey::MOUSE_R;
	UpGunBoneIds Aimbot_Pos = UpGunBoneIds::HEAD;
	//int XMODIFDEBUG = 0; // TO REMOVE
	//int YMODIFDEBUG = 0; // TO REMOVE
	//int ZMODIFDEBUG = 0; // TO REMOVE
	//int XMODIFDEBUG2 = 0; // TO REMOVE
	//int YMODIFDEBUG2 = 0; // TO REMOVE
	//int ZMODIFDEBUG2 = 0; // TO REMOVE
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