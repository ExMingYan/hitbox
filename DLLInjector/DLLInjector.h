#include <Windows.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <sstream>

namespace fs = std::filesystem;

class DLLInjector {
private:
	HANDLE hProcess;
	bool Initialized;
	bool Initialize(DWORD processID);
public:
	DLLInjector(DWORD processID) : hProcess(NULL), Initialized(false) {
		Initialize(processID);
	}
	~DLLInjector() {
		if (hProcess) {
			CloseHandle(hProcess);
		}
	}
	bool InjectDLL(const std::string& dllPath);
};
