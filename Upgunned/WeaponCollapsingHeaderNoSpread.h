#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderNoSpread {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
        if (ImGui::Checkbox("No Spread", &Globals::noSpread->enabledCheckbox)) {
            if (Globals::noSpread->enabledCheckbox) {
                if (!Globals::noSpread->enabled) {
                    Globals::noSpread->OriginalValue = attributeSet->RifleDispersion.CurrentValue;
                    Globals::noSpread->Multiplier = 0.001f;
                    Globals::noSpread->enabled = true;
                }
                attributeSet->RifleDispersion.CurrentValue = attributeSet->RifleDispersion.CurrentValue * Globals::noSpread->Multiplier;
            }
            else {
                Globals::noSpread->enabled = false;
                Globals::noSpread->OriginalValue = 0;
                Globals::noSpread->Multiplier = 1;
            }
        }
	}
}