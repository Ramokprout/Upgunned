#pragma once

#ifndef __LOCALPLAYER__
#define __LOCALPLAYER__

#include "Native.h"
#include "offsets.h"
#include "ue4.h"
#include "engine.h"
struct LocalPlayerWrapper {

	static void* getPlayerCameraManager(void* PlayerController) {
		auto PlayerCameraManager = (void*)ReadPointer(PlayerController, offsetsManager::PlayerCameraManager);
		return PlayerCameraManager;
	}

	static LocalPlayer* getLocalPlayer() {
		auto pLocalPlayer = (void*)ReadPointer(UpgunnedEngine::GetWorld()->OwningGameInstance->LocalPlayers, 0x0);

		return (LocalPlayer*)pLocalPlayer;
	}

	static PlayerController* getController() {
		auto localPlayer = getLocalPlayer();
		return (PlayerController*)localPlayer->PlayerController;
	}

	static void* getPawn(PlayerController* Controller) {
		return Controller->Character;
	}
};

#endif