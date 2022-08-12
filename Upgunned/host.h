#pragma once

#include "pch.h"
#include "engine.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "guicomponents.h"

namespace Host {
	void Render(Character* character) {
		static float WorldCustomTimeDialationTemp = 0.f;
		PawnCustomTimeDilatation::Render(&character->CustomTimeDilatation);
		WorldCustomTimeDilatation::Render(&WorldCustomTimeDialationTemp); //&UpgunnedEngine::GetWorld()->PersistentLevel->WorldSettings->TimeDilatation
		WeaponCollapsingHeader::Render();
		PlayerCollapsingHeader::Render();
	}
}