#include "pch.h"
#include "util.h"

void util::CreateConsole()
{
	AllocConsole();
	FILE* File;
	freopen_s(&File, "CONOUT$", "w", stdout);
}

std::string util::FNameToString(void* fName)
{
	FString str = FString();
	Native::FNameToString(fName, &str);
	std::wstring wStr = str.c_str();
	std::string sstr = std::string(wStr.begin(), wStr.end());

	return sstr;
}
