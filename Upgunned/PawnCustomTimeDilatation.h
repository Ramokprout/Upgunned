#pragma once

#include "pch.h"
#include "Globals.h"
#include "upgunstructs.h"

namespace PawnCustomTimeDilatation {
	void Render(float* CustomTimeDilatation) {
        ImVec2 size = { 0, 0 };
        size = ImGui::CalcTextSize("Pawn CustomTimeDilatation");
        ImGui::SetNextItemWidth(200.000f);
        ImGui::SliderFloat("Pawn CustomTimeDilatation", CustomTimeDilatation, 0.f, 15.f);
        ImGui::SameLine();
        ImGui::SetCursorPos({ size.x + 225, ImGui::GetCursorPosY() });
        if (ImGui::Button("Reset##first")) {
            *CustomTimeDilatation = 1;
        }
	}
}