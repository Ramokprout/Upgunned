#pragma once

#include "pch.h"
#include "Globals.h"
#include "config.h"

namespace loadConfig {
	void Render() {
        if (ImGui::Button("Load config")) {
            char* buf = nullptr;
            size_t sz = 0;
            if (_dupenv_s(&buf, &sz, "userprofile") == 0 && buf != nullptr)
            {
                std::filesystem::path documentsPath = std::filesystem::path(buf) / "Documents";
                ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose Config File", ".bin", documentsPath.string().c_str(), 1, nullptr, ImGuiFileDialogFlags_HideColumnSize | ImGuiFileDialogFlags_DontShowHiddenFiles | ImGuiFileDialogFlags_DisableCreateDirectoryButton | ImGuiFileDialogFlags_ReadOnlyFileNameField);
                free(buf);
            }

        }

        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
        {
            if (ImGuiFileDialog::Instance()->IsOk())
            {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                std::filesystem::path path = filePath / std::filesystem::path(filePathName);
                Config::Load(path.string());
            }

            ImGuiFileDialog::Instance()->Close();
        }
	}
}