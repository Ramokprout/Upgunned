#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderRifleMagazine {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
        ImGui::SetNextItemWidth(150.000f);
        if (ImGui::SliderInt("Rifle Magazine", &Globals::RifleMagazine, 5, 100))
        {
            attributeSet->RifleMagazine.CurrentValue = (float)Globals::RifleMagazine;
        }
	}
}