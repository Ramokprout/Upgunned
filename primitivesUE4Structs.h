#pragma once

#ifndef __PRIMITIVES_UE4_STRUCTS__
#define __PRIMITIVES_UE4_STRUCTS__

class Character
{
public:
	char pad_0000[152]; //0x0000
	float CustomTimeDilatation; //0x0098
	char pad_009C[492]; //0x009C
	class CharacterMovement* CharacterMovement; //0x0288
};

class CharacterMovement
{
public:
	char pad_0000[336]; //0x0000
	float GravityScale; //0x0150
	char pad_0154[4]; //0x0154
	float JumpZVelocity; //0x0158
	char pad_015C[52]; //0x015C
	float MaxWalkSpeed; //0x18C
	float MaxWalkSpeedCrouched; //0x190
	char pad_0190[16]; //0x194
	float MaxAcceleration; //0x1A0
};

class UObject;



struct SpawnObject_Params
{
	UObject* ObjectClass;
	UObject* Outer;
	UObject* ReturnValue;
};

class UWorldProxy
{
public:
	void* World;
};

class GEngineProxy
{
public:
	void* GEngine;
};

template<class T>
struct TArray {
	friend struct FString;

public:
	inline TArray() {
		Data = nullptr;
		Count = Max = 0;
	};

	inline INT Num() const {
		return Count;
	};

	inline T& operator[](INT i) {
		return Data[i];
	};

	inline BOOLEAN IsValidIndex(INT i) {
		return i < Num();
	}

public:
	T* Data;
	INT Count;
	INT Max;
};

struct FString : public TArray<WCHAR> {
	FString() {
		Data = nullptr;
		Max = Count = 0;
	}

	FString(LPCWSTR other) {
		Max = Count = static_cast<INT>(wcslen(other));

		if (Count) {
			Data = const_cast<PWCHAR>(other);
		}
	};

	inline BOOLEAN IsValid() {
		return Data != nullptr;
	}

	inline PWCHAR c_str() {
		return Data;
	}
};

typedef struct {
	float X, Y, Z;
} FVector;

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

typedef struct {
	float A;
	float R;
	float G;
	float B;
} FLinearColor;




#endif