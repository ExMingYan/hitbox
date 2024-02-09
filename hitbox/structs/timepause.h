#pragma once

enum class Pause_Set
{
	Unpause = 0x0,
	Pause1 = 0x3,
	Pause2 = 0x4,
};

struct Time_Pause {
	unsigned int frame;
	Pause_Set pauset;
	char unknown[0x24];
};
static_assert(sizeof(Time_Pause) == 0x2C, "Size check");