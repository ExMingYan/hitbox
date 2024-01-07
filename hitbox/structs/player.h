#pragma once
#include "action.h"

struct Attack_Type_Collections
{
	Attack_Types types;
	char unknown[0x1C0];
};
static_assert(sizeof(Attack_Type_Collections) == 0x1C4, "Size check");

struct Attacks
{
	char unknown[0x20];
	Attack_Type_Collections* atkcs;
};

_declspec(align(8))
struct Player
{
	char unknown1[0x38];		//0x0
	Actions* acts;				//0x38
	char unknown2[0x28];		//0x40
	Attacks* atks;				//0x68
	char fill[0x30];			//0x70
	float x;					//0xa0
	float y;					//0xa4
	char unknown3[0x34];		//0xa8
	float xoff;					//0xDC
	float yoff;					//0xE0
	char fill2[0x70];			//0xE4
	int toward;					//0x154：面向
	int unknown4;				//0x158
	int unknown5;				//0x15c
	int unknown6;				//0x160
	int unknown7;				//0x164
	int number;					//0x168
	int unknown8;				//0x16c
	int now;					//0x170: 正在执行帧数
};
