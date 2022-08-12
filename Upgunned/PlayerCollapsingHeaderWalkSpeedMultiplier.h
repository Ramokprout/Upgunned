#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace PlayerCollapsingHeaderWalkSpeedMultiplier {
	void Render(BaseCharacterAttributeSet* BaseCharacterAttributeSet) {
        ImGui::SetNextItemWidth(150.000f);
        if (ImGui::SliderFloat("WalkSpeed Multiplier", &Globals::WalkSpeedMultiplier->Multiplier, 0.5f, 4.f)) {
            if (!Globals::WalkSpeedMultiplier->enabled) {
                Globals::WalkSpeedMultiplier->OriginalValue = BaseCharacterAttributeSet->WalkSpeed.CurrentValue;
                Globals::WalkSpeedMultiplier->enabled = true;
            }

            BaseCharacterAttributeSet->WalkSpeed.CurrentValue *= Globals::WalkSpeedMultiplier->Multiplier;
        }
	}
}