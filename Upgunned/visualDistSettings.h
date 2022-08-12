#pragma once

#include "Globals.h"
#include "pch.h"

namespace visualDistSettings {
	void Render() {
		ImGui::Separator();
		ImGui::SliderFloat("ESP Max Distance##ESPDIST", &Globals::ESPMaxDistance, 0, 1000);
		ImGui::SliderFloat("Snaplines Max Distance##SNAPDIST", &Globals::SnaplinesMaxDistance, 0, 1000);
	}
}