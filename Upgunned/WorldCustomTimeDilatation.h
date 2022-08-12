#pragma once

#include "pch.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "engine.h"

namespace WorldCustomTimeDilatation {

    void resetValues() {
        Globals::WalkSpeedMultiplier->enabled = false;
        Globals::WalkSpeedMultiplier->Multiplier = 1;
        Globals::WalkSpeedMultiplier->OriginalValue = 0.f;
        Globals::HealthMultiplier->enabled = false;
        Globals::HealthMultiplier->Multiplier = 1;
        Globals::HealthMultiplier->OriginalValue = 0.f;
        Globals::noSpread->enabled = false;
        Globals::noSpread->enabledCheckbox = false;
        Globals::noSpread->Multiplier = 1;
        Globals::noSpread->OriginalValue = 0.f;
        Globals::RifleFireRateMultiplier->enabled = false;
        Globals::RifleFireRateMultiplier->Multiplier = 1;
        Globals::RifleFireRateMultiplier->OriginalValue = 0.f;
        Globals::BulletSpeedMultiplier->enabled = false;
        Globals::BulletSpeedMultiplier->Multiplier = 1;
        Globals::BulletSpeedMultiplier->OriginalValue = 0.f;
        Globals::RifleMagazine = 20.0f;
        Globals::RifleCriticalHitChanceMultiplier->enabled = false;
        Globals::RifleCriticalHitChanceMultiplier->Multiplier = 1;
        Globals::RifleCriticalHitChanceMultiplier->OriginalValue = 0.f;
        Globals::GWorldTrigger = UpgunnedEngine::GetWorld();
    }

	void Render(float* CustomTimeDilatation) {
		ImVec2 size = { 0, 0 };
        size = ImGui::CalcTextSize("World CustomTimeDilatation");
        ImGui::SetNextItemWidth(200.000f);
        ImGui::SliderFloat("World CustomTimeDilatation", CustomTimeDilatation, 0.f, 15.f);
        ImGui::SameLine();
        ImGui::SetCursorPos({ size.x + 223, ImGui::GetCursorPosY() });
        if (ImGui::Button("Reset##second")) {
            *CustomTimeDilatation = 1;
        }

        if (Globals::GWorldTrigger != UpgunnedEngine::GetWorld()) {
            resetValues();
        }
	}
}