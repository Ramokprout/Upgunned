#pragma once

#include "Globals.h"
#include "ue4.h"

namespace visualBooleans {
	void Render() {
        ImGui::Separator();
        ImGui::Checkbox("ESP", &Globals::boxesESP);
        ImGui::Checkbox("ESP VisCheck", &Globals::boxesESPVischeck);
        if (ue4::IsPlayingMME()) {
            ImGui::Checkbox("ESP TeamMates", &Globals::boxesESPMates);
        }

#ifdef _DEBUG
        ImGui::Checkbox("Bones ESP", &Globals::bonesESP);
#endif
        ImGui::Checkbox("Snaplines", &Globals::snapLines);
        ImGui::Checkbox("Snaplines VisCheck", &Globals::snapLinesVischeck);
        ImGui::Checkbox("Render Aimbot FOV", &Globals::renderFOVCircle);
        ImGui::Checkbox("Show Watermark", &Globals::showWatermark);
        ImGui::Checkbox("Show FPS", &Globals::showFPS);
	}
}