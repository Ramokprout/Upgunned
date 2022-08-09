#pragma once
#ifndef __OFFSETS__
#define __OFFSETS__

#include "Native.h"
#include "hooks.h"
#include "util.h"

#include "Globals.h"
#include "engine.h"

class offsetsManager
{
public :
	static const int PROCESSEVENT = 0x10B0CC0;
	static const int GOBJECT = 0x44A25D8;
	static const int GENGINE = 0x45D8280;
	static const int GETBONEMATRIX = 0x246A380;
	static const int GETPLAYERVIEWPOINT = 0x2779E40;
	static const int COMPONENTTOWORLD = 0x2AB6BC0;
	static const int STATICFINDOBJECT = 0x10D3880;
	static const int Malloc = 0xDF5A20;
	static const int Realloc = 0xDF73C0;
	static const int Free = 0xDEA350;
	static const int CurlEasySetOpt = 0x3194770;
	static const int PostRender = 0x253E960;
	static const int K2DrawLine = 0x29335D0;
	static const int K2DrawBox = 0x2933510;
	static const int GetObjectName = 0x25D1770;
	static const int StaticConstructObject_internal = 0x10D2A10;
	static const int SpawnObject = 0x2546AD0;
	static const int FNamePool = 0x448A040;
	static const int GetNameStringByIndex = 0x1054B70;
	static const int FNAMETOSTRING = 0xEE3DF0;
	static const int IsServer = 0x2679E00;
	static const int K2DrawText = 0x2933AF0;
	static const int ProjectWorldToScreen = 0x2540990;
	//static const int GWORLD = 0x45DBB40;
	//	static const int K2_GetPawn = 0x8A7D80;
//	static const int FOV = 0x2776D20;
//	static const int GetFovAngle = 0x27782C0;
#ifdef AESHOOK
	static const int DecryptData = 0xE69FE0;
#endif

	inline void Initialize() {
				uintptr_t Address = 0;
				uintptr_t ImageBase = (uintptr_t)GetModuleHandle(0);

				GETOFFSET(Address, ImageBase, this->PROCESSEVENT, Native::oProcessEvent, "ProcessEvent");
				GETOFFSET(Address, ImageBase, this->PostRender, Native::oPostRender, "PostRender")
					GETOFFSET(Address, ImageBase, this->STATICFINDOBJECT, Native::StaticFindObject, "StaticFindObject")
					GETOFFSET(Address, ImageBase, this->StaticConstructObject_internal, Native::StaticConstructObject_internal, "StaticConstructObject_internal")
					GETOFFSET(Address, ImageBase, this->SpawnObject, Native::SpawnObject, "SpawnObject")
					GETOFFSET(Address, ImageBase, this->FNAMETOSTRING, Native::FNameToString, "FNameToString")
					GETOFFSET(Address, ImageBase, this->K2DrawLine, Native::K2_DrawLine, "K2_DrawLine")
					GETOFFSET(Address, ImageBase, this->K2DrawBox, Native::K2_DrawBox, "K2_DrawBox")
					GETOFFSET(Address, ImageBase, this->K2DrawText, Native::K2_DrawText, "K2_DrawText")
					//			GETOFFSET(Address, ImageBase, this->K2_GetPawn, Native::K2_GetPawn, "K2_GetPawn")
						//		GETOFFSET(Address, ImageBase, this->GWORLD, Native::UWorld, "UWorld Proxy")
					GETOFFSET(Address, ImageBase, this->GOBJECT, Native::GObjects, "GObject")
					GETOFFSET(Address, ImageBase, this->GENGINE, Native::GEngine, "GEngine Proxy")
					GETOFFSET(Address, ImageBase, this->IsServer, Native::IsServer, "IsServer")
					GETOFFSET(Address, ImageBase, this->GETBONEMATRIX, Native::GetBoneMatrix, "GetBoneMatrix")
					GETOFFSET(Address, ImageBase, this->ProjectWorldToScreen, Native::ProjectWorldToScreen, "ProjectWorldToScreen")
					GETOFFSET(Address, ImageBase, this->Free, Native::FMemoryFree, "FMemoryFree")
#ifdef AESHOOK
					GETOFFSET(Address, ImageBase, this->DecryptData, Native::DecryptData, "DecryptData")
#endif
					//		GETOFFSET(Address, ImageBase, this->GetFovAngle, Native::GetFovAngle, "GetFovAngle")
							//GETOFFSET(Address, ImageBase, this->FOV, Native::FOV, "GetFovAngle")

					DETOUR_START
					DetourAttachE(Native::oProcessEvent, hooks::hkProcessEvent)
#ifndef DEBUGLOG
					std::cout << termcolor::bright_green
					<< "Hooked ProcessEvent successfully"
					<< termcolor::reset
					<< std::endl;
#endif
/*				DetourAttachE(Native::oPostRender, hooks::hkPostRender)
#ifndef DEBUGLOG
					std::cout << termcolor::bright_green
					<< "Hooked PostRender successfully"
					<< termcolor::reset
					<< std::endl;
#endif*/
#ifdef AESHOOK

				DetourAttachE(Native::DecryptData, hooks::hkDecryptData)
#ifndef DEBUGLOG
					std::cout << termcolor::bright_green
					<< "Hooked DecryptData successfully"
					<< termcolor::reset
					<< std::endl;
#endif
#endif
				DETOUR_END

					Globals::GWorldTrigger = UpgunnedEngine::GetWorld();
	}
};


#endif
