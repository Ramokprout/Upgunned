// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"


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
Globals::font = io.Fonts->AddFontFromFileTTF("C:/Windows/Fonts/segoeui.ttf", 14.990f);\

#endif //PCH_H
