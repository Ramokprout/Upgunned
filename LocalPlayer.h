#pragma once

#ifndef __LOCALPLAYER__
#define __LOCALPLAYER__

#include "types.h"
#include "offsets.h"

struct LocalPlayerWrapper {

	static void* getPlayerCameraManager(void* PlayerController) {
		auto PlayerCameraManager = (void*)ReadPointer(PlayerController, offsetsManager::PlayerCameraManager);
		return PlayerCameraManager;
	}

	static void* getLocalPlayer() {
		auto UWproxy = (UWorldProxy*)Native::UWorld;
		auto OwningGameInstance = ReadPointer(UWproxy->World, offsetsManager::OwningGameInstance);
		auto LocalPlayers = (void*)ReadPointer(OwningGameInstance, offsetsManager::LocalPlayers);
		auto LocalPlayer = (void*)ReadPointer(LocalPlayers, 0x0);

		return LocalPlayer;
	}

	static void* getController(void* localPlayer) {
		UPDATE_LOCAL_PLAYER
		auto Controller = (void*)ReadPointer(localPlayer, offsetsManager::PlayerController);
		return Controller;
	}

	static void* getPawn(void* Controller) {
		auto Pawn = Native::K2_GetPawn(Controller);
		if (IsBadReadPtr(Pawn, sizeof(Pawn))) {
			Pawn = (void*)ReadPointer(Controller, offsetsManager::AcknowledgedPawn);
		}

		return Pawn;
	}
};

#endif