#pragma once

#include "pch.h"
#include "Globals.h"
#include "ue4.h"
#include "upgunstructs.h"
#include "Native.h"
#include "guihelpers.h"
#include "guisections.h"
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
        Globals::width = width;
        Globals::height = height;
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
                D3D11_TEXTURE2D_DESC backBufferDesc = { 0 };
                pBackBuffer->GetDesc(&backBufferDesc);
                Globals::width = backBufferDesc.Width;
                Globals::height = backBufferDesc.Height;
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


        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));

        ImGui::Begin("##scene", nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);
        auto pDrawList = ImGui::GetCurrentWindow()->DrawList;
        auto& io = ImGui::GetIO();
        ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::SetWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);
        
        if (Globals::renderFOVCircle) {
            pDrawList->AddCircle(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2), Globals::AimbotFOV, ImColor(Globals::FOVCircleColor[0], Globals::FOVCircleColor[1], Globals::FOVCircleColor[2]), 0, 2);
        }

        if (Globals::showWatermark) {
            pDrawList->AddText(Globals::font, 18, { Globals::width / 2.55f, 30 }, ImColor{ 255, 0, 0 }, "github.com/Ramokprout/Upgunned");
        }

        if (Globals::showFPS) {
            pDrawList->AddText(Globals::font, 18, { Globals::width / 2.4f, 50 }, ImColor{ 0, 255, 0 }, std::format("FPS Counter: {}", static_cast<int>(ImGui::GetIO().Framerate)).c_str());
        }



        auto localPlayer = ue4::getLocalPlayer();
        if (localPlayer->PlayerController) {
            auto PlayerController = localPlayer->PlayerController;
            auto players = ue4::getPlayers();

            if (Globals::AimbotEnabled) {
                auto hwnd = GetForegroundWindow();
                DWORD Pid;
                GetWindowThreadProcessId(hwnd, &Pid);
                if (Globals::showMenu == false && GetAsyncKeyState(Globals::Aimbot_Key) && Pid == Globals::ProcessPid) {
                    FVector BonePos = { 0 };
                    auto closestVisiblePlayer = ue4::GetClosestPlayer(PlayerController, players, nullptr, true, Globals::AimbotFOV, Globals::ignoreMates);
                    if (closestVisiblePlayer) {
                        FVector2D BonePosW2S = { 0 };
                        ue4::GetBoneLocation(closestVisiblePlayer->Mesh, &BonePos, Globals::Aimbot_Pos);
                        if (Globals::Aimbot_Pos == UpGunBoneIds::HEAD) {
                            BonePos.Z += 5;
                        }
                        if (Native::ProjectWorldToScreen(localPlayer->PlayerController, &BonePos, &BonePosW2S, false)) {
                            ue4::AimAt(BonePosW2S);
                        }
                    }
                }
            }



        
          for (auto player : players) {
                if (ue4::IsLocalPlayer(player)) continue;
           //     if (Globals::ignoreMates && ) continue; bad idea, i'll make a TeamMate ESP instead
                auto distance = ue4::getDistance(PlayerController->Character, player) / 15;
                FVector Root = { 0 };
                ue4::GetBoneLocation(player->Mesh, &Root, UpGunBoneIds::ROOT);
                FVector RawRoot = Root;
                bool gotRawRootW2S = false;
                FVector2D RootPosScreenPos = { 0 };

                if (Globals::boxesESP || Globals::snapLines) {
                    gotRawRootW2S = Native::ProjectWorldToScreen(PlayerController, &RawRoot, &RootPosScreenPos, false);
                }
#ifdef _DEBUG
                if (Globals::bonesESP) {
                    auto socket_names = ue4::GetAllSocketNames(player->Mesh);
                    for (int i = 0; i < socket_names.Num(); i++) {
                        FVector BonePos = { 0 };
                        ue4::GetBoneLocation(player->Mesh, &BonePos, i);
                        FVector BonePosscren = {0};
                        if (Native::ProjectWorldToScreen(PlayerController, &BonePos, &BonePosscren, false)) {
                            pDrawList->AddText(ImVec2(BonePosscren.X, BonePosscren.Y), ImColor{0, 255, 0}, std::to_string(i).c_str());
                        }
                    }

                    Native::FMemoryFree(socket_names.Data);
                }
#endif



                if (Globals::boxesESP) {
                    FVector Head = { 0 };
                    ue4::GetBoneLocation(player->Mesh, &Head, UpGunBoneIds::HEAD);


                    Head.Z += 30;

                    Root.Y += -35;
                    Head.Y += 35;

                    FVector2D screenPosHead = { 0 };
                    FVector2D screenPosRoot = { 0 };
                    if (distance <= Globals::ESPMaxDistance) {
                        if (Native::ProjectWorldToScreen(PlayerController, &Head, &screenPosHead, false)
                            && Native::ProjectWorldToScreen(PlayerController, &Root, &screenPosRoot, false)) {
                            ImVec2 bottomLeft = { screenPosHead.X,screenPosRoot.Y };
                            ImVec2 topRight = { screenPosRoot.X, screenPosHead.Y };
                            ImColor color = { Globals::ESPColor[0], Globals::ESPColor[1], Globals::ESPColor[2] };
                            if (Globals::boxesESPVischeck && ue4::IsVisible(PlayerController, player)) {
                                color = { Globals::ESPVisibleColor[0], Globals::ESPVisibleColor[1], Globals::ESPVisibleColor[2] };
                            }

                            if (Globals::boxesESPMates && ue4::IsTeamMate(localPlayer->PlayerController->Character->PlayerState, player->PlayerState)) {
                                color = { Globals::ESPTeamMateColor[0], Globals::ESPTeamMateColor[1], Globals::ESPTeamMateColor[2] };
                            }

                            pDrawList->AddRect(bottomLeft, topRight, color);
                        }
                    }

                }

                if (Globals::snapLines) {
      
                    if (distance <= Globals::SnaplinesMaxDistance) {
                        if (gotRawRootW2S) {
                            ImColor color = { Globals::SnaplinesColor[0], Globals::SnaplinesColor[1], Globals::SnaplinesColor[2] };
                            if (Globals::snapLinesVischeck && ue4::IsVisible(PlayerController, player)) {
                                color = { Globals::SnaplinesVisibleColor[0], Globals::SnaplinesVisibleColor[1], Globals::SnaplinesVisibleColor[2] };
                            }
                            pDrawList->AddLine(ImVec2(Globals::width/2, Globals::height), ImVec2(RootPosScreenPos.X, RootPosScreenPos.Y), color);
                        }
                    }
                }
            }

            players.clear();
        }

    
        pDrawList->PushClipRectFullScreen();
        ImGui::End();
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor();

        if (Globals::showMenu)
        {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(9.000f, 15.000f));
            ImGui::SetNextWindowSize(ImVec2(800.000f, 500.000f), ImGuiCond_Once);
            ImGui::Begin("Upgunned", &Globals::showMenu, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize);

            bool isServer = ue4::IsServer();
            auto localPlayer = ue4::getLocalPlayer();
            auto character = localPlayer->PlayerController->Character;
            static float tempRepairForCustomTimeDilatation = 0;

            TabSelector::Render(isServer);

            /*
            tabs:
            0 = Host 
            1 = Debug
            2 = Visuals
            3 = Misc
            4 = Aimbot
            */

            switch (Globals::tab) {
            case GUIHelpers::GuiTabs::GuiTabs_Host:
                Host::Render(character);
                break;
            case GUIHelpers::GuiTabs::GuiTabs_Debug:
#ifdef _DEBUG
                debug::Render();

#else
                ImGui::Text("This menu is avaliable in debug mode only");
#endif
                break;
            case GUIHelpers::GuiTabs::GuiTabs_Visuals:
                visualMenu::Render();
                break;
            case GUIHelpers::GuiTabs::GuiTabs_Misc:
                miscMenu::Render();
                break;
            case GUIHelpers::GuiTabs::GuiTabs_Aimbot:
                aimbotMenu::Render();
                break;
            }

            ImGui::PopStyleVar(1);
            ImGui::End();
        }





        ImGui::EndFrame();
        ImGui::Render();

        Globals::pContext->OMSetRenderTargets(1, &Globals::mainRenderTargetView, NULL);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        return Native::oPresent(pSwapChain, SyncInterval, Flags);
    }
}