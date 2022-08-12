#pragma once


#include "upgunstructs.h"
#include "Globals.h"

namespace PlayerCollapsingHeaderResetValues {
	void Render(BaseCharacterAttributeSet* BaseCharacterAttributeSet) {
        if (ImGui::Button("Reset Values##PlayerResetValues")) {
      //      
            if (Globals::HealthMultiplier->enabled) {
                BaseCharacterAttributeSet->Health.CurrentValue = BaseCharacterAttributeSet->MaxHealth.CurrentValue;
            }    
            
            if (Globals::WalkSpeedMultiplier->enabled) {
                BaseCharacterAttributeSet->WalkSpeed.CurrentValue = Globals::WalkSpeedMultiplier->OriginalValue;
            }

            Globals::WalkSpeedMultiplier->enabled = false;
            Globals::WalkSpeedMultiplier->Multiplier = 1;
            Globals::WalkSpeedMultiplier->OriginalValue = 1.f;
            Globals::HealthMultiplier->enabled = false;
            Globals::HealthMultiplier->Multiplier = 1;
            Globals::HealthMultiplier->OriginalValue = 1.f;
        }
	}
}