#pragma once


#include "pch.h"
#include "engine.h"
#include "Globals.h"
#include "upgunstructs.h"
#include "ue4.h"

namespace miscMenu {
    void Render() {
        if (ImGui::Button("Build Console")) {
            ue4::BuildConsole();
            ue4::BuildCheatManager();
#ifndef DEBUGLOG
            std::cout << termcolor::bright_green
                << "Built UConsole and CheatManager successfully"
                << termcolor::reset
                << std::endl;
#endif
        }
    }
}