#pragma once

#ifndef __UPGUN__STRUCTS__
#define __UPGUN__STRUCTS__

#include "ue4structs.h"



class UObject;
class Character;

enum UpGunBoneIds {
	Foot_LEFT = 57,
	Foot_RIGHT = 51,
	lowerarm_r = 30,
	upperarm_r = 29,
	clavicle_r = 28,
	lowerarm_l = 9,
	upperarm_l = 8,
	clavicle_l = 7,
	HEAD = 6,
	NECK = 5,
	PELVIS = 1,
	ROOT = 0,
};

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

class WorldSettings
{
public:
	char pad_0000[744]; //0x0000
	float TimeDilatation; //0x02E8
	char pad_02EC[28]; //0x02EC
}; //Size: 0x0308

class ActorsArray
{
public:
	Character** Data; //0x0000
	uint32_t Count; //0x0008
	uint32_t Max; //0x000C
	char pad_0010[8]; //0x0010

	inline INT Num() const {
		return Count;
	};

	inline Character* operator[](INT i) {
		return Data[i];
	};

	inline BOOLEAN IsValidIndex(INT i) {
		return i < Num();
	}
}; //Size: 0x0018

class ULevel
{
public:
	char pad_0000[152]; //0x0000
	class TArray<Character*> AActors; //0x0098
	char pad_00B0[424]; //0x00B0
	class WorldSettings* WorldSettings; //0x0268
	char pad_0270[424]; //0x0270
}; //Size: 0x0418





class UWorld
{
public:
	char pad_0000[48]; //0x0000
	class ULevel* PersistentLevel; //0x0030
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


class Mesh
{
public:
	char pad_0000[284]; //0x0000
	FVector RelativeLocation; //0x011C
	FRotator RelativeRotation; //0x0128
	FVector RelativeScale3D; //0x0134
	FVector ComponentVelocity; //0x0140
	char pad_014C[296]; //0x014C
	float BoundsScale; //0x0274
	float LastSumbit; //0x0278
	float LastRender; //0x027C
	float LastRenderTimeOnScreen; //0x0280
	char pad_0284[484]; //0x0284
	void* StaticMesh; //0x0468
	char pad_0470[136]; //0x0470



	//

}; //Size: 0x0524


class SceneComponent
{
public:
	char pad_0000[284]; //0x0000
	FVector Location; //0x011C
	FVector RelativeRotation; //0x0128
	char pad_0134[36]; //0x0134

}; //Size: 0x014C
class Character
{
public:
	char pad_0000[152]; //0x0000
	float CustomTimeDilatation; //0x0098
	char pad_009C[148]; //0x009C
	class SceneComponent* RootComponent; //0x0130
	char pad_0138[264]; //0x0138
	class PlayerState* PlayerState; //0x0240
	char pad_0248[56]; //0x0248
	Mesh* Mesh; //0x0280
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
	char pad_0000[544]; //0x0000
	class PlayerController* PCOwner; //0x0220
	class SceneComponent* TransformComponent; //0x0228
	char pad_0230[8]; //0x0230
	float DefaultFOV; //0x0238
	char pad_023C[4]; //0x023C
	float DefaultOrthoWidth; //0x0240
	char pad_0244[4]; //0x0244
	float DefaultAspectRatio; //0x0248
	char pad_024C[52]; //0x024C
}; //Size: 0x0280

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
	char pad_0000[112]; //0x0000
	void* MediumFont; //0x0070
	char pad_0078[24]; //0x0078
	void* LargeFont; //0x0090
	char pad_0098[88]; //0x0098
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

class UpGunChatRoomId {
public:
	BYTE Id;
};

class UpGunChatRoom {
public:
	UpGunChatRoomId* ChatRoomId;
	FString Name;
	TArray<void*> Players;
};

class UpGunChatManagerComponent
{
public:
	char pad_0000[176]; //0x0000
	void* AwaitingMessages; //0x00B0
	char pad_00B8[8]; //0x00B8
	TArray<UpGunChatRoom*> Rooms; //0x00C0
	char pad_00C8[128]; //0x00C8
}; //Size: 0x0148

class GameState
{
public:
	char pad_0000[552]; //0x0000
	void* AuthorityGameMode; //0x0228
	char pad_0230[8]; //0x0230
	TArray<PlayerState>* PlayerArray; //0x0238
	char pad_0240[48]; //0x0240
	class UpGunChatManagerComponent* ChatManager; //0x0270
	void* GameMode; //0x0278
	void* GameModeSettings; //0x0280
	char pad_0288[8]; //0x0288

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