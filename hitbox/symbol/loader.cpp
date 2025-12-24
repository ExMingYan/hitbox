#include "loader.h"

bool SymbolLoader::LoadSymbols(HMODULE hModule) {
	if (!Initialized)
	{
		return false;
	}
	char dllPath[MAX_PATH];
	GetModuleFileNameA(NULL, dllPath, MAX_PATH);
	fs::path pdbPath = fs::path(dllPath).replace_extension(".pdb");
	if (!fs::exists(pdbPath) || !fs::is_regular_file(pdbPath))
	{
		return false;
	}
	DWORD64 baseAddress = SymLoadModuleEx(hProcess, NULL, pdbPath.string().c_str(), NULL, (DWORD64)hModule, 0, NULL, 0);
	if (baseAddress == 0)
	{
		return false;
	}
	return true;
}
