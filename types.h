#pragma once

#ifndef __TYPES_H__
#define __TYPES_H__
#include "pch.h"
#include "primitivesUE4Structs.h"

typedef HRESULT(__stdcall* Present)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

namespace Native {

	inline void(__fastcall* oProcessEvent)(void*, void*, void*);
	inline void(__fastcall* oPostRender)(void*, void*);
	inline uintptr_t* (__fastcall* StaticFindObject)(uintptr_t* ObjectClass, uintptr_t* InObjectPackage, const wchar_t* OriginName, bool ExactClass);
	inline void* (__fastcall* SpawnObject)(void*, void*);
	inline void(__fastcall* FNameToString)(void*, void*);
	//template<class T>
	//inline T* (__fastcall* GetGameInstance)(void*);
	inline void(__fastcall* K2_DrawLine)(void*, FVector2D, FVector2D, float, FLinearColor);
	inline void(__fastcall* K2_DrawBox)(void*, FVector2D, FVector2D, float, FLinearColor);
	inline void*(__fastcall* K2_GetPawn)(void*);
	inline void* (__fastcall* StaticConstructObject_internal)(void*, void*, void*, int, int, void*, bool, void*, bool);
	inline bool(__fastcall* IsServer)(void*);
	inline float(__fastcall* GetFovAngle)(void*);
	//inline void(__fastcall* FOV)(void*, float);
	inline Present oPresent;
	inline HRESULT(*oResize)(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) = nullptr;
	inline PVOID* UWorld;
	inline PVOID* GEngine;
	inline PVOID* GObjects;
	//inline PVOID* EngineProxy;
};

#endif