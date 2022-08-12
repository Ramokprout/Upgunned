#pragma once

#include "pch.h"
#include "Globals.h"
#include "guihelpers.h"

namespace aimbotPosSelector {
    void Render() {
        auto currentPos = GUIHelpers::getCurrentAimbotLocation();
        if (ImGui::BeginCombo("Aimbot Position", currentPos.first)) {
            size_t n = sizeof(GUIHelpers::BoneArray) / sizeof(GUIHelpers::BoneArray[0]);
            for (int i = 0; i < n; i++) {
                auto boneName = GUIHelpers::BoneArray[i];
                bool selected = Globals::Aimbot_Pos == boneName.second;

                if (ImGui::Selectable(boneName.first, selected)) {
                    Globals::Aimbot_Pos = boneName.second;
                }

                if (selected) {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }
    }
}