#pragma once

#include "engine.h"
#include "util.h"

namespace debugGamemodeName {
	void Render() {
		if (ImGui::Button("print gameMode name")) {
			PRINT_PTR(UpgunnedEngine::GetWorld()->GameState->AuthorityGameMode, "AuthorityGameMode");
			wprintf(L"GameMode Name : %s\n", UpgunnedEngine::GetGameModeName().c_str());
		}	
		
		if (ImGui::Button("print gameState name")) {
			PRINT_PTR(UpgunnedEngine::GetWorld()->GameState, "GameState");
			wprintf(L"GameState Name : %s\n", UpgunnedEngine::GetGameStateName().c_str());
		}	
		
		if (ImGui::Button("print gameState name 2")) {
			auto FName = UpgunnedEngine::GetWorld()->GameState->GameMode->Name;
			FString* str = (FString*)Native::FTEXTTOSTRING(&FName);
			wprintf(L"GameMode Name : %s\n", std::wstring(str->c_str()).c_str());
		}	
		
		if (ImGui::Button("print GameMode classname from GameState->GameModeEntry")) {
			auto Class = (UObject*)UpgunnedEngine::GetWorld()->GameState->GameMode->GameModeClass;
			wprintf(L"class name : %s\n", std::wstring(Class->GetName()).c_str());
		}
	}
}