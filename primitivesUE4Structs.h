#pragma once

#ifndef __PRIMITIVES_UE4_STRUCTS__
#define __PRIMITIVES_UE4_STRUCTS__

class UObject;

// Created with ReClass.NET 1.2 by KN4CK3R

class UWorld
{
public:
	char pad_0000[56]; //0x0000
	void* NetDriver; //0x0038
	char pad_0040[320]; //0x0040
	class OwningGameInstance* OwningGameInstance; //0x0180
	char pad_0188[1720]; //0x0188
}; //Size: 0x0840

class OwningGameInstance
{
public:
	char pad_0000[56]; //0x0000
	void* LocalPlayers; //0x0038
	char pad_0040[192]; //0x0040
}; //Size: 0x0100

class GameViewportClient
{
public:
	char pad_0000[64]; //0x0000
	void* ViewportConsole; //0x0040
	char pad_0048[48]; //0x0048
	class UWorld* World; //0x0078
	char pad_0080[1984]; //0x0080
}; //Size: 0x0840

class PlayerController
{
public:
	char pad_0000[672]; //0x0000
	class Character* Character; //0x02A0
	char pad_02A8[16]; //0x02A8
	class PlayerCameraManager* PlayerCameraManager; //0x02B8
	char pad_02C0[112]; //0x02C0
	void* CheatManager; //0x0330
	char pad_0338[240]; //0x0338
}; //Size: 0x0428

class Character
{
public:
	char pad_0000[152]; //0x0000
	float CustomTimeDilatation; //0x0098
	char pad_009C[492]; //0x009C
	class CharacterMovement* CharacterMovement; //0x0288
	char pad_0290[48]; //0x0290
}; //Size: 0x02C0

class PlayerCameraManager
{
public:
	char pad_0000[64]; //0x0000
}; //Size: 0x0040

class CharacterMovement
{
public:
	char pad_0000[336]; //0x0000
	float GravityScale; //0x0150
	char pad_0154[4]; //0x0154
	float JumpZVelocity; //0x0158
	char pad_015C[52]; //0x015C
	float MaxWalkSpeedCrouched; //0x0190
	char pad_0194[12]; //0x0194
	float MaxAcceleration; //0x01A0
	char pad_01A4[1956]; //0x01A4
}; //Size: 0x0948

class GEngineProxy
{
public:
	class GEngine* GEngine; //0x0000
	char pad_0008[56]; //0x0008
}; //Size: 0x0040

class GEngine
{
public:
	char pad_0000[240]; //0x0000
	void* ConsoleClass; //0x00F0
	char pad_00F8[1672]; //0x00F8
	class GameViewportClient* GameViewport; //0x0780
	char pad_0788[1152]; //0x0788
}; //Size: 0x0C08

class LocalPlayer
{
public:
	char pad_0000[48]; //0x0000
	class PlayerController* PlayerController; //0x0030
	char pad_0038[8]; //0x0038
}; //Size: 0x0040


#endif