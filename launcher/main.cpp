#include <iostream>
#include "loader.h"
#include "hitbox.hpp"

int main() {
	HWND hwnd = FindWindowA("UnrealWindow", "KOFXV  ");
	unsigned long pid = 0;
	GetWindowThreadProcessId(hwnd, &pid);
	if (pid == 0) {
		MessageBoxA(0, "��Ϸδ����", "warning", MB_OK);
		return -1;
	}

	loader* load = loader::instance();
	bool success = load->remote_thread(pid, hitbox, sizeof(hitbox));
	if (success == false) {
		MessageBoxA(0, "����ʧ��", "warning", MB_OK);
		return -1;
	}
	return 0;
}