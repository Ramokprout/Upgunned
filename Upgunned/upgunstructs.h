#pragma once

#ifndef __UPGUN__STRUCTS__
#define __UPGUN__STRUCTS__

#include "ue4structs.h"

class UObject;


// Created with ReClass.NET 1.2 by KN4CK3R

struct UpGunOSSItemId
{
	FString Id;
};

struct UpGunCosmeticSettings {

	UpGunOSSItemId ScreenItemId;

	FLinearColor FaceTint;

	UpGunOSSItemId ArmorItemId;
	UpGunOSSItemId HatItemId;
	UpGunOSSItemId RifleItemId;
	UpGunOSSItemId KnifeItemId;
};



class UWorld
{
public:
	char pad_0000[56]; //0x0000
	void* NetDriver; //0x0038
	char pad_0040[224]; //0x0040
	class GameState* GameState; //0x0120
	char pad_0128[88]; //0x0128
	class OwningGameInstance* OwningGameInstance; //0x0180
	char pad_0188[1720]; //0x0188
}; //Size: 0x0840

class OwningGameInstance
{
public:
	char pad_0000[56]; //0x0000
	void* LocalPlayers; //0x0038
	char pad_0040[200]; //0x0040
}; //Size: 0x0108

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
	char pad_02C0[120]; //0x02C0
	void* CheatManager; //0x0338
	char pad_0340[232]; //0x0340
}; //Size: 0x0428

class Character
{
public:
	char pad_0000[152]; //0x0000
	float CustomTimeDilatation; //0x0098
	char pad_009C[420]; //0x009C
	class PlayerState* PlayerState; //0x0240
	char pad_0248[64]; //0x0248
	class CharacterMovement* CharacterMovement; //0x0288
	char pad_0290[576]; //0x0290
	class CameraComponent* Camera; //0x04D0
	char pad_04D8[24]; //0x04D8
	class CosmeticManager* CosmeticManager; //0x04F0
	char pad_04F8[927]; //0x04F8
}; //Size: 0x0897

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
	char pad_0038[1032]; //0x0038
}; //Size: 0x0440

class StatManager
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class PlayerState
{
public:
	char pad_0000[544]; //0x0000
	float Score; //0x0220
	int32_t PlayerId; //0x0224
	uint8_t Ping; //0x0228
	char pad_0229[23]; //0x0229
	void* SavedNetworkAddress; //0x0240
	char pad_0248[232]; //0x0248
	class AbilitySystem* AbilitySystem; //0x0330
	class SkillManager* SkillManager; //0x0338
	class StatManager StatManager; //0x0340
	class BaseCharacterAttributeSet* BaseCharacterAttributeSet; //0x0348
	class UpGunWeaponAttributeSet* WeaponAttributeSet; //0x0350
	char pad_0358[40]; //0x0358
	UpGunCosmeticSettings CosmeticSettings; //0x0380
	char pad_0388[95]; //0x0388
	int32_t Kills; //0x03E7
	int32_t Deaths; //0x03EB
	uint32_t Assists; //0x03EF
}; //Size: 0x45A3

class AbilitySystem
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class SkillManager
{
public:
	char pad_0000[256]; //0x0000
	char Skills[1][8]; //0x0100
	char pad_0108[1032]; //0x0108
}; //Size: 0x0510

class GameplayAttributeData
{
public:
	char pad_0000[8]; //0x0000
	float BaseValue; //0x0008
	float CurrentValue; //0x000C
}; //Size: 0x0010

class UpGunWeaponAttributeSet
{
public:
	char pad_0000[48]; //0x0000
	class GameplayAttributeData RifleFireRate; //0x0030
	class GameplayAttributeData RifleDamage; //0x0040
	class GameplayAttributeData RifleBulletSpeed; //0x0050
	class GameplayAttributeData RifleMagazine; //0x0060
	class GameplayAttributeData RifleDispersion; //0x0070
	class GameplayAttributeData RifleCriticalHitChance; //0x0080
	class GameplayAttributeData KnifeDamage; //0x0090
	class GameplayAttributeData DamageBaseMultiplier; //0x00A0
	class GameplayAttributeData HeadshotMultiplier; //0x00B0
	char pad_00C0[264]; //0x00C0
}; //Size: 0x01C8

class CameraComponent
{
public:
	char pad_0000[504]; //0x0000
	float FieldOfView; //0x01F8
	char pad_01FC[268]; //0x01FC
}; //Size: 0x0308



class CosmeticManager
{
public:
	char pad_0000[176]; //0x0000
	void* HatRootComponent; //0x00B0
	void* HatActor; //0x00B8
	void* ArmorMat; //0x00C0
	void* ScreenMat; //0x00C8
	void* RifleMat; //0x00D0
	void* Mesh; //0x00D8
	void* HandsMesh; //0x00E0
	void* ScreenMesh; //0x00E8
	void* RifleMesh; //0x00F0
	void* DefaultRifleMesh; //0x00F8
	void* KnifeMat; //0x0100
	void* KnifeMesh; //0x0108
	void* DefaultKnifeMesh; //0x0110
	int32_t ArmorMatIndex; //0x0118
	int32_t ScreenMatIndex; //0x011C
	class FLinearColor ArmorColor; //0x0120
	bool bShouldUseArmorColor; //0x0130
	char pad_0131[31]; //0x0131
}; //Size: 0x0150


/*class UpGunCosmeticSettings
{
public:
	void* ScreenItemId; //0x0000
	char pad_0008[8]; //0x0008
	void* FaceTint; //0x0010
	char pad_0018[8]; //0x0018
	void* ArmorItemId; //0x0020
	char pad_0028[8]; //0x0028
	void* HatItemId; //0x0030
	char pad_0038[8]; //0x0038
	void* RifleItemId; //0x0040
	char pad_0048[8]; //0x0048
	void* KnifeItemId; //0x0050
	char pad_0058[944]; //0x0058
}; //Size: 0x0408*/


class GameState
{
public:
	char pad_0000[568]; //0x0000
	TArray<PlayerState>* PlayerArray; //0x0238
	char pad_0240[8]; //0x0240
}; //Size: 0x0248

class BaseCharacterAttributeSet
{
public:
	char pad_0000[72]; //0x0000
	class GameplayAttributeData Health; //0x0048
	class GameplayAttributeData OverHealth; //0x0058
	class GameplayAttributeData MaxHealth; //0x0068
	class GameplayAttributeData WalkSpeed; //0x0078
	class GameplayAttributeData CrounchSpeed; //0x0088
	class GameplayAttributeData JumpVelocity; //0x0098
	class GameplayAttributeData HeadArmor; //0x00A8
	class GameplayAttributeData Armor; //0x00B8
	class GameplayAttributeData FireResistance; //0x00C8
	char pad_00D8[128]; //0x00D8
}; //Size: 0x0158


#endif