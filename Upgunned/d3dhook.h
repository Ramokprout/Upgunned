#pragma once

#include "pch.h"
#include "Globals.h"
#include "ue4.h"
#include "upgunstructs.h"
#include "Native.h"

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
Globals::font = io.Fonts->AddFontFromFileTTF("C:/Users/ramok/Downloads/Fonts/arial.ttf", 15.990f);\


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

    void resetEveryValues() {
        Globals::WalkSpeedMultiplier->enabled = false;
        Globals::WalkSpeedMultiplier->Multiplier = 1;
        Globals::WalkSpeedMultiplier->OriginalValue = 0.f;
        Globals::HealthMultiplier->enabled = false;
        Globals::HealthMultiplier->Multiplier = 1;
        Globals::HealthMultiplier->OriginalValue = 0.f;
        Globals::noSpread->enabled = false;
        Globals::noSpread->enabledCheckbox = false;
        Globals::noSpread->Multiplier = 1;
        Globals::noSpread->OriginalValue = 0.f;
        Globals::RifleFireRateMultiplier->enabled = false;
        Globals::RifleFireRateMultiplier->Multiplier = 1;
        Globals::RifleFireRateMultiplier->OriginalValue = 0.f;
        Globals::BulletSpeedMultiplier->enabled = false;
        Globals::BulletSpeedMultiplier->Multiplier = 1;
        Globals::BulletSpeedMultiplier->OriginalValue = 0.f;
        Globals::RifleMagazine = 20.0f;
        Globals::RifleCriticalHitChanceMultiplier->enabled = false;
        Globals::RifleCriticalHitChanceMultiplier->Multiplier = 1;
        Globals::RifleCriticalHitChanceMultiplier->OriginalValue = 0.f;
        Globals::GWorldTrigger = UpgunnedEngine::GetWorld();
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
           // pDrawList->AddText(, , );
            pDrawList->AddText(Globals::font, 18, { Globals::width / 2.55f, 30 }, ImColor{ 255, 0, 0 }, "github.com/Ramokprout/Upgunned");
        }

        auto localPlayer = ue4::getLocalPlayer();
        if (localPlayer->PlayerController) {
            auto PlayerController = localPlayer->PlayerController;
            auto players = ue4::getPlayers();
        
          for (auto player : players) {
                if (ue4::IsLocalPlayer(player)) continue;
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
                  //  Root->Z -= 5;

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
                            pDrawList->AddRect(bottomLeft, topRight, color);
                        }
                    }

                }

                if (Globals::snapLines) {
      
                    if (distance <= Globals::SnaplinesMaxDistance) {
                        if (gotRawRootW2S) {
                            //        Native::K2_DrawLine(canvas, FVector2D{ Globals::width / 2, Globals::height }, playerDest, 1.5f, { 255, 0, 0, 1 });
                            ImColor color = { Globals::SnaplinesColor[0], Globals::SnaplinesColor[1], Globals::SnaplinesColor[2] };
                            if (Globals::snapLinesVischeck && ue4::IsVisible(PlayerController, player)) {
                                //Globals::
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
            ImGui::SetNextWindowSize(ImVec2(750.000f, 450.000f), ImGuiCond_Once);
            ImGui::Begin("Upgunned", &Globals::showMenu);

            bool isServer = ue4::IsServer();
            auto localPlayer = ue4::getLocalPlayer();

            if (isServer) {
                if (ImGui::Button("Host", ImVec2(125.000f, 30.000f)))
                {
                    Globals::tab = 0;
                }
                ImGui::SameLine();
            }
            else if (Globals::tab == 0) {
                Globals::tab++;
            }
#ifdef _DEBUG
            if (ImGui::Button("Debug", ImVec2(125.000f, 30.000f)))
            {
                Globals::tab = 1;
       
            }         
            ImGui::SameLine();
#endif
            if (ImGui::Button("Visuals", ImVec2(125.000f, 30.000f)))
            {
                Globals::tab = 2;
            }   
            ImGui::SameLine();
            if (ImGui::Button("Exploits", ImVec2(125.000f, 30.000f)))
            {
                Globals::tab = 3;
            }
            auto world = UpgunnedEngine::GetWorld();
            if (Globals::tab == 0) {

                auto PlayerController = localPlayer->PlayerController;
                auto character = PlayerController->Character;
                ImGui::SetNextItemWidth(200.000f);
                ImVec2 size;
                size = ImGui::CalcTextSize("Pawn CustomTimeDilatation");
                ImGui::SliderFloat("Pawn CustomTimeDilatation", &character->CustomTimeDilatation, 0.f, 15.f);
                ImGui::SameLine();
                ImGui::SetCursorPos({ size.x + 225, ImGui::GetCursorPosY()});
                if (ImGui::Button("Reset##first")) {
                    character->CustomTimeDilatation = 1;
                }
                size = ImGui::CalcTextSize("World CustomTimeDilatation");
                ImGui::SetNextItemWidth(200.000f);
                ImGui::SliderFloat("World CustomTimeDilatation", &world->PersistentLevel->WorldSettings->TimeDilatation, 0.f, 15.f);
                ImGui::SameLine();
                ImGui::SetCursorPos({ size.x + 223, ImGui::GetCursorPosY() });
                if (ImGui::Button("Reset##second")) {
                    world->PersistentLevel->WorldSettings->TimeDilatation = 1;
                }

                if (Globals::GWorldTrigger != world) {
                    d3dhook::resetEveryValues();
                }

                if (ImGui::CollapsingHeader("Weapon"))
                {
                    auto weaponAttributeSet = localPlayer->PlayerController->Character->PlayerState->WeaponAttributeSet;
                    if (ImGui::Checkbox("No Spread", &Globals::noSpread->enabledCheckbox)) {
                        if (Globals::noSpread->enabledCheckbox) {
                            if (!Globals::noSpread->enabled) {
                                Globals::noSpread->OriginalValue = weaponAttributeSet->RifleDispersion.CurrentValue;
                                Globals::noSpread->Multiplier = 0.001f;
                                Globals::noSpread->enabled = true;
                            }
                            weaponAttributeSet->RifleDispersion.CurrentValue = weaponAttributeSet->RifleDispersion.CurrentValue * Globals::noSpread->Multiplier;
                        }
                        else {
                            Globals::noSpread->enabled = false;
                            Globals::noSpread->OriginalValue = 0;
                            Globals::noSpread->Multiplier = 1;
                        }

                    }

                    ImGui::SetNextItemWidth(150.000f);
                    if (ImGui::SliderFloat("Rifle Fire Rate Multiplier", &Globals::RifleFireRateMultiplier->Multiplier, 0.01f, 50.f)) {
                        if (!Globals::RifleFireRateMultiplier->enabled) {
                            Globals::RifleFireRateMultiplier->OriginalValue = weaponAttributeSet->RifleFireRate.CurrentValue;
                            Globals::RifleFireRateMultiplier->enabled = true;
                        }

                        weaponAttributeSet->RifleFireRate.CurrentValue = Globals::RifleFireRateMultiplier->OriginalValue * Globals::RifleFireRateMultiplier->Multiplier;
                    }
                    ImGui::SetNextItemWidth(150.000f);
                    if (ImGui::SliderFloat("Bullet Speed Multiplier", &Globals::BulletSpeedMultiplier->Multiplier, 0.01f, 25.f)) {
                        if (!Globals::BulletSpeedMultiplier->enabled) {
                            Globals::BulletSpeedMultiplier->OriginalValue = weaponAttributeSet->RifleBulletSpeed.CurrentValue;
                            Globals::BulletSpeedMultiplier->enabled = true;
                        }

                        weaponAttributeSet->RifleBulletSpeed.CurrentValue = Globals::BulletSpeedMultiplier->OriginalValue * Globals::BulletSpeedMultiplier->Multiplier;
                    }
                    ImGui::SetNextItemWidth(150.000f);
                    if (ImGui::SliderInt("Rifle Magazine", &Globals::RifleMagazine, 5, 100))
                    {
                        weaponAttributeSet->RifleMagazine.CurrentValue = (float)Globals::RifleMagazine;
                    }
                    ImGui::SetNextItemWidth(150.000f);
                    if (ImGui::SliderFloat("Bullet Critical Hit Chance Multiplier", &Globals::RifleCriticalHitChanceMultiplier->Multiplier, 0.01f, 150.f)) {
                        if (!Globals::RifleCriticalHitChanceMultiplier->enabled) {
                            Globals::RifleCriticalHitChanceMultiplier->OriginalValue = weaponAttributeSet->RifleCriticalHitChance.CurrentValue;
                            Globals::RifleCriticalHitChanceMultiplier->enabled = true;
                        }
                        weaponAttributeSet->RifleCriticalHitChance.CurrentValue = Globals::RifleCriticalHitChanceMultiplier->OriginalValue * Globals::RifleCriticalHitChanceMultiplier->Multiplier;
                    }
                    ImGui::SetNextItemWidth(150.000f);
                    ImGui::SliderFloat("Bullet Damage Multiplier", &weaponAttributeSet->DamageBaseMultiplier.CurrentValue, 0.01f, 150.f);
                    if (ImGui::Button("Reset Values##WeaponResetValues")) {

                        weaponAttributeSet->DamageBaseMultiplier.CurrentValue = weaponAttributeSet->DamageBaseMultiplier.BaseValue;
                        weaponAttributeSet->RifleMagazine.CurrentValue = weaponAttributeSet->RifleMagazine.BaseValue;
                        weaponAttributeSet->RifleCriticalHitChance.CurrentValue = Globals::RifleCriticalHitChanceMultiplier->OriginalValue;
                        weaponAttributeSet->RifleBulletSpeed.CurrentValue = Globals::BulletSpeedMultiplier->OriginalValue;
                        weaponAttributeSet->RifleFireRate.CurrentValue = Globals::RifleFireRateMultiplier->OriginalValue;
                        weaponAttributeSet->RifleDispersion.CurrentValue = Globals::noSpread->OriginalValue;

                        Globals::noSpread->enabled = false;
                        Globals::noSpread->enabledCheckbox = false;
                        Globals::noSpread->Multiplier = 1;
                        Globals::noSpread->OriginalValue = 0.f;
                        Globals::RifleFireRateMultiplier->enabled = false;
                        Globals::RifleFireRateMultiplier->Multiplier = 1;
                        Globals::RifleFireRateMultiplier->OriginalValue = 0.f;
                        Globals::BulletSpeedMultiplier->enabled = false;
                        Globals::BulletSpeedMultiplier->Multiplier = 1;
                        Globals::BulletSpeedMultiplier->OriginalValue = 0.f;
                        Globals::RifleMagazine = 20.0f;
                        Globals::RifleCriticalHitChanceMultiplier->enabled = false;
                        Globals::RifleCriticalHitChanceMultiplier->Multiplier = 1;
                        Globals::RifleCriticalHitChanceMultiplier->OriginalValue = 0.f;


                    }
                }

                if (ImGui::CollapsingHeader("Player")) {
                    auto LocalPlayer = ue4::getLocalPlayer();
                    auto BaseCharacterAttributeSet = LocalPlayer->PlayerController->Character->PlayerState->BaseCharacterAttributeSet;
                    ImGui::SetNextItemWidth(150.000f);
                    if (ImGui::SliderFloat("Health Multiplier", &Globals::HealthMultiplier->Multiplier, 0.5f, 15.f)) {
                        if (!Globals::HealthMultiplier->enabled) {
                            Globals::HealthMultiplier->OriginalValue = BaseCharacterAttributeSet->MaxHealth.CurrentValue;
                            Globals::HealthMultiplier->enabled = true;
                        }

                        BaseCharacterAttributeSet->Health.CurrentValue = BaseCharacterAttributeSet->MaxHealth.CurrentValue * Globals::HealthMultiplier->Multiplier;
                    }
                    ImGui::SetNextItemWidth(150.000f);
                    if (ImGui::SliderFloat("WalkSpeed Multiplier", &Globals::WalkSpeedMultiplier->Multiplier, 0.5f, 4.f)) {
                        if (!Globals::WalkSpeedMultiplier->enabled) {
                            Globals::WalkSpeedMultiplier->OriginalValue = BaseCharacterAttributeSet->WalkSpeed.CurrentValue;
                            Globals::WalkSpeedMultiplier->enabled = true;
                        }

                        BaseCharacterAttributeSet->WalkSpeed.CurrentValue = BaseCharacterAttributeSet->WalkSpeed.CurrentValue * Globals::WalkSpeedMultiplier->Multiplier;
                    }

                    if (ImGui::Button("Reset Values##PlayerResetValues")) {

                        BaseCharacterAttributeSet->WalkSpeed.CurrentValue = Globals::WalkSpeedMultiplier->OriginalValue;
                        BaseCharacterAttributeSet->Health.CurrentValue = Globals::HealthMultiplier->OriginalValue;
                        Globals::WalkSpeedMultiplier->enabled = false;
                        Globals::WalkSpeedMultiplier->Multiplier = 1;
                        Globals::WalkSpeedMultiplier->OriginalValue = 0.f;
                        Globals::HealthMultiplier->enabled = false;
                        Globals::HealthMultiplier->Multiplier = 1;
                        Globals::HealthMultiplier->OriginalValue = 0.f;
                    }

                }


            }
            else if (Globals::tab == 1) {
#ifdef _DEBUG
                if (ImGui::Button("Print Addresses")) {
                    auto LocalPlayer = ue4::getLocalPlayer();
                    PRINT_PTR(LocalPlayer, "LocalPlayer");
                    if (LocalPlayer->PlayerController) {
                        PRINT_PTR(LocalPlayer->PlayerController, "PlayerController");
                    }
    
                }


          //     ImGui::SliderInt("X modify#1", &Globals::XMODIFDEBUG, -100, 100);
          //    ImGui::SliderInt("Y modify#1", &Globals::YMODIFDEBUG, -100, 100);
                ////ImGui::SliderInt("Z modify#1", &Globals::ZMODIFDEBUG, -100, 100);            
                ////
                ////ImGui::SliderInt("X modify 2#2", &Globals::XMODIFDEBUG2, -100, 100);
                ////ImGui::SliderInt("Y modify 2#2", &Globals::YMODIFDEBUG2, -100, 100);
                ////ImGui::SliderInt("Z modify 2#2", &Globals::ZMODIFDEBUG2, -100, 100);
                if (ImGui::Button("AimAT ClosestPlayer")) {
                    auto players = ue4::getPlayers();
                    FVector HeadPos = { 0 };
                    auto closestVisiblePlayer = ue4::GetClosestPlayer(players, &HeadPos, true);
                    if (!closestVisiblePlayer) {
                        printf("Not Found");
                   }

                    PRINT_PTR(closestVisiblePlayer->Mesh, "ClosestVisiblePlayer mesh");
                //    ue4::AimAt(ue4::getLocalPlayer()->PlayerController, HeadPos);
                }
#else
            ImGui::Text("This menu is avaliable in debug mode only");
#endif
            }
            else if(Globals::tab == 2) {
                if (ImGui::SliderInt("FOV", &Globals::FOV, 30, 160)) {
                    auto LocalPlayer = ue4::getLocalPlayer();
                    auto cam = LocalPlayer->PlayerController->Character->Camera;
                    cam->FieldOfView = (float)Globals::FOV;
                }

                ImGui::Checkbox("ESP", &Globals::boxesESP);
                ImGui::Checkbox("ESP VisCheck", &Globals::boxesESPVischeck);
                ImGui::Checkbox("Bones ESP", &Globals::bonesESP);
                ImGui::Checkbox("Snaplines", &Globals::snapLines);
                ImGui::Checkbox("Snaplines VisCheck", &Globals::snapLinesVischeck);
                ImGui::Checkbox("Render Aimbot FOV", &Globals::renderFOVCircle);
                ImGui::Checkbox("Show Watermark", &Globals::showWatermark);

                ImGui::SliderFloat("ESP Max Distance##ESPDIST", &Globals::ESPMaxDistance, 0, 1000);
                ImGui::SliderFloat("Snaplines Max Distance##SNAPDIST", &Globals::SnaplinesMaxDistance, 0, 1000);
                ImGui::SliderFloat("Aimbot FOV##SNAPDIST", &Globals::AimbotFOV, 10, 700);
              
                ImGui::ColorEdit3("FOV Circle Color", Globals::FOVCircleColor, ImGuiColorEditFlags_NoInputs);
                ImGui::ColorEdit3("Snaplines Color", Globals::SnaplinesColor, ImGuiColorEditFlags_NoInputs);
                ImGui::ColorEdit3("Snapline Visible Color", Globals::SnaplinesVisibleColor, ImGuiColorEditFlags_NoInputs);
                ImGui::ColorEdit3("ESP Color", Globals::ESPColor, ImGuiColorEditFlags_NoInputs);
                ImGui::ColorEdit3("ESP Visible Color", Globals::ESPVisibleColor, ImGuiColorEditFlags_NoInputs);
            }
            else if (Globals::tab == 3) {
                if (ImGui::Button("Build Console")) {
                    ue4::BuildConsole();
                    ue4::BuildCheatManager();
#ifndef DEBUGLOG
                    std::cout << termcolor::bright_green
                        << "Built UConsole and CheatManager successfully"
                        << termcolor::reset
                        << std::endl;
#endif
                }


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