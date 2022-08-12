#pragma once

#include "pch.h"
#include "engine.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "debugmenucomponents.h"

namespace debug {
	void Render() {
		debugPrintAddresses::Render();
		debugDumpActors::Render();
		debugTeam::Render();
		debugGamemodeName::Render();
		debugIsPlayingMME::Render();
		debugWorldSettings::Render();
	}
}

