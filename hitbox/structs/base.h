#pragma once

struct Action_Table
{
	int action;
};

struct Base_Info
{
	char unknown[0x1C];
	int capacity;
	char unknown2[0x18];
	float Aswitchdistance;
	float Bswitchdistance;
	float Cswitchdistance;
	float Dswitchdistance;
	char unknown3[0xA8];
	Action_Table* actiontable;
};