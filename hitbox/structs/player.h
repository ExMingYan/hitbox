#pragma once
#include "action.h"

_declspec(align(8))
struct Player
{
	char unknown1[0x38];		//0x0
	Actions* acts;				//0x38
	char unknown2[0x60];		//0x40
	float x;					//0xa0
	float y;					//0xa4
	char unknown3[0xac];		//0xa8
	int toward;					//0x154：面向
	int unknown4;				//0x158
	int unknown5;				//0x15c
	int unknown6;				//0x160
	int unknown7;				//0x164
	int number;					//0x168
	int unknown8;				//0x16c
	int now;					//0x170: 正在执行帧数
};
