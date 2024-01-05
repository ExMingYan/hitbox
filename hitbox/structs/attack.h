#pragma once

enum class Attack_Typs : int			//攻击框类型
{
	NormalAttack,						//普通攻击；0x0
	FlyingObject,						//飞行道具；0x1
	ThrowSkill,							//投技；0x2
	ForcedHit,							//强制命中；0x3
	Unkown,								//0x4
	CauseGuard							//引发防御；0x5
};

struct Attack_Boxs							//攻击框；每帧占用0x2C字节
{
	unsigned int frame;					//偏移0x00
	unsigned int atk;					//偏移0x04；对应ATK编号
	unsigned int hit;					//偏移0x08；所属Hit数
	float x;							//偏移0x0C
	float y;							//偏移0x10
	float w;							//偏移0x14
	float h;							//偏移0x18
	unsigned int flag;					//偏移0x1C；bit 8在重拳/重脚的攻击框中表示这一帧为C投/D投的判定框
	char unknown[0xc];
};
static_assert(sizeof(Attack_Boxs) == 0x2C, "Size check");
