#include "main.hpp"

int main(int argc, char* argv[])
{
	if (argc < 4 || argc > 6)
	{
		std::cerr << "Usage:\n\t" << argv[0] << "<PathToDLL> -pid <ProcessID>\\n\t" << \
			argv[0] << "<PathToDLL> -pname <ProcessName>" << std::endl;
		return EXIT_FAILURE;
	}

	fs::path dllPath = fs::absolute(argv[1]);
	if (!CheckFileWithExtension(dllPath, ".dll") || !ProcessArgs(argc, argv))
	{
		return EXIT_FAILURE;
	}
	if (processID != 0)
	{
		auto injector = DLLInjector(processID);
		if (!injector.InjectDLL(dllPath.string()))
		{
			std::cerr << "DLL Injection failed for Process ID" << processID << std::endl;
			return EXIT_FAILURE;
		}
	}
	else
	{
		std::cerr << "Process ID or Process Name Error." << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

bool CheckFileWithExtension(const fs::path& dllPath, const std::string extension)
{
	if (!fs::exists(dllPath) || !fs::is_regular_file(dllPath))
	{
		std::cerr << "DLL Path does not exist or is not a file: " << dllPath.string() << std::endl;
		return false;
	}
	else if (dllPath.extension() != extension)
	{
		std::cerr << "Provided file is not a : " << extension << std::endl;
		return false;
	}
	return true;
}

bool ProcessArgs(int argc, char* argv[])
{
	for (int i = 2; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg == "-pid" && ++i < argc)
		{
			processID = static_cast<DWORD>(std::stoul(argv[i]));
		}
		else if (arg == "-pname" && ++i < argc)
		{
			const std::wstring processName = std::wstring(argv[i], argv[i] + strlen(argv[i]));
			processID = GetProcessIDByName(processName);
		}
		else
		{
			std::cerr << "Unknown argument: " << arg << std::endl;
			return false;
		}
	}
	return true;
}

DWORD GetProcessIDByName(const std::wstring& processName)
{
	DWORD pid = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE)
	{
		std::cerr << "Failed to create process snapshot. Error: " << GetLastError() << std::endl;
		return 0;
	}
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hSnapshot, &pe))
	{
		do
		{
			if (processName == pe.szExeFile)
			{
				pid = pe.th32ProcessID;
				break;
			}
		} while (Process32Next(hSnapshot, &pe));
	}
	else
	{
		std::cerr << "Failed to get first process. Error: " << GetLastError() << std::endl;
	}
	CloseHandle(hSnapshot);
	return pid;
}
