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
	char unknown4[0x10];		//0x158
	int action;					//0x168
	int unknown5;				//0x16c
	unsigned int nowframe;		//0x170: 正在执行帧数
	char unknown6[0x23C];		//0x174
	unsigned int hitflag;		//0x3B0
	char fill3[0xC];			//0x3B4
	unsigned int flag;			//0x3C0
	char unknown7[0x2C];		//0x3C4
	unsigned int flag2;			//0x3F0
	char unknown8[0x8C];		//0x3F4
	unsigned int propsflag;		//0x480
	char unknown9[0x27C];		//0x484
	unsigned __int64 flag3;		//0x700
	char unknownA[0xD4];		//0x708
	int correctvalue;			//0x7DC；修正次数
	char unknownB[0x4C];		//0x7E0
	int leadframe;				//0x82C；领先帧数
	char unknownC[0x28];		//0x830
	int avoidhit;				//0x858；免打帧数
	int avoidthrow;				//0x85C；免投帧数
};
