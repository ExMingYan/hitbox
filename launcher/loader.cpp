#include "loader.h"
#include "MemLoadDll.h"
#include "scope_exit.hpp"

loader::~loader()
{
	CloseHandle(hprocess);
}

bool loader::remote_thread(unsigned long pid, unsigned __int8* file, unsigned long size)
{
	hprocess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (hprocess == INVALID_HANDLE_VALUE) {
		return false;
	}

	std::unique_ptr<unsigned __int8[]> filebuffer(new unsigned __int8[size]);
	memcpy(filebuffer.get(), file, size);

	auto dos_header = reinterpret_cast<IMAGE_DOS_HEADER*>(filebuffer.get());
	if (dos_header->e_magic != IMAGE_DOS_SIGNATURE) {
		return false;
	}

	auto nt_headers = reinterpret_cast<IMAGE_NT_HEADERS*>(filebuffer.get() + dos_header->e_lfanew);
	if (nt_headers->Signature != IMAGE_NT_SIGNATURE || nt_headers->FileHeader.Machine != IMAGE_FILE_MACHINE_AMD64) {
		return false;
	}

	void* library = VirtualAllocEx(hprocess, 0, size, MEM_COMMIT, PAGE_READWRITE);
	auto freelibrary = std::scope_exit([&] { VirtualFreeEx(hprocess, library, size, MEM_RELEASE); });

	void* shellcode = VirtualAllocEx(hprocess, 0, sizeof(MemLoadShellcode_x64), MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	auto freeshellcode = std::scope_exit([&] { VirtualFreeEx(hprocess, shellcode, sizeof(MemLoadShellcode_x64), MEM_RELEASE); });

	bool success = WriteProcessMemory(hprocess, library, filebuffer.get(), size, nullptr);
	if (!success) {
		return false;
	}

	success = WriteProcessMemory(hprocess, shellcode, MemLoadShellcode_x64, sizeof(MemLoadShellcode_x64), nullptr);
	if (!success) {
		return false;
	}

	HANDLE remote_thread = CreateRemoteThread(hprocess, 0, 0, (LPTHREAD_START_ROUTINE)shellcode, library, 0, 0);
	WaitForSingleObject(remote_thread, INFINITE);
	CloseHandle(remote_thread);
	return true;
}