#pragma once


#include "pch.h"
#include "engine.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "visualsmenucomponents.h"

namespace visualMenu {
	void Render() {
		FOV::Render();
		visualBooleans::Render();
		visualDistSettings::Render();
		visualColorSettings::Render();
	}
}