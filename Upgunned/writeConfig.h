#pragma once

#include "config.h"
#include "pch.h"

namespace writeConfig {
	void Render() {
		if (ImGui::Button("Write config")) {
			Config::Save();
		}
	}
}