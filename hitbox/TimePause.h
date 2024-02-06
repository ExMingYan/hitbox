#pragma once

struct Time_Pause {
	unsigned int frame;
	int pauset;
	char unknown[0x24];
};
static_assert(sizeof(Time_Pause) == 0x2C, "Size check");