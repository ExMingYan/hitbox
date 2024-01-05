#include "memory.h"

bool memory::probe(void* address, unsigned long long size, unsigned __int32 alignment)
{
	if (address == nullptr) {
		return false;
	}

	if (size == 0) {
		return false;
	}

	unsigned long long current = (unsigned long long)address;
	if (((unsigned long long)address & (alignment - 1)) != 0) {
		return false;
	}

	unsigned long long last = current + size - 1;
	if (last < current) {
		return false;
	}

	return true;
}