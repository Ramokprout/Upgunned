#pragma once

#include "Globals.h"
#include "pch.h"

namespace aimbotSettings {
	void Render() {
		ImGui::Separator();
		ImGui::SliderFloat("Aimbot FOV##AIMFOV", &Globals::AimbotFOV, 10, 700);
		ImGui::SliderInt("Aimbot Smooth X##AIMSMOOTHX", &Globals::AimbotSpeedX, 1, 15);
		ImGui::SliderInt("Aimbot Smooth Y##AIMSMOOTHY", &Globals::AimbotSpeedY, 1, 15);
	}
}