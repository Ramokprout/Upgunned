#pragma once

#include "engine.h"
#include "util.h"

namespace debugWorldSettings {
	void Render() {
		if (ImGui::Button("debug worldsettings ptr")) {
			PRINT_PTR(UpgunnedEngine::GetWorld()->PersistentLevel->WorldSettings, "WorldSettings"); //broken for some reasons
		}
	}
}