#pragma once

#ifndef __HOOKS_H__
#define __HOOKS_H__
#include "Native.h"
#include "ue4structs.h"
#include "util.h"
#include "ue4.h"
#include "Globals.h"
//#define LOGGER
namespace hooks 
{
#ifdef RELOADHOOK
	static void hkReload(AUpGunWeapon* weapon) {
		//printf("Ammo : %d\n", weapon->Ammo);
		//printf("Magazine : %d\n", weapon->Magazine);
		//printf("OnWeaponAmmoChanged : %p\n", weapon->OnWeaponAmmoChanged);
		Native::Reload(weapon);
		//weapon->Magazine = 231;
	}
#endif
	static void hkProcessEvent(UObject* dis, UFunction* fn, void* params) {
#ifdef LOGGER
		std::string nameOfFunction = ue4::FNameToString(&fn->Name);
		std::vector<std::string> ignoredFunctions = {
			"Tick",
				"BlueprintModify",
				"BlueprintPost",
				"BlueprintUpdate",
				"Offset__UpdateFunc",
				"GenNewRot",
				"OnMouse",
				"SetBrushColor",
				"BndEvt__ButtonMenuBase",
				"OnAnimationStarted",
				"OnAnimationFinished",
				"ClientUpdateStats",
				"EvaluateGraphExposedInputs_ExecuteUbergraph",
				"GetTextValue",
				"GetCorrectPing",
				"IsStartButtonEnabled",
				"ServerMovePacked",
				"GetValue",
				"OnRep_ReplicatedWorldTimeSeconds",
				"GetRoundCountText",
				"OnHealthOrOverHealthChanged",
				"OnRep_Transform",
				"GetRespawnText",
				"ClientMoveResponsePacked",
				"OnRep_OverHealth"
		};
		bool noLog = false;
/*		for (auto ignoreFunction : ignoredFunctions) {
			if (nameOfFunction.contains(ignoreFunction)) {
				noLog = true;
			}
		}*/

		auto name = dis->GetName();
		if (std::wstring(name).contains(L"Rifle")) {
			noLog = false;
		}
		else {
			noLog = true;
		}



		if (!noLog) {
/*				struct paramsStruct {
					void* HitComponent;
					void* OtherActor;
					void* OtherComp;
					FVector NormalImpulse;
					struct {
						void* Actor;
						uint8_t bBlockingHit : 1;
						FName BoneName;
						uint8_t bStartPenetrating : 1;
						void* Component;
						float Distance;
					} HitResult;
				};

				auto structuredParams = (paramsStruct*)params;
				structuredParams->OtherActor = ue4::getLocalPlayer()->PlayerController->Character; //bullet teleport lol*/
			printf("Function name : %s\n", nameOfFunction.c_str());
		}
		Native::FMemoryFree(name);
#endif

		return Native::oProcessEvent(dis, fn, params);
	}




	//static void hkPostRender(void* invocker, void* canvas) {
	//	//if (!Globals::boxesESP && !Globals::snapLines) return;


	//}

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
};

#endif