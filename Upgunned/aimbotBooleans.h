#pragma once

#include "Globals.h"
#include "ue4.h"

namespace aimbotBooleans {
	void Render() {
        ImGui::Separator();
        ImGui::Checkbox("Enable Aimbot", &Globals::AimbotEnabled);
        if (ue4::IsPlayingMME()) {
            ImGui::Checkbox("Ignore Mates", &Globals::ignoreMates);
        }
	}
}