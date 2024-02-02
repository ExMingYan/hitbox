#pragma once
#include "action.h"

_declspec(align(8))
struct Player
{
	void** vtbl;				//0x0
	char unknown1[0x30];		//0x8
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
	char unknown9[0x30C];		//0x174
	unsigned int propsflag;		//0x480
	char unknownA[0x27C];		//0x484
	unsigned __int64 flag;		//0x700
	char unknownB[0xD4];		//0x708
	int correctvalue;			//0x7DC；修正次数
	char unknownC[0x4C];		//0x7E0
	int leadframe;				//0x82C；领先帧数
	char unknownD[0x28];		//0x830
	int avoidhit;				//0x858；免打帧数
	int avoidthrow;				//0x85C；免投帧数
};
