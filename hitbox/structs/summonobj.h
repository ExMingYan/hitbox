#pragma once

struct Summon_Object
{
	unsigned int frame;
	void* unknown;
	float summonxoff;
	float summonyoff;
	int unknown2;
	__int16 hitimes;
	__int16 action;
	unsigned int flag;
	char unknown4[0xC];
};
static_assert(sizeof(Summon_Object) == 0x2C, "Size check");