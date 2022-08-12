#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderBulletCriticalHitChanceMultiplier {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
        ImGui::SetNextItemWidth(150.000f);
        if (ImGui::SliderFloat("Bullet Critical Hit Chance Multiplier", &Globals::RifleCriticalHitChanceMultiplier->Multiplier, 0.01f, 150.f)) {
            if (!Globals::RifleCriticalHitChanceMultiplier->enabled) {
                Globals::RifleCriticalHitChanceMultiplier->OriginalValue = attributeSet->RifleCriticalHitChance.CurrentValue;
                Globals::RifleCriticalHitChanceMultiplier->enabled = true;
            }
            attributeSet->RifleCriticalHitChance.CurrentValue = Globals::RifleCriticalHitChanceMultiplier->OriginalValue * Globals::RifleCriticalHitChanceMultiplier->Multiplier;
        }
	}
}