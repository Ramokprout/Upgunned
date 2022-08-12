#pragma once

#include "ue4.h"

namespace debugTeam {
	void Render() {

		if (ImGui::Button("debug team")) {
			auto localPlayer = ue4::getLocalPlayer();
			auto team = localPlayer->PlayerController->Character->Team;
			PRINT_PTR(&team, "team ptr"); //should be the same
			PRINT_PTR(&team.ID, "team id"); //should be the same
		}
	}
}