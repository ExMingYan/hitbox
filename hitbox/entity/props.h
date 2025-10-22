#pragma once
#include "action.h"
#include "object.h"

_declspec(align(8))
struct projectile
{
	char _0x0[0x38];			//0x0
	actions* acts;				//0x38
	char _0x40[0x28];			//0x40
	attacks* atcs;				//0x68
	char _0x68[0x20];			//0x70
	object* enemy;				//0x90
	object* owner;				//0x98
	float x;					//0xa0
	float y;					//0xa4
	char unknown3[0xac];		//0xa8
	int toward;					//0x154：面向
	int _0x158;					//0x158
	int _0x15c;					//0x15c
	int _0x160;					//0x160
	int _0x164;					//0x164
	int number;					//0x168
	int _0x16c;					//0x16c
	int now;					//0x170: 正在执行帧数
	char _0x174[0x300];			//0x174
	int RemainingAttacks;		//0x474；剩余攻击次数
	void* _0x478;				//0x478
	__int8 _0x480;				//0x480
	bool isInvalidate;			//0x481；是否无效
	__int16 _0x482;				//0x482

	inline bool left() {
		return this->toward == 0;
	}
};

struct projectile_list
{
	projectile_list* next;	//0x0
	void* hold;					//0x8
	projectile* props;		//0x10
};

struct projectile_header
{
	char hold[0x30];
	projectile_list* list;	//0x30
};

struct proprange {
	float left;
	float top;
	float right;
	float bottom;

	proprange();
	proprange(projectile* obj, attack_boxs box, bool left);
	proprange(projectile* obj, body_boxs box, bool left);
	proprange(projectile* obj, affected_boxs box, bool left);
};
