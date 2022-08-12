#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace PlayerCollapsingHeaderHealthMultiplier {
	void Render(BaseCharacterAttributeSet* BaseCharacterAttributeSet) {
        ImGui::SetNextItemWidth(150.000f);
        if (ImGui::SliderFloat("Health Multiplier", &Globals::HealthMultiplier->Multiplier, 0.5f, 15.f)) {
            if (!Globals::HealthMultiplier->enabled) {
                Globals::HealthMultiplier->OriginalValue = BaseCharacterAttributeSet->MaxHealth.CurrentValue;
                Globals::HealthMultiplier->enabled = true;
            }

            BaseCharacterAttributeSet->Health.CurrentValue = BaseCharacterAttributeSet->MaxHealth.CurrentValue * Globals::HealthMultiplier->Multiplier; //
        }
	}
}