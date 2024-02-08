#pragma once

struct Command
{
	unsigned int commands;
	bool ispkpressmt;
	unsigned int unknown;
	unsigned int chargeframe;
	unsigned __int64 unknown2;
};
static_assert(sizeof(Command) == 0x18, "Size check");

struct Command_Table
{
	unsigned int capacity;
	unsigned int unknown;
	Command* command;
};
static_assert(sizeof(Command_Table) == 0x10, "Size check");

enum class Move_Level : int
{
	SpK = 0xE,
	SpM = 0xF,
	EXSpM = 0x10,
	SSpM = 0x11,
	EXSSpM = 0x12,
	Neo = 0x13,
	SpKC = 0x14,
	SpMC = 0x15,
	EXSpMC = 0x16,
	SSpMC = 0x17,
	EXSSpMC = 0x18,
	NeoC = 0x19
};

struct Move_Info
{
	unsigned int commandid;
	Move_Level level;
	char unknown[0x14];
	int needpower;
	char unknown2[0x8];
	unsigned int flag;
	int action;
	char unknown3[0x14];
};
static_assert(sizeof(Move_Info) == 0x44, "Size check");

struct CCommand
{
	char unknown[0x1C];
	int moveinfocapacity;
	int commandtablecapacity;
	Move_Info* moveinfo;
	Command_Table* commandtable;
};