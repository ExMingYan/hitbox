#pragma once

enum class  Affected_Types :int
{
	NormalHitBox = 0x1,						//0x01；受击框
	CastBox = 0x2,							//0x02；被投框
	GuardBox = 0x3,							//0x03；防御框
	DownHitBox = 0x4,						//0x04；倒地受击框
	OffsetFlyingObjectBox = 0x5,			//0x05；抵消飞行道具框
	ReboundFlyingObjectBox = 0x6,			//0x06；反弹飞行道具框
	TyrantsBox = 0x7,						//0x07；霸体框
	GuardPointBox = 0x8,					//0x08；当身框
};

struct Affected_Boxs						//受击框结构；每帧占用0x2C字节
{
	unsigned int frame;						//偏移0x00；帧数
	unsigned int fill1;						//偏移0x04
	Affected_Types types;					//偏移0x08；受击框类型
	unsigned int flag;						//偏移0x0C；Flag在不同类型的受击框中对应的功能不一样
	unsigned int fill2;						//偏移0x10
	unsigned int fill3;						//偏移0x14
	unsigned int fill4;						//偏移0x18
	float x;								//偏移0x1C
	float y;								//偏移0x20
	float w;								//偏移0x24
	float h;								//偏移0x28
};
static_assert(sizeof(Affected_Boxs) == 0x2C, "Size check");
