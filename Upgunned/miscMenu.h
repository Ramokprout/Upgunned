#pragma once


#include "pch.h"
#include "engine.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "ue4.h"
#include "misccomponents.h"
#include "config.h"
namespace miscMenu {
    void Render() {
        buildConsoleButton::Render();
        writeConfig::Render();
        loadConfig::Render();
    }
}