#pragma once
#include <memory>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <filesystem>
#include "singletion.hpp"

class loader :public singleton<loader>
{
private:
	HANDLE hprocess;

public:
	~loader();
	bool remote_thread(unsigned long pid, unsigned __int8* file, unsigned long size);
};
