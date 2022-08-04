#pragma once
#ifndef __UE4__H__
#define __UE4__H__

#include "Native.h"
#include "ue4structs.h"
#include "util.h"
#include "offsets.h"
#include "offsets.h"
#include "engine.h"

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

	static LocalPlayer* getLocalPlayer() {
		auto pLocalPlayer = (void*)ReadPointer(UpgunnedEngine::GetWorld()->OwningGameInstance->LocalPlayers, 0x0);

		return (LocalPlayer*)pLocalPlayer;
	}

	static float GetFovAngle(void* CameraManager) {
		return Native::GetFovAngle(CameraManager);
	}

	static bool IsServer() {
		auto NetDriver = UpgunnedEngine::GetWorld()->NetDriver;
		if (NetDriver == nullptr) return false;
		bool isServer = Native::IsServer(NetDriver);
		//printf("Is Server : %d\n", isServer);
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

		PRINT_PTR(Engine->ConsoleClass, "ConsoleClass");
		PRINT_PTR(Engine->GameViewport, "GameViewport");

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
	}

	template <typename T>
	static T* StaticFindObject(const wchar_t* ObjectName) {
		return reinterpret_cast<T*>(StaticFindObject(ObjectName));
	}

	static std::wstring FNameToString(void* str) {
		FString result = FString(); //result = nullptr
		Native::FNameToString(str, &result);
		return result.c_str();
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

