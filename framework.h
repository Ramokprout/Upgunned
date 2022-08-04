#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <detours.h>
#pragma comment(lib, "detours.lib")

#include <d3d11.h>
#include <d3dx11.h>
#pragma comment(lib, "d3d11.lib")

#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>