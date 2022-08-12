#pragma once

#include "pch.h"
#include "Globals.h"
#include "guihelpers.h"

namespace aimbotKeySelector {
	void Render() {
        ImGui::Separator();
        auto currentKey = GUIHelpers::getCurrentAimbotKey();
        if (ImGui::BeginCombo("Aimbot Key", currentKey.first)) {
            size_t n = sizeof(GUIHelpers::AimbotKeys) / sizeof(GUIHelpers::AimbotKeys[0]);
            for (int i = 0; i < n; i++) {
                auto aimbotKey = GUIHelpers::AimbotKeys[i];
                bool selected = Globals::Aimbot_Key == aimbotKey.second;

                if (ImGui::Selectable(aimbotKey.first, selected)) {
                    Globals::Aimbot_Key = aimbotKey.second;
                }

                if (selected) {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

	}
}