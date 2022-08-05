#pragma once
#ifndef __UTIL_H__
#define __UTIL_H__

#include "Native.h"
#include "upgunstructs.h"

static void Error(std::string error, bool bExit = false)
{
	MessageBoxA(nullptr, error.c_str(), "Error", MB_OK | MB_ICONERROR);
	printf(error.c_str());
	if (bExit)
		exit(0);
}


#define PRINT_PTR(ptr, name) \
			printf("%s ptr : %p\n", name, (void*)ptr);

#define CheckNullFatal(x, y) \
    if (!x)                  \
    {                        \
        Error(y, true);      \
    }

#define DETOUR_START \
	DetourTransactionBegin(); \
	DetourUpdateThread(GetCurrentThread());

#define DetourAttachE(Target, Detour) DetourAttach(&(void*&)Target, Detour);

#define DETOUR_END DetourTransactionCommit();

#define AddressToFunction(a, f) f = reinterpret_cast<decltype(f)>(a);

#ifdef DEBUGLOG
#define GETOFFSET(buffer, imagebase, a, f, name) \
	buffer = imagebase + a; \
	CheckNullFatal(buffer, name) \
	AddressToFunction(buffer, f) \
	PRINT_PTR(buffer, name)
#else
#define GETOFFSET(buffer, imagebase, a, f, name) \
	buffer = imagebase + a; \
	CheckNullFatal(buffer, name) \
	AddressToFunction(buffer, f) \
		std::cout << termcolor::bright_green << "Found " << name << " pointer" << termcolor::reset << std::endl;
#endif



#define ReadPointer(base, offset) (*(PVOID *)(((PBYTE)base + offset)))

#define CreateConsole \
	AllocConsole(); \
	FILE* File; \
	freopen_s(&File, "CONOUT$", "w", stdout);

#endif
