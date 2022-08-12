#pragma once

#include "upgunstructs.h"
#include "Globals.h"

namespace WeaponCollapsingHeaderResetValues {
	void Render(UpGunWeaponAttributeSet* attributeSet) {
        if (ImGui::Button("Reset Values##WeaponResetValues")) {

            attributeSet->DamageBaseMultiplier.CurrentValue = attributeSet->DamageBaseMultiplier.BaseValue;
            attributeSet->RifleMagazine.CurrentValue = attributeSet->RifleMagazine.BaseValue;
            attributeSet->RifleCriticalHitChance.CurrentValue = Globals::RifleCriticalHitChanceMultiplier->OriginalValue;
            attributeSet->RifleBulletSpeed.CurrentValue = Globals::BulletSpeedMultiplier->OriginalValue;
            attributeSet->RifleFireRate.CurrentValue = Globals::RifleFireRateMultiplier->OriginalValue;
            attributeSet->RifleDispersion.CurrentValue = Globals::noSpread->OriginalValue;

            Globals::noSpread->enabled = false;
            Globals::noSpread->enabledCheckbox = false;
            Globals::noSpread->Multiplier = 1;
            Globals::noSpread->OriginalValue = 0.f;
            Globals::RifleFireRateMultiplier->enabled = false;
            Globals::RifleFireRateMultiplier->Multiplier = 1;
            Globals::RifleFireRateMultiplier->OriginalValue = 0.f;
            Globals::BulletSpeedMultiplier->enabled = false;
            Globals::BulletSpeedMultiplier->Multiplier = 1;
            Globals::BulletSpeedMultiplier->OriginalValue = 0.f;
            Globals::RifleMagazine = 20.0f;
            Globals::RifleCriticalHitChanceMultiplier->enabled = false;
            Globals::RifleCriticalHitChanceMultiplier->Multiplier = 1;
            Globals::RifleCriticalHitChanceMultiplier->OriginalValue = 0.f;


        }
	}
}