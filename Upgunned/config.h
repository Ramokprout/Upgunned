#pragma once

#include "pch.h"
#include "Globals.h"

class Config {
private:
	static void WriteContent(std::string content, std::filesystem::path path) {
		std::ofstream stream(path.string().c_str());

		if (stream && stream.is_open()) {
			stream << std::setw(4) << content << std::flush;
		}

		stream.close();
	}

	static nlohmann::json globalsToJson() {
		nlohmann::basic_json<std::map, std::vector, std::string, bool, std::int64_t, std::uint64_t, float> result = {
			{"showFPS", Globals::showFPS},
			{"showWatermark", Globals::showWatermark},
			{"snapLines", Globals::snapLines},
			{"snapLinesVischeck", Globals::snapLinesVischeck},
			{"boxesESP", Globals::boxesESP},
			{"boxesESPVischeck", Globals::boxesESPVischeck},
			{"boxesESPMates", Globals::boxesESPMates},
			{"renderFOVCircle", Globals::renderFOVCircle},
			{"ignoreMates", Globals::ignoreMates},
			{"AimbotEnabled", Globals::AimbotEnabled},
			{"AimbotSpeedX", Globals::AimbotSpeedX},
			{"AimbotSpeedY", Globals::AimbotSpeedY},
			{"Aimbot_Key", Globals::Aimbot_Key},
			{"Aimbot_Pos", Globals::Aimbot_Pos},
			{"AimbotFOV", Globals::AimbotFOV},
			{"SnaplinesMaxDistance", Globals::SnaplinesMaxDistance},
			{"ESPMaxDistance", Globals::ESPMaxDistance},
			{"FOVCircleColor", {Globals::FOVCircleColor[0], Globals::FOVCircleColor[1], Globals::FOVCircleColor[2]}},
			{"ESPColor", {Globals::ESPColor[0], Globals::ESPColor[1], Globals::ESPColor[2]}},
			{"ESPTeamMateColor", {Globals::ESPTeamMateColor[0], Globals::ESPTeamMateColor[1], Globals::ESPTeamMateColor[2]}},
			{"ESPVisibleColor", {Globals::ESPVisibleColor[0], Globals::ESPVisibleColor[1], Globals::ESPVisibleColor[2]}},
			{"SnaplinesColor", {Globals::SnaplinesColor[0], Globals::SnaplinesColor[1], Globals::SnaplinesColor[2]}},
			{"SnaplinesVisibleColor", {Globals::SnaplinesVisibleColor[0], Globals::SnaplinesVisibleColor[1], Globals::SnaplinesVisibleColor[2]}},
		};

		return result;
	}

public:
	static void Save() {
		char* buf = nullptr;
		size_t sz = 0;
		if (_dupenv_s(&buf, &sz, "userprofile") == 0 && buf != nullptr)
		{
			std::filesystem::path path = std::filesystem::path(buf) / "Documents" / "upgunnedconfig.bin";
			auto json = globalsToJson();
			WriteContent(json.dump(), path);
			std::cout << "Wrotten content in " << path.string() << std::endl;
			free(buf);
		}
	}

	static float* propertyToFloatArray(nlohmann::json json) {
		auto result = new float[3];

		result[0] = json[0].get<float>();
		result[1] = json[1].get<float>();
		result[2] = json[2].get<float>();

		return result;
	}

	static void Load(std::string filePath) {
		//printf("FILE PATH : %s\n", filePath.c_str());
		std::ifstream stream(filePath);
		if (stream && stream.is_open()) {
			nlohmann::json json = { nullptr };

			std::string fileContents = "";
			std::string buffer;
			while (getline(stream, buffer)) {
				fileContents += buffer + "\n";
			}

			stream.close();
		//	std::cout << fileContents << std::endl;
	
			json = json.parse(fileContents);

			Globals::showFPS = json["showFPS"].get<bool>();
			Globals::showWatermark = json["showWatermark"].get<bool>();
			Globals::snapLines = json["snapLines"].get<bool>();
			Globals::snapLinesVischeck = json["snapLinesVischeck"].get<bool>();
			Globals::boxesESP = json["boxesESP"].get<bool>();
			Globals::boxesESPVischeck = json["boxesESPVischeck"].get<bool>();
			Globals::boxesESPMates = json["boxesESPMates"].get<bool>();
			Globals::renderFOVCircle = json["renderFOVCircle"].get<bool>();
			Globals::ignoreMates = json["ignoreMates"].get<bool>();
			Globals::AimbotEnabled = json["AimbotEnabled"].get<bool>();
			Globals::AimbotSpeedX = json["AimbotSpeedX"].get<int>();
			Globals::AimbotSpeedY = json["AimbotSpeedY"].get<int>();
			Globals::SnaplinesMaxDistance = json["SnaplinesMaxDistance"].get<float>();
			Globals::AimbotFOV = json["AimbotFOV"].get<float>();
			Globals::ESPMaxDistance = json["ESPMaxDistance"].get<float>();
			Globals::Aimbot_Key = static_cast<AimbotKey>(json["Aimbot_Key"].get<int>());
			Globals::Aimbot_Pos = static_cast<UpGunBoneIds>(json["Aimbot_Pos"].get<int>());
			auto FOVCircleColor = propertyToFloatArray(json["FOVCircleColor"]);
			auto ESPColor = propertyToFloatArray(json["ESPColor"]);
			auto ESPTeamMateColor = propertyToFloatArray(json["ESPTeamMateColor"]);
			auto ESPVisibleColor = propertyToFloatArray(json["ESPVisibleColor"]);
			auto SnaplinesColor = propertyToFloatArray(json["SnaplinesColor"]);
			auto SnaplinesVisibleColor = propertyToFloatArray(json["SnaplinesVisibleColor"]);
			Globals::FOVCircleColor[0] = FOVCircleColor[0];
			Globals::FOVCircleColor[1] = FOVCircleColor[1];
			Globals::FOVCircleColor[2] = FOVCircleColor[2];
			Globals::ESPColor[0] = ESPColor[0];
			Globals::ESPColor[1] = ESPColor[1];
			Globals::ESPColor[2] = ESPColor[2];
			Globals::ESPTeamMateColor[0] = ESPTeamMateColor[0];
			Globals::ESPTeamMateColor[1] = ESPTeamMateColor[1];
			Globals::ESPTeamMateColor[2] = ESPTeamMateColor[2];
			Globals::ESPVisibleColor[0] = ESPVisibleColor[0];
			Globals::ESPVisibleColor[1] = ESPVisibleColor[1];
			Globals::ESPVisibleColor[2] = ESPVisibleColor[2];
			Globals::SnaplinesColor[0] = SnaplinesColor[0];
			Globals::SnaplinesColor[1] = SnaplinesColor[1];
			Globals::SnaplinesColor[2] = SnaplinesColor[2];
			Globals::SnaplinesVisibleColor[0] = SnaplinesVisibleColor[0];
			Globals::SnaplinesVisibleColor[1] = SnaplinesVisibleColor[1];
			Globals::SnaplinesVisibleColor[2] = SnaplinesVisibleColor[2];
		}
	
	}
};