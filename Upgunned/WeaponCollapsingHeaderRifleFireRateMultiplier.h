#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderRifleFireRateMultiplier {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
        ImGui::SetNextItemWidth(150.000f);
        if (ImGui::SliderFloat("Rifle Fire Rate Multiplier", &Globals::RifleFireRateMultiplier->Multiplier, 0.01f, 50.f)) {
            if (!Globals::RifleFireRateMultiplier->enabled) {
                Globals::RifleFireRateMultiplier->OriginalValue = attributeSet->RifleFireRate.CurrentValue;
                Globals::RifleFireRateMultiplier->enabled = true;
            }

            attributeSet->RifleFireRate.CurrentValue = Globals::RifleFireRateMultiplier->OriginalValue * Globals::RifleFireRateMultiplier->Multiplier;
        }
	}
}