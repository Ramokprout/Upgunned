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
		for (auto ignoreFunction : ignoredFunctions) {
			if (nameOfFunction.contains(ignoreFunction)) {
				noLog = true;
			}
		}
		if (!noLog) {
			printf("Name Of Fct : %s\n", nameOfFunction.c_str());
		}

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