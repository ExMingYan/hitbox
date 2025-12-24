#include "DLLInjector.h"
#include <TlHelp32.h>
#include <iostream>
#include <string>

bool DLLInjector::Initialize(DWORD processID) {
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if (!hProcess) {
		std::cerr << "Failed to open process with ID " << processID << ". Error: " << GetLastError() << std::endl;
		return false;
	}
	return true;
}

bool DLLInjector::InjectDLL(const std::string& dllPath)
{
	LPVOID pDllPath = VirtualAllocEx(hProcess, nullptr, dllPath.size() + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (!pDllPath)
	{
		std::cerr << "Failed to allocate memory in target process. Error: " << GetLastError() << std::endl;
		return false;
	}

	if (!WriteProcessMemory(hProcess, pDllPath, dllPath.c_str(), dllPath.size() + 1, nullptr))
	{
		std::cerr << "Failed to write DLL path to target process memory. Error: " << GetLastError() << std::endl;
		VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
		return false;
	}

	HMODULE hmodule = GetModuleHandleW(L"kernel32.dll");
	if (hmodule == NULL || hmodule == INVALID_HANDLE_VALUE)
	{
		std::cerr << "Failed to get handle of kernel32.dll. Error: " << GetLastError() << std::endl;
		VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
		return false;
	}

	LPTHREAD_START_ROUTINE pLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(hmodule, "LoadLibraryA");
	if (!pLoadLibrary)
	{
		std::cerr << "Failed to get address of LoadLibraryA. Error: " << GetLastError() << std::endl;
		VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
		return false;
	}

	HANDLE hThread = CreateRemoteThread(hProcess, nullptr, 0, pLoadLibrary, pDllPath, 0, nullptr);
	if (!hThread)
	{
		std::cerr << "Failed to create remote thread. Error: " << GetLastError() << std::endl;
		VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
		return false;
	}
	WaitForSingleObject(hThread, INFINITE);
	VirtualFreeEx(hProcess, pDllPath, 0, MEM_RELEASE);
	CloseHandle(hThread);
	return true;
}
