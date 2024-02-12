#pragma once

enum class Pause_Set
{
	Unpause = 0x0,
	Unpause2 = 0x1,
	Pauself = 0x2,
	Pauself2 = 0x3,
	PauseOppo = 0x4,
	PauseOppo2 = 0x5,
};

struct Time_Pause {
	unsigned int frame;
	Pause_Set pauset;
	int unknown;
	unsigned int pauseframe;
	char unknown2[0x1C];
};
static_assert(sizeof(Time_Pause) == 0x2C, "Size check");