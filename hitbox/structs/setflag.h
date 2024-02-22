#pragma once

struct BSet_Flag
{
	int frame;
	unsigned __int64 flag;
	char fill[0x20];
};
static_assert(sizeof(BSet_Flag) == 0x2C, "Size check");

struct CSet_Flag
{
	int frame;
	unsigned __int64 flag;
	char fill[0x20];
};
static_assert(sizeof(CSet_Flag) == 0x2C, "Size check");