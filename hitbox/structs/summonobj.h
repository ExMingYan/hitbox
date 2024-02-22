#pragma once

struct Summon_Object
{
	int frame;
	void* unknown;
	float summonxoff;
	float summonyoff;
	__int16 unknown2;
	__int16 summonorder;
	__int16 hitimes;
	__int16 action;
	unsigned int flag;
	char unknown4[0xC];
};
static_assert(sizeof(Summon_Object) == 0x2C, "Size check");