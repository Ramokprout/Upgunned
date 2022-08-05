#pragma once

#ifndef __HOOKS_H__
#define __HOOKS_H__
#include "Native.h"
#include "ue4structs.h"
#include "util.h"
#include "ue4.h"
#include "Globals.h"
//#define LOGGER
namespace hooks {
	static void hkProcessEvent(UObject* dis, UFunction* fn, void* params) {
#ifdef LOGGER
		std::wstring nameOfFunction = ue4::FNameToString(&fn->Name);
		std::vector<std::wstring> ignoredFunctions = {
			L"Tick",
		//	L"BlueprintModify",
		//	L"BlueprintPost",
		//	L"BlueprintUpdate",
		//	L"Offset__UpdateFunc",
			L"GenNewRot",
			L"OnMouse",
			L"SetBrushColor",
			L"BndEvt__ButtonMenuBase",
			L"OnAnimationStarted",
			L"OnAnimationFinished",
			L"ClientUpdateStats"
		};
		bool noLog = false;
		for (auto ignoreFunction : ignoredFunctions) {
			if (nameOfFunction.contains(ignoreFunction)) {
				noLog = true;
			}
		}
		if (!noLog) {
			wprintf(L"Name Of Fct : %s\n", nameOfFunction.c_str());
		}
	
#endif

		auto localPlayer = ue4::getLocalPlayer();
		if (localPlayer->PlayerController) {
			auto weaponAttributeSet = localPlayer->PlayerController->Character->PlayerState->WeaponAttributeSet;
		
			/*if (Globals::noSpread->enabled) {
				weaponAttributeSet->RifleDispersion.CurrentValue = Globals::noSpread->OriginalValue * Globals::noSpread->Multiplier;
			}		
			
			if (Globals::RifleFireRateMultiplier->enabled) {
				weaponAttributeSet->RifleFireRate.CurrentValue = Globals::RifleFireRateMultiplier->OriginalValue * Globals::RifleFireRateMultiplier->Multiplier;
			}		
			
			if (Globals::BulletSpeedMultiplier->enabled) {
				weaponAttributeSet->RifleBulletSpeed.CurrentValue = Globals::BulletSpeedMultiplier->OriginalValue * Globals::BulletSpeedMultiplier->Multiplier;
			}		
			
			if (Globals::RifleCriticalHitChanceMultiplier->enabled) {
				weaponAttributeSet->RifleCriticalHitChance.CurrentValue = Globals::RifleCriticalHitChanceMultiplier->OriginalValue * Globals::RifleCriticalHitChanceMultiplier->Multiplier;
			}*/

	

		}

		//localPlayer->PlayerController->Character->PlayerState->WeaponAttributeSet->RifleMagazine.CurrentValue = (float)Globals::RifleMagazine;

		return Native::oProcessEvent(dis, fn, params);
	}

	static void hkPostRender(void* invocker, void* canvas) {
		//Native::K2_DrawBox(canvas, { 100, 300 }, { 100, 500 }, 15, { 255, 255,255,255 });
		//Native::K2_DrawLine(canvas, { 100, 300 }, { 300, 100 }, 100, { 63, 255, 51, 100 });
	}
#ifdef AESHOOK
	static void hkDecryptData(void* unk, void* unk2, void* key) {
		struct AesKey {
			uint8_t Key[256];
		};

		auto AK = (AesKey*)(key);
		
		printf("aes key : ");
		for (int i = 0; i < 32; i++) {
			printf("%02X", AK->Key[i]);
		}
		printf("\n");
	}

#endif
}

#endif