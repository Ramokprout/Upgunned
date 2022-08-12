#pragma once

#include "ue4.h"
#include "util.h"

namespace debugPrintAddresses {
	void Render() {
        if (ImGui::Button("Print Addresses")) {
            auto LocalPlayer = ue4::getLocalPlayer();
            PRINT_PTR(LocalPlayer, "LocalPlayer");
            if (LocalPlayer->PlayerController) {
                PRINT_PTR(LocalPlayer->PlayerController, "PlayerController");
            }

        }
	}
}