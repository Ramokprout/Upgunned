#pragma once

#ifndef __GUIRENDERER__
#define __GUIRENDERER__
#include "pch.h"
#include "util.h"
#include "Globals.h"
#include "d3dhook.h"

namespace renderer {

    void Initialize()
    {
        auto featureLevel = D3D_FEATURE_LEVEL_11_0;
        DXGI_SWAP_CHAIN_DESC sd = { 0 };
        sd.BufferCount = 1;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
        HWND hwnd = FindWindowA("UnrealWindow", nullptr);
        if (!hwnd) {
            printf("No hwnd found\n");
        }
        sd.OutputWindow = hwnd;
        sd.SampleDesc.Count = 1;
        sd.Windowed = TRUE;

        if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, 0, 0, &featureLevel, 1, D3D11_SDK_VERSION, &sd, &Globals::swapChain, &Globals::pDevice, nullptr, &Globals::pContext)))
        {
            MessageBox(0, L"failed: dx11", L"Upgunned", MB_ICONERROR);
            return;
        }

 

        auto table = *reinterpret_cast<PVOID**>(Globals::swapChain);
        auto present = table[8];
        auto resize = table[13];

        Globals::pContext->Release();
        Globals::pDevice->Release();
        Globals::swapChain->Release();


        DETOUR_START
        DetourAttachE(present, d3dhook::hkPresent);
        DetourAttachE(resize, d3dhook::hkResize);
        DETOUR_END

        AddressToFunction(present, Native::oPresent);
        AddressToFunction(resize, Native::oResize);

    }
}

#endif