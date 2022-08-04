#pragma once
#ifndef __UE4__H__
#define __UE4__H__

#include "types.h"
#include "ue4structs.h"
#include "util.h"
#include "offsets.h"
#include "Globals.h"
#include "LocalPlayer.h"
class ue4
{
private :
	static uintptr_t* StaticFindObject(const wchar_t* ObjectName) {
		return Native::StaticFindObject(nullptr, nullptr, ObjectName, false);
	}
public:

	static void* GetWorld() {
		auto UWProxy = (UWorldProxy*)Native::UWorld;
		return UWProxy->World;
	}

	static void* GetEngine() {
		auto GEProxy = (GEngineProxy*)Native::GEngine;
		return GEProxy->GEngine;
	}

	static void FOV(void* PlayerController, float newFOV) 
	{
		auto fn = ue4::StaticFindObject<UObject>(L"Engine.PlayerController:FOV");
		
		struct {
			float NewFOV;
		} params;

		params.NewFOV = newFOV;

		Native::oProcessEvent(PlayerController, fn, &params);
	//	Native::FOV(PlayerController, newFOV);
	}

	static float GetFovAngle(void* CameraManager) {
		return Native::GetFovAngle(CameraManager);
	}

	static bool IsServer() {
		auto NetDriver = (void*)ReadPointer(GetWorld(), offsetsManager::NetDriver);
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
		auto Engine = GetEngine();
		auto ConsoleClass = (void*)ReadPointer(Engine, offsetsManager::ConsoleClass);
		auto GameViewPort = (void*)ReadPointer(Engine, offsetsManager::GameViewport);

		void* ViewportConsoleAddress = reinterpret_cast<void*>((DWORD_PTR)GameViewPort + offsetsManager::ViewportConsole);

		PRINT_PTR(ConsoleClass, "ConsoleClass");
		PRINT_PTR(GameViewPort, "GameViewPort");

		SpawnObject_Params params{
		(UObject*)ConsoleClass,
		(UObject*)GameViewPort
		};



		auto ret = ue4::EasySpawnObject(params);

		WritePointerRaw((LPVOID*)ViewportConsoleAddress, ret);
	}

	static void BuildCheatManager() {
		auto Controller = LocalPlayerWrapper::getController(Globals::LocalPlayer);
		PRINT_PTR(Controller, "Controller");
		void* CheatManagerAddress = reinterpret_cast<void*>((DWORD_PTR)Controller + offsetsManager::CheatManager);

		auto CheatManagerClass = ue4::StaticFindObject<UObject>(L"Engine.CheatManager");

		SpawnObject_Params params{
			CheatManagerClass,
			(UObject*)Controller
		};

		auto ret = ue4::EasySpawnObject(params);

		WritePointerRaw((LPVOID*)CheatManagerAddress, ret);
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


};

#endif

