#pragma once

#ifndef __HOOKS_H__
#define __HOOKS_H__
#include "types.h"
#include "ue4structs.h"
#include "util.h"

namespace hooks {
	static void hkProcessEvent(UObject* dis, UFunction* fn, void* params) {
#ifdef LOGGER
		std::string nameOfFunction = util::FNameToString(&fn->Name);
		printf("Name Of Fct : %s\n", nameOfFunction.c_str());
#endif
		return Native::oProcessEvent(dis, fn, params);
	}

	static void hkPostRender(void* invocker, void* canvas) {
		//Native::K2_DrawBox(canvas, { 100, 300 }, { 100, 500 }, 15, { 255, 255,255,255 });
		//Native::K2_DrawLine(canvas, { 100, 300 }, { 300, 100 }, 100, { 63, 255, 51, 100 });
	}

	
}

#endif