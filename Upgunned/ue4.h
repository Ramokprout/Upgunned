#pragma once
#ifndef __UE4__H__
#define __UE4__H__

#include "Native.h"
#include "ue4structs.h"
#include "util.h"
#include "engine.h"
#include "upgunstructs.h"
#include "Globals.h"
#include <map>
#define M_PI 3.14159265358979323846
struct SpawnObject_Params
{
	UObject* ObjectClass;
	UObject* Outer;
	UObject* ReturnValue;
};

class ue4
{
private :
	static uintptr_t* StaticFindObject(const wchar_t* ObjectName) {
		return Native::StaticFindObject(nullptr, nullptr, ObjectName, false);
	}
public:

	static FVector2D V2Subtract(FVector2D point1, FVector2D point2)
	{
		FVector2D vector{ 0, 0 };
		vector.X = point1.X - point2.X;
		vector.Y = point1.Y - point2.Y;
		return vector;
	}

	static FVector Subtract(FVector point1, FVector point2)
	{
		FVector vector{ 0, 0, 0 };
		vector.X = point1.X - point2.X;
		vector.Y = point1.Y - point2.Y;
		vector.Z = point1.Z - point2.Z;
		return vector;
	}

	static float GetDistance2D(FVector2D point1, FVector2D point2)
	{
		FVector2D heading = V2Subtract(point2, point1);
		float distanceSquared;
		float distance;

		distanceSquared = heading.X * heading.X + heading.Y * heading.Y;
		distance = sqrt(distanceSquared);

		return distance;
	}

	static float GetDistance(FVector point1, FVector point2)
	{
		FVector heading = Subtract(point2, point1);
		float distanceSquared;
		float distance;

		distanceSquared = heading.X * heading.X + heading.Y * heading.Y + heading.Z * heading.Z;
		distance = sqrt(distanceSquared);

		return distance;
	}

	static Character* GetClosestPlayer(std::vector<Character*> players, FVector* HeadPos = nullptr, bool mustBeVisible = true) {
		auto localPlayer = ue4::getLocalPlayer();
		if (!localPlayer->PlayerController) return nullptr;
		auto PlayerController = localPlayer->PlayerController;
		if (!localPlayer->PlayerController->Character) return nullptr;
		auto localPawn = PlayerController->Character;
		if (!localPlayer->PlayerController->Character->RootComponent) return nullptr;
		auto localPos = localPawn->RootComponent->Location;
		Character* foundPlayer = nullptr;
		float foundPlayerDist = 99999;
		FVector playerRootLocation = {0};
		for(auto player : players) {
			if (ue4::IsLocalPlayer(player)) continue;
			ue4::GetBoneLocation(player->Mesh, &playerRootLocation, UpGunBoneIds::PELVIS);
			auto dist = GetDistance(localPos, playerRootLocation);
			if (dist < foundPlayerDist && mustBeVisible == false) {
				foundPlayer = player;
				foundPlayerDist = dist;
			}
			else if (dist < foundPlayerDist && mustBeVisible == true && ue4::LineOfSightTo(PlayerController, player)) {
				foundPlayer = player;
				foundPlayerDist = dist;
			}
		}

		if (foundPlayer && HeadPos) {
			*HeadPos = playerRootLocation;
		}

		return foundPlayer;
	}

	static bool IsVisible(PlayerController* Controller, Character* player) {
		float fVisionTick = 0.06f;

		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Controller:LineOfSightTo");

		struct {
			Character* Other;
			FVector ViewPoint;
			bool bAlternateChecks;
			bool ReturnValue;
		}params;

		params.Other = player;
		params.ViewPoint = {0, 0, 0};
		params.bAlternateChecks = false;

		Native::oProcessEvent(Controller, fn, &params);

		return player->Mesh->LastRenderTimeOnScreen + fVisionTick >= player->Mesh->LastSumbit && params.ReturnValue;
	}

	static void AimAt(PlayerController* Controller, FVector Location) {
	//	FVector localPos = Controller->PlayerCameraManager->TransformComponent->Location;
		//FVector relativePos = Subtract(Pos, localPos);
		//float tmp = atan2(relativePos.Y, relativePos.X) * 180 / M_PI;
		//float pitch = -((acos(relativePos.Z / GetDistance(localPos, Pos)) * 180 / M_PI) - 90);
		

		//auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Controller:SetControlRotation");
		//struct {
		//	FRotator NewRotation;
		//}params;

		//FVector NewRotationVector = { 0 };
		//ue4::GetBoneLocation(Character->Mesh, &NewRotationVector, UpGunBoneIds::HEAD);
		//FVector HeadScreen = { 0 };
		//if (Native::ProjectWorldToScreen(Controller, &NewRotationVector, &HeadScreen, false)) {
		//	auto CamLoc = Controller->Character->RootComponent->Location;
		//	auto VectorPos = Subtract(HeadScreen, CamLoc);

		//	auto dist = sqrt(VectorPos.X * VectorPos.X + VectorPos.Y * VectorPos.Y + VectorPos.Z * VectorPos.Z);

		//	NewRotationVector.X = -((acosf(VectorPos.Z / dist) * (float)(180.0f / M_PI)) - 90.f);
		//	NewRotationVector.Y = atan2f(VectorPos.Y, VectorPos.X) * (float)(180.0f / M_PI);
		////	return NewRotationVector;
		//	params.NewRotation = { NewRotationVector.X, NewRotationVector.Y, NewRotationVector.Z };
		//	Native::oProcessEvent(Controller, fn, &params);
		//}

		//Native::oProcessEvent(Controller, fn, &params);

	//	printf("tmp : %f\n", tmp);
	//	printf("pitch : %f\n", pitch);
	}

	static bool LineOfSightTo(PlayerController* Controller, Character* player) {
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Controller:LineOfSightTo");

		struct {
			Character* Other;
			FVector ViewPoint;
			bool bAlternateChecks;
			bool ReturnValue;
		} params;

		params.Other = player;
		params.ViewPoint = {0, 0,0};
		params.bAlternateChecks = false;

		Native::oProcessEvent(Controller, fn, &params);

		return params.ReturnValue;
	}

	static bool IsInFOV(Character* m_Player, FVector position, float fov)
	{
		FVector2D centerScreen{ (float)Globals::width / 2, (float)Globals::height / 2 };
		FVector2D screenPos;
		if (Native::ProjectWorldToScreen(m_Player, &position, &screenPos, false))
		{
			float dist = GetDistance2D(centerScreen, screenPos);
			if (dist < fov)
				return true;
		}
		return false;
	}

	static void GetBoneLocation(Mesh* pMesh, FVector* vBone, int BoneId)
	{

		int boneidx = BoneId;
		FMatrix vMatrix;
		FMatrix* vTempvMatrix = (FMatrix*)Native::GetBoneMatrix(pMesh, &vMatrix, boneidx);
		FVector result = { 0 };
		result.X = vMatrix.M[3][0];
		result.Y = vMatrix.M[3][1];
		result.Z = vMatrix.M[3][2];
		*vBone = result;//Trans
	}

	static float getDistance(Character* pawn1, Character* pawn2) {
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Actor:GetDistanceTo");
		struct {
			Character* otherPawn;
			float ReturnValue;
		} params;

		params.otherPawn = pawn2;

		Native::oProcessEvent(pawn1, fn, &params);

		return params.ReturnValue;
	}
	
	static TArray<FName> GetAllSocketNames(void* Mesh) {
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.SceneComponent:GetAllSocketNames");

		struct {
			TArray<FName> ReturnValue;
		} params;

		Native::oProcessEvent(Mesh, fn, &params);

		return params.ReturnValue;
	}

	static FName GetSocketBoneName(void* Mesh, FName InSocketName) {
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.SkinnedMeshComponent:GetSocketBoneName");
		struct {
			FName InSocketName;
			FName ReturnValue;
		} params;
		params.InSocketName = InSocketName;

		Native::oProcessEvent(Mesh, fn, &params);

		return params.ReturnValue;
	}

	static int GetBoneIndex(void* Mesh, FName BoneName) {
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.SkinnedMeshComponent:GetBoneIndex");
		struct {
			FName BoneName;
			int ReturnValue;
		} params;

		params.BoneName = BoneName;

		Native::oProcessEvent(Mesh, fn, &params);

		return params.ReturnValue;
	}



	static LocalPlayer* getLocalPlayer() {
		auto pLocalPlayer = (void*)ReadPointer(UpgunnedEngine::GetWorld()->OwningGameInstance->LocalPlayers, 0x0);
		return (LocalPlayer*)pLocalPlayer;
	}

	static bool IsLocalPlayer(Character* player) {
		if (!player->PlayerState) return true;
		auto localPlayer = getLocalPlayer();
		if (!localPlayer) return true;
		if (!localPlayer->PlayerController) return true;
		if (!localPlayer->PlayerController->Character) return true;
		if (!localPlayer->PlayerController->Character->PlayerState) return true;
		return player->PlayerState->PlayerId == localPlayer->PlayerController->Character->PlayerState->PlayerId;
	}

	static bool IsServer() {
		auto NetDriver = UpgunnedEngine::GetWorld()->NetDriver;
		if (NetDriver == nullptr) return false;
		bool isServer = Native::IsServer(NetDriver);
		return isServer;
	}

	static UObject* EasySpawnObject(SpawnObject_Params params) {
		auto GameplayStatics = ue4::StaticFindObject<void*>(L"Engine.Default__GameplayStatics");
		auto SpawnObject = ue4::StaticFindObject<void*>(L"Engine.GameplayStatics:SpawnObject");

		Native::oProcessEvent(GameplayStatics, SpawnObject, &params);

		return params.ReturnValue;
	}

	static void BuildConsole() {
		auto Engine = UpgunnedEngine::GetEngine();

#ifdef DEBUGLOG
		PRINT_PTR(Engine->ConsoleClass, "ConsoleClass");
		PRINT_PTR(Engine->GameViewport, "GameViewport");
#endif

		SpawnObject_Params params
		{
			(UObject*)Engine->ConsoleClass,
			(UObject*)Engine->GameViewport 
		};

		auto ret = ue4::EasySpawnObject(params);

		WritePointerRaw((LPVOID*)&Engine->GameViewport->ViewportConsole, ret);
	}

	static void BuildCheatManager() {
		auto LocalPlayer = ue4::getLocalPlayer();

		auto CheatManagerClass = ue4::StaticFindObject<UObject>(L"Engine.CheatManager");

		SpawnObject_Params params{
			CheatManagerClass,
			(UObject*)LocalPlayer->PlayerController
		};

		auto ret = ue4::EasySpawnObject(params);

		WritePointerRaw((LPVOID*)&LocalPlayer->PlayerController->CheatManager, ret);
#ifdef DEBUGLOG
		printf("CheatManager ptr : %p\n", LocalPlayer->PlayerController->CheatManager);
#endif
	}

	template <typename T>
	static T* StaticFindObject(const wchar_t* ObjectName) {
		return reinterpret_cast<T*>(StaticFindObject(ObjectName));
	}

	static std::string FNameToString(void* str) {
		FString *result = new FString(); //result = nullptr
		Native::FNameToString(str, result);
		std::wstring *wStr = new std::wstring(result->c_str());
		std::string fStr = std::string(wStr->begin(), wStr->end());
		delete wStr;
		Native::FMemoryFree(result->c_str());
		return fStr;
	}

	inline static std::vector<Character*> getPlayers() {
		std::vector<Character*> characters = {};
		auto level = UpgunnedEngine::GetWorld()->PersistentLevel;
		auto AActors = level->AActors;
		for (int i = 0; i < AActors.Count; i++) {
			if (!AActors.IsValidIndex(i)) continue;
			auto actor = level->AActors.Data[i];
			if (!actor || actor == NULL) continue;
			auto Uobj = ((UObject*)actor);
			if (!IsBadReadPtr(&Uobj->Name, sizeof(Uobj->Name))) {
				if (&Uobj->Name == nullptr) continue;
				FString* str = new FString();
				if (&Uobj->Name == nullptr) continue;
				Native::FNameToString(&Uobj->Name, str);
				std::wstring* wStr = new std::wstring(str->c_str());
				Native::FMemoryFree(str->c_str());
				if (wStr->contains(L"Character_C")) {
					characters.push_back(actor);
				}
				delete wStr;
				delete str;
		//		if (!wStr.contains(L"Character_C")) continue;	
			}
		}

		//AActors.FreeArray();
		return characters;
	
		//return std::make_pair(characters, & AActors);
	}

	static FMinimalViewInfo GetViewInfo(PlayerController* Controller) {
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Controller:GetViewTarget");

		struct {
			FMinimalViewInfo* ReturnValue;
		} params;

		Native::oProcessEvent(Controller, fn, &params);

		return *params.ReturnValue;
	}

	static FVector K2_GetActorLocation(void* Actor) 
	{
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Actor:K2_GetActorLocation");

		struct {
			FVector ReturnValue;
		} params = { 0 };

		Native::oProcessEvent(Actor, fn, &params);

		return params.ReturnValue;
	}	
	
	static FRotator K2_GetActorRotation(void* Actor)
	{
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.Actor:K2_GetActorRotation");

		struct {
			FRotator ReturnValue;
		} params = { 0 };

		Native::oProcessEvent(Actor, fn, &params);

		return params.ReturnValue;
	}

/*	static std::wstring GetPlayerName(PlayerState* playerState) {
		//Function /Script/
		auto fn = ue4::StaticFindObject<UFunction>(L"Engine.PlayerState:GetPlayerName");

		struct {
			FString ReturnValue;
		} params = { 0 };

		Native::oProcessEvent((void*)playerState, fn, &params);

		return params.ReturnValue.c_str();
	}*/
};

#endif

