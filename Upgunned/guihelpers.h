#pragma once

#include "pch.h"
#include "upgunstructs.h"
#include "Globals.h"

namespace GUIHelpers {
    std::pair<const char*, UpGunBoneIds> BoneArray[5] = {
        std::make_pair("HEAD", UpGunBoneIds::HEAD),
        std::make_pair("NECK", UpGunBoneIds::NECK),
        std::make_pair("PENIS", UpGunBoneIds::PELVIS),
        std::make_pair("FOOT", UpGunBoneIds::ROOT),
        std::make_pair("CHEST", UpGunBoneIds::CHEST)
    };

    std::pair<const char*, AimbotKey> AimbotKeys[7] = {
            std::make_pair("MOUSE_L", AimbotKey::MOUSE_L),
            std::make_pair("MOUSE_MIDDLE", AimbotKey::MOUSE_MIDDLE),
            std::make_pair("MOUSE_R", AimbotKey::MOUSE_R),
            std::make_pair("CONTROL", AimbotKey::CONTROL),
            std::make_pair("ALT", AimbotKey::ALT),
            std::make_pair("SHIFT", AimbotKey::SHIFT),
            std::make_pair("TAB", AimbotKey::TAB),
    };


    std::pair<const char*, AimbotKey> getCurrentAimbotKey() {
        size_t n = sizeof(AimbotKeys) / sizeof(AimbotKeys[0]);
        for (int i = 0; i < n; i++) {
            auto aimkey = AimbotKeys[i];
            if (Globals::Aimbot_Key == aimkey.second) {
                return aimkey;
            }
        }

        return std::make_pair("MOUSE_R", AimbotKey::MOUSE_R);
    }

    std::pair<const char*, UpGunBoneIds> getCurrentAimbotLocation() {
        size_t n = sizeof(BoneArray) / sizeof(BoneArray[0]);
        for (int i = 0; i < n; i++) {
            auto bonePair = BoneArray[i];
            if (Globals::Aimbot_Pos == bonePair.second) {
                return bonePair;
            }
        }

        return  std::make_pair("HEAD", UpGunBoneIds::HEAD);
    }

    enum GuiTabs {
        GuiTabs_Host,
        GuiTabs_Debug,
        GuiTabs_Visuals,
        GuiTabs_Misc,
        GuiTabs_Aimbot
    };
}