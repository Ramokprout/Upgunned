#pragma once

#include "aimbotmenucomponents.h"
#include "ue4.h"
#include "upgunstructs.h"

namespace aimbotMenu {
	void Render() {
		aimbotPosSelector::Render();
		aimbotKeySelector::Render();
		aimbotBooleans::Render();
		aimbotSettings::Render();
	}
}