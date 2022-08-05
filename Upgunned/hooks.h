#pragma once

#ifndef __HOOKS_H__
#define __HOOKS_H__
#include "Native.h"
#include "ue4structs.h"
#include "util.h"
#include "ue4.h"
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