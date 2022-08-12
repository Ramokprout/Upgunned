#pragma once

#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Native.h"

class UpgunnedEngine { //i just dont know how to name this class lmfao
public:
	static GEngine* GetEngine() {
		auto GEProxy = (GEngineProxy*)Native::GEngine;
		return (GEngine*)GEProxy->GEngine;
	}

	static UWorld* GetWorld() {
		/*	auto UWProxy = (UWorldProxy*)Native::UWorld;
			return (UWorld*)UWProxy->World;*/
		return GetEngine()->GameViewport->World;
	}

	static std::wstring GetGameModeName() {
		auto GameMode = (UObject*)UpgunnedEngine::GetWorld()->GameState->GameMode->GameModeClass;
		auto GameModeName = GameMode->GetName();
		return std::wstring(GameModeName);
	}

	static std::wstring GetGameStateName() {
		auto GameMode = (UObject*)UpgunnedEngine::GetWorld()->GameState;
		auto GameModeName = GameMode->GetName();
		return std::wstring(GameModeName);
	}

	
};

#endif