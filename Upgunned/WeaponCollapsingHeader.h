#pragma once

#include "pch.h"
#include "engine.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "WeaponCollapsingHeaderComponents.h"
#include "ue4.h"

namespace WeaponCollapsingHeader {
	void Render() {
		ImGui::Separator();
		if (ImGui::CollapsingHeader("Weapon"))
		{
			auto localPlayer = ue4::getLocalPlayer();
			auto weaponAttributeSet = localPlayer->PlayerController->Character->PlayerState->WeaponAttributeSet;
			WeaponCollapsingHeaderNoSpread::Render(weaponAttributeSet);
			WeaponCollapsingHeaderRifleFireRateMultiplier::Render(weaponAttributeSet);
			WeaponCollapsingHeaderBulletSpeedMultiplier::Render(weaponAttributeSet);
			WeaponCollapsingHeaderRifleMagazine::Render(weaponAttributeSet);
			WeaponCollapsingHeaderBulletCriticalHitChanceMultiplier::Render(weaponAttributeSet);
			WeaponCollapsingHeaderBulletDamageMultiplier::Render(weaponAttributeSet);//todo
			WeaponCollapsingHeaderResetValues::Render(weaponAttributeSet);//todo
		}
	}
}