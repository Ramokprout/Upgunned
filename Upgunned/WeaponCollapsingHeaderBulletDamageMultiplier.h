#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderBulletDamageMultiplier {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
		ImGui::SetNextItemWidth(150.000f);
		ImGui::SliderFloat("Bullet Damage Multiplier", &attributeSet->DamageBaseMultiplier.CurrentValue, 0.01f, 150.f);
	}
}