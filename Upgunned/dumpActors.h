#pragma once

#include "engine.h"
#include "Native.h"
#include "pch.h"

namespace debugDumpActors {
	void Render() {
        if (ImGui::Button("Dump Actors")) {
            auto actors = UpgunnedEngine::GetWorld()->PersistentLevel->AActors;
            std::wofstream stream("actorsdump.txt");

            for (int i = 0; i < actors.Num(); i++) {
                auto actor = actors[i];
                if (actor == nullptr || !actor) continue;
                auto UobjectActor = (UObject*)actor;
                if (IsBadReadPtr(&UobjectActor->Name, sizeof(FName))) continue;
                FString str = FString();
                Native::FNameToString(&UobjectActor->Name, &str);
                std::wstring wStr = std::wstring(str.c_str());
                Native::FMemoryFree(str.c_str());
                stream << L"[" << std::to_wstring(i) << L"] " << wStr << std::endl;
                wStr.clear();
            }

            stream.close();
        }
	}
}