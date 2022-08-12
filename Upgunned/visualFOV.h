#pragma once

#include "ue4.h"

namespace FOV {
	void Render() {
        if (ImGui::SliderInt("FOV", &Globals::FOV, 30, 160)) {
            auto LocalPlayer = ue4::getLocalPlayer();
            auto cam = LocalPlayer->PlayerController->Character->Camera;
            cam->FieldOfView = (float)Globals::FOV;
        }
	}
}
