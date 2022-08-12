#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderBulletSpeedMultiplier {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
        ImGui::SetNextItemWidth(150.000f);
        if (ImGui::SliderFloat("Bullet Speed Multiplier", &Globals::BulletSpeedMultiplier->Multiplier, 0.01f, 25.f)) {
            if (!Globals::BulletSpeedMultiplier->enabled) {
                Globals::BulletSpeedMultiplier->OriginalValue = attributeSet->RifleBulletSpeed.CurrentValue;
                Globals::BulletSpeedMultiplier->enabled = true;
            }

            attributeSet->RifleBulletSpeed.CurrentValue = Globals::BulletSpeedMultiplier->OriginalValue * Globals::BulletSpeedMultiplier->Multiplier;
        }
	}
}