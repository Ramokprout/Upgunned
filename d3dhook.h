#pragma once

#include "pch.h"
#include "Globals.h"
#include "ue4.h"
#include "guirenderer.h"
#include "LocalPlayer.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


#define INITSTYLE \
auto& Style = ImGui::GetStyle();\
Style.WindowPadding = ImVec2(9.000f, 15.000f);\
Style.WindowTitleAlign = ImVec2(0.510f, 0.540f);\
Style.FramePadding = ImVec2(5.000f, 4.000f);\
Style.ItemInnerSpacing = ImVec2(6.000f, 3.000f);\
Style.ScrollbarSize = 15.000f;\
Style.GrabMinSize = 11.000f;\
Style.ButtonTextAlign = ImVec2(0.490f, 0.500f);\
Style.Colors[ImGuiCol_Text] = ImVec4(0.920f, 0.920f, 0.920f, 1.000f);\
Style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.440f, 0.440f, 0.440f, 1.000f);\
Style.Colors[ImGuiCol_WindowBg] = ImVec4(0.012f, 0.012f, 0.012f, 1.000f);\
Style.Colors[ImGuiCol_PopupBg] = ImVec4(0.080f, 0.080f, 0.080f, 0.940f);\
Style.Colors[ImGuiCol_Border] = ImVec4(0.510f, 0.360f, 0.150f, 1.000f);\
Style.Colors[ImGuiCol_FrameBg] = ImVec4(0.110f, 0.110f, 0.110f, 1.000f);\
Style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.510f, 0.360f, 0.150f, 1.000f);\
Style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.780f, 0.550f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_TitleBg] = ImVec4(0.510f, 0.360f, 0.150f, 1.000f);\
Style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.000f, 0.000f, 0.000f, 0.510f);\
Style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.110f, 0.110f, 0.110f, 1.000f);\
Style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.060f, 0.060f, 0.060f, 0.530f);\
Style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.210f, 0.210f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.470f, 0.470f, 0.470f, 1.000f);\
Style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.810f, 0.830f, 0.810f, 1.000f);\
Style.Colors[ImGuiCol_CheckMark] = ImVec4(1.000f, 0.590f, 0.000f, 1.000f);\
Style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_Button] = ImVec4(0.510f, 0.360f, 0.150f, 1.000f);\
Style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.780f, 0.550f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_Header] = ImVec4(0.510f, 0.360f, 0.150f, 1.000f);\
Style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.930f, 0.650f, 0.140f, 1.000f);\
Style.Colors[ImGuiCol_Separator] = ImVec4(0.210f, 0.210f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.780f, 0.550f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.210f, 0.210f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.780f, 0.550f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_Tab] = ImVec4(0.510f, 0.360f, 0.150f, 1.000f);\
Style.Colors[ImGuiCol_TabHovered] = ImVec4(0.910f, 0.640f, 0.130f, 1.000f);\
Style.Colors[ImGuiCol_TabActive] = ImVec4(0.780f, 0.550f, 0.210f, 1.000f);\
Style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.070f, 0.100f, 0.150f, 0.970f);\
Style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.140f, 0.260f, 0.420f, 1.000f);\
Style.Colors[ImGuiCol_PlotLines] = ImVec4(0.610f, 0.610f, 0.610f, 1.000f);\
Style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.000f, 0.600f, 0.000f, 1.000f);\
Style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.000f, 1.000f, 0.000f, 0.900f);\
Style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.260f, 0.590f, 0.980f, 1.000f);\
Style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 1.000f, 1.000f, 0.700f);\
Style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.800f, 0.800f, 0.800f, 0.200f);\
Style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.800f, 0.800f, 0.800f, 0.350f);\
io.Fonts->AddFontFromFileTTF("C:/Users/ramok/Downloads/Fonts/arial.ttf", 15.990f);\

namespace d3dhook {


    static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if (uMsg == WM_KEYUP && wParam == VK_INSERT)
        {

            Globals::showMenu = !Globals::showMenu;
            ImGui::GetIO().MouseDrawCursor = Globals::showMenu;
        }

        if (Globals::showMenu)
        {
            ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
            return TRUE;
        }

        return CallWindowProc(Globals::oWndProc, hWnd, uMsg, wParam, lParam);
    }

    static HRESULT hkResize(IDXGISwapChain* swapChain, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags)
    {
        if (Globals::mainRenderTargetView)
        {
            Globals::pContext->OMSetRenderTargets(0, 0, 0);
            Globals::mainRenderTargetView->Release();
        }

        HRESULT hr = Native::oResize(swapChain, bufferCount, width, height, newFormat, swapChainFlags);

        ID3D11Texture2D* pBuffer;
        swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer);

        Globals::pDevice->CreateRenderTargetView(pBuffer, NULL, &Globals::mainRenderTargetView);

        pBuffer->Release();

        Globals::pContext->OMSetRenderTargets(1, &Globals::mainRenderTargetView, NULL);

        D3D11_VIEWPORT vp;
        vp.Width = width;
        vp.Height = height;
        vp.MinDepth = 0.0f;
        vp.MaxDepth = 1.0f;
        vp.TopLeftX = 0;
        vp.TopLeftY = 0;
        Globals::pContext->RSSetViewports(1, &vp);
        return hr;
    }



    static HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
    {
        if (!Globals::init)
        {
            if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&Globals::pDevice)))
            {
                Globals::pDevice->GetImmediateContext(&Globals::pContext);
                DXGI_SWAP_CHAIN_DESC sd;
                pSwapChain->GetDesc(&sd);
                Globals::window = sd.OutputWindow;
                ID3D11Texture2D* pBackBuffer;
                pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
                Globals::pDevice->CreateRenderTargetView(pBackBuffer, NULL, &Globals::mainRenderTargetView);
                pBackBuffer->Release();
                Globals::oWndProc = (WNDPROC)SetWindowLongPtr(Globals::window, GWLP_WNDPROC, (LONG_PTR)d3dhook::WndProc);
                ImGui::CreateContext();
                ImGuiIO& io = ImGui::GetIO();
                io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
                ImGui_ImplWin32_Init(Globals::window);
                ImGui_ImplDX11_Init(Globals::pDevice, Globals::pContext);
                INITSTYLE
                Globals::init = true;
            }

            else
                return Native::oPresent(pSwapChain, SyncInterval, Flags);
        }

        if (Globals::showMenu)
        {
            ImGui_ImplDX11_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();

            ImGui::SetWindowSize(ImVec2(700.000f, 450.000f), ImGuiCond_Once);
            ImGui::Begin("Upgunned", &Globals::showMenu, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize);
            
            auto uwProxy = (UWorldProxy*)Native::UWorld;

            bool isServer = ue4::IsServer();
            
           // if (!IsBadReadPtr(&isServer, sizeof(bool)) && !isServer) {
            if (isServer) {
                if (ImGui::Button("Host", ImVec2(125.000f, 30.000f)))
                {
                    Globals::tab = 0;
                }
            }
            else if (Globals::tab == 0) {
                Globals::tab++;
            }


         //   if (!isServer && Globals::tab == 0) Globals::tab + 1;

            ImGui::SameLine();

            if (ImGui::Button("Debug", ImVec2(125.000f, 30.000f)))
            {
                Globals::tab = 1;
            }

 

            if (Globals::tab == 0) {
                if (ImGui::Button("print time dilatation")) {
                    auto PlayerController = LocalPlayerWrapper::getController(Globals::LocalPlayer);
                    auto character = (Character*)LocalPlayerWrapper::getPawn(PlayerController);
                    printf("CustomTimeDilatation : %f\n", character->CustomTimeDilatation);
                }
            }
            else if (Globals::tab == 1) {
                if (ImGui::Button("Display Location"))
                {
                    auto Controller = LocalPlayerWrapper::getController(Globals::LocalPlayer);
                    auto Pawn = LocalPlayerWrapper::getPawn(Controller);
                    auto Location = ue4::K2_GetActorLocation(Pawn);

                    printf("Location X : %f\n", Location.X);
                    printf("Location Y : %f\n", Location.Y);
                    printf("Location Z : %f\n", Location.Z);
                }

                if (ImGui::Button("Build Console")) {
                    ue4::BuildConsole();
                    ue4::BuildCheatManager();
                    printf("Console initialized successfully!\n");
                }

                if (ImGui::Button("Print Role")) {
               //     printf("Is Server : %d\n", ue4::IsServer());
                }

                if (ImGui::Button("Try reget LocalPlayer")) {
                    auto OwningGameInstance = ReadPointer(uwProxy->World, offsetsManager::OwningGameInstance);
                    auto LocalPlayers = (void*)ReadPointer(OwningGameInstance, offsetsManager::LocalPlayers);
                    auto LocalPlayer = (void*)ReadPointer(LocalPlayers, 0x0);
                    if (!LocalPlayer || IsBadReadPtr(LocalPlayer, sizeof(LocalPlayer))) {
                        printf("No LocalPlayer\n");
                    }
                    else {
                        printf("New LocalPlayer : %p\n", LocalPlayer);
                        Globals::LocalPlayer = (PVOID*)LocalPlayer;
                    }
                }

                if (ImGui::Button("Print Uworld full name")) {
                    auto world = (UObject*)uwProxy->World;
                    wprintf(L"UWorld name : %s\n",world->GetFullName().c_str());
                }

                if (ImGui::Button("Print Actors Number")) {
                    
    /*                auto PersistentLevel = (void*)ReadPointer(Native::UWorld, 0x30);
                    PRINT_PTR(PersistentLevel, "PersistentLevel");
                    auto ActorCluster = (void*)ReadPointer(PersistentLevel, 0xD8);
                    PRINT_PTR(ActorCluster, "ActorCluster");
                    
                    //int a = (int)ReadPointerRaw((PVOID*)PersistentLevel + 0xA0);
                    PVOID* AActors = (PVOID*)ReadPointerRaw((PVOID*)ActorCluster + 0x28);
                    PRINT_PTR(AActors, "AActors");*/
              //      int ActorCount = (int)ReadPointerRaw((PVOID*)AActors + sizeof(int));

   /*                 for (int i = 0; i < a; i++) {
                        auto actor = (PVOID*)ReadPointerRaw((PVOID*)AActors + i * 0x8);

                    }*/

            //        printf("Num : %d\n", ActorCount);
                }

                if (ImGui::SliderInt("FOV", &Globals::FOV, 30, 160)) {
                    auto PlayerController = LocalPlayerWrapper::getController(Globals::LocalPlayer);
                    PRINT_PTR(PlayerController, "PlayerController")
                    auto CameraManager = LocalPlayerWrapper::getPlayerCameraManager(PlayerController);
                    PRINT_PTR(CameraManager, "CameraManager")
                    auto FOV = ue4::GetFovAngle(CameraManager);
                    printf("FOV : %f\n", FOV);
                    printf("Global FOV : %d\n", Globals::FOV);
                    ue4::FOV(PlayerController, FOV);
                  //  Globals::FOV = (int)FOV;
                }
            }



            ImGui::End();
            Globals::pContext->OMSetRenderTargets(1, &Globals::mainRenderTargetView, NULL);
            ImGui::Render();


            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        }

        return Native::oPresent(pSwapChain, SyncInterval, Flags);
    }
}