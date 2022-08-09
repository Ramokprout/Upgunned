#pragma once

#ifndef __TYPES_H__
#define __TYPES_H__
#include "pch.h"


typedef HRESULT(__stdcall* Present)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

typedef struct {
	float W, X, Y, Z;
} FQuat;

typedef struct {
	float X, Y, Z;
} FVector;

typedef struct {
	FQuat		Rotation;
	FVector 	Scale3D;
	FVector 	Translation;
} FTransform;

typedef struct {
	float X, Y;
} FVector2D;

typedef struct {
	float Pitch;
	float Yaw;
	float Roll;
} FRotator;

typedef struct {
	FVector Location;
	FRotator Rotation;
	float FOV;
	float OrthoWidth;
	float OrthoNearClipPlane;
	float OrthoFarClipPlane;
	float AspectRatio;
} FMinimalViewInfo;

typedef struct {
	float M[4][4];
} FMatrix;

struct FLinearColor
{
	float R; //0x0000
	float G; //0x0004
	float B; //0x0008
	float A; //0x000C
}; //Size: 0x0010

class FString;

namespace Native {

	inline void(__fastcall* oProcessEvent)(void*, void*, void*);
	inline void(__fastcall* oPostRender)(void*, void*);
	inline uintptr_t* (__fastcall* StaticFindObject)(uintptr_t* ObjectClass, uintptr_t* InObjectPackage, const wchar_t* OriginName, bool ExactClass);
	inline void* (__fastcall* SpawnObject)(void*, void*);
	inline void(__fastcall* FNameToString)(void*, void*);
	inline void(__fastcall* K2_DrawLine)(void*, FVector2D, FVector2D, float, FLinearColor);
	inline void(__fastcall* K2_DrawBox)(void*, FVector2D, FVector2D, float, FLinearColor);
	inline void(__fastcall* K2_DrawText)(void*, void*, FString, FVector2D, FVector2D, FLinearColor, float, FLinearColor, FVector2D, bool, bool, bool, FLinearColor);
	inline void* (__fastcall* StaticConstructObject_internal)(void*, void*, void*, int, int, void*, bool, void*, bool);
	inline void* (__fastcall* GetBoneMatrix)(void*, void*, int);
	inline bool(__fastcall* IsServer)(void*);
	inline bool(__fastcall* ProjectWorldToScreen)(void*, void*, void*, bool);//playercontroller, fvector*, fvector2d*, false
	inline bool(__fastcall* LineOfSightTo)(void*, void*, void*);
	inline void(__fastcall* DecryptData)(void*, void*, void*);
	inline void(__fastcall* FMemoryFree)(void*);

	inline Present oPresent;
	inline HRESULT(*oResize)(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags) = nullptr;
	inline PVOID* GEngine;
	inline PVOID* GObjects;
};

#endif