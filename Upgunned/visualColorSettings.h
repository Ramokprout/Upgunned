#pragma once

#include "Globals.h"
#include "pch.h"

namespace visualColorSettings {
	void Render() {
        ImGui::ColorEdit3("FOV Circle Color", Globals::FOVCircleColor, ImGuiColorEditFlags_NoInputs);
        ImGui::ColorEdit3("Snaplines Color", Globals::SnaplinesColor, ImGuiColorEditFlags_NoInputs);
        ImGui::ColorEdit3("Snapline Visible Color", Globals::SnaplinesVisibleColor, ImGuiColorEditFlags_NoInputs);
        ImGui::ColorEdit3("ESP Color", Globals::ESPColor, ImGuiColorEditFlags_NoInputs);
        ImGui::ColorEdit3("ESP Visible Color", Globals::ESPVisibleColor, ImGuiColorEditFlags_NoInputs);
        if (ue4::IsPlayingMME()) {
            ImGui::ColorEdit3("ESP Teammate Color", Globals::ESPTeamMateColor, ImGuiColorEditFlags_NoInputs);
        }
	}
}