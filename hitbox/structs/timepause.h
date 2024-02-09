#pragma once

enum class Pause_Set
{
	Unpause = 0x0,
	Pause0 = 0x1,
	Pause1 = 0x2,
	Pause2 = 0x3,
	Pause3 = 0x4,
};

struct Time_Pause {
	unsigned int frame;
	Pause_Set pauset;
	int unknown;
	unsigned int pauseframe;
	char unknown2[0x1C];
};
static_assert(sizeof(Time_Pause) == 0x2C, "Size check");