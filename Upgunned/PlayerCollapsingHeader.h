#pragma once

#include "Globals.h"
#include "ue4.h"
#include "PlayerCollapsingHeaderComponents.h"

namespace PlayerCollapsingHeader {
	void Render() {
		auto localPlayer = ue4::getLocalPlayer();
		if (ImGui::CollapsingHeader("Player")) {
			PlayerCollapsingHeaderHealthMultiplier::Render(localPlayer->PlayerController->Character->PlayerState->BaseCharacterAttributeSet);
			PlayerCollapsingHeaderWalkSpeedMultiplier::Render(localPlayer->PlayerController->Character->PlayerState->BaseCharacterAttributeSet);
			PlayerCollapsingHeaderResetValues::Render(localPlayer->PlayerController->Character->PlayerState->BaseCharacterAttributeSet);
		}
	}
}