#pragma once
#include "action.h"
#include "base.h"
#include "command.h"

_declspec(align(8))
struct Player
{
	void** vtbl;				//0x0
	char unknown1[0x30];		//0x8
	Actions* acts;				//0x38
	char unknown2[0x28];		//0x40
	Attacks* atks;				//0x68
	char fill[0x28];			//0x70
	Player* propsmaster;		//0x98
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
	int nowframe;				//0x170: 正在执行帧数
	char unknown6[0x20];		//0x174
	float exespeed;				//0x194
	char unknown7[0x218];		//0x198
	unsigned int hitflag;		//0x3B0
	char fill3[0xC];			//0x3B4
	unsigned int flag;			//0x3C0
	char unknown8[0x2C];		//0x3C4
	unsigned int flag2;			//0x3F0
	char unknown9[0x1C];		//0x3F4
	Base_Info* baseinfo;		//0x410
	char unknownA[0x16];		//0x418
	__int16 propsorder;			//0x42E
	char unknownB[0x4C];		//0x430
	int sumpropaction;			//0x47C；生成飞行道具的动作代码
	unsigned int propsflag;		//0x480
	char unknownC[0x1A4];		//0x484
	CCommand* cmd1;				//0x628
	char unknownD[0x68];		//0x630
	CCommand* cmd2;				//0x698
	char unknownE[0x60];		//0x6A0
	unsigned __int64 flag3;		//0x700
	char unknownF[0xD4];		//0x708
	int correctvalue;			//0x7DC；修正次数
	char unknown10[0x4C];		//0x7E0
	int leadframe;				//0x82C；领先帧数
	int unknown11;				//0x830
	int occframe;				//0x834；发生帧数
	int OnAirCanBeHitFrame;		//0x838；浮空可受击帧数
	int OnGroundCanBeHitFrame;	//0x83C；地面可受击帧数
	char unknown12[0x18];		//0x840
	int avoidhit;				//0x858；免打帧数
	int avoidthrow;				//0x85C；免投帧数
};
