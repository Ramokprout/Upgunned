#pragma once

#include "engine.h"
#include "pch.h"
#include "ue4.h"

namespace debugIsPlayingMME {
	void Render() {
		if (ImGui::Button("Is playing mme")) {
			auto isPlayingMME = ue4::IsPlayingMME();
			printf("Is playing mme : %d\n", isPlayingMME);
		}
	}
}