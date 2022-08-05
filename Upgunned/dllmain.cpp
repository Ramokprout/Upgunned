// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "offsets.h"
#include "util.h"
#include "guirenderer.h"

DWORD WINAPI Main(HMODULE lpParam) {
    CreateConsole
#ifndef DEBUGLOG
        std::cout 
        << termcolor::bright_green
        << "Welcome to UpGunned !"
        << std::endl
        << "This is an open-source cheat made by Ramok"
        << std::endl 
        << termcolor::bright_grey
        << "Github Repository : "
        << termcolor::bright_green
        << "https://github.com/Ramokprout/Upgunned"
        << termcolor::reset
        << std::endl
        << termcolor::bright_red
        << "If you bought this you got scammed !"
        << std::endl
        << termcolor::bright_blue
        << "Thanks for using my programs"
        << std::endl
        << termcolor::reset;
#endif

    Globals::noSpread = new ValueMultiplier();
    Globals::RifleFireRateMultiplier = new ValueMultiplier();
    Globals::BulletSpeedMultiplier = new ValueMultiplier();
    Globals::RifleCriticalHitChanceMultiplier = new ValueMultiplier();

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

