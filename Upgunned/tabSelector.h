#pragma once

#include "pch.h"
#include "Globals.h"

namespace TabSelector {
	void Render(bool isServer) {
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

        if (ImGui::Button("Aimbot", ImVec2(125, 30))) {
            Globals::tab = 4;
        }
        ImGui::SameLine();

        if (ImGui::Button("Misc", ImVec2(125.000f, 30.000f)))
        {
            Globals::tab = 3;
        }

        ImGui::Separator();
	}
}