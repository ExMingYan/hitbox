#include <filesystem>
#include <iostream>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include "DLLInjector.h"

namespace fs = std::filesystem;

static DWORD processID = 0;
static fs::path pdbPath;
static bool InjectSymbol = false;
static bool CheckFileWithExtension(const fs::path& dllPath, std::string extension);
static bool ProcessArgs(int argc, char* argv[]);
DWORD GetProcessIDByName(const std::wstring& processName);
