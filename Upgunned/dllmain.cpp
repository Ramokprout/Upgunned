// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "offsets.h"
#include "util.h"
#include "guirenderer.h"
#include "LocalPlayer.h"

DWORD WINAPI Main(HMODULE lpParam) {
    CreateConsole
    offsetsManager* offsetManager = new offsetsManager();
    offsetManager->Initialize();
    renderer::Initialize();
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  reason,
                       LPVOID lpReserved
                     )
{
    DisableThreadLibraryCalls(hModule);
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, nullptr);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

