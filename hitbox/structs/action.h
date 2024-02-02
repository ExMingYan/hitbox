#pragma once
#include "body.h"
#include "attack.h"
#include "affected.h"

enum class  Action_Types : int
{
	BodyBoxs = 0x3,								//身位框；0x3
	AffectedBoxs = 0x4,							//受击框；0x4
	AttackBoxs = 0x5,							//攻击框；0x5
};

struct Action_Collections						//ACT指针集
{
	unsigned int capacity;						//0x0 总帧数；指针指向内容总大小 = TotalFrame * 0x2C
	Action_Types types;							//0x4 ACT类型；决定指针指向的内容
	union
	{
		Attack_Boxs* attack;
		Body_Boxs* body;
		Affected_Boxs* affected;
	};
};
static_assert(sizeof(Action_Collections) == 0x10, "Size check");

struct ATK_Collections
{
	Attack_Types types;							//0x0；招式类型
	int level;									//0x4；招式等级
	int damage;									//0x8；招式伤害
	int damagelimit;							//0xC；招式保底伤害
	int guarddamagelimit;						//0x10；招式命中防御保底伤害
	int stun;									//0x14；造成晕值
	int guard;									//0x18；造成破防值
	int selfaddpower;							//0x1C；自身指定加气量
	int oppoaddpower;							//0x20；对方指定加气量
	char fill[0x1A4];
};
static_assert(sizeof(ATK_Collections) == 0x1C8, "Size check");

struct Actions_Entry							//动作实体类
{
	void* unknown1;								//0x0
	int mar;									//0x08；动作最大帧数
	int reset;									//0x0C；动作重置帧数
	void* unknown2;								//0x10
	void* unknown3;								//0x18
	int unknown4;								//0x20
	int capacity;								//0x24；ACT指针集内指针数
	Action_Collections* actcs;					//0x28；ACT指针集
};
static_assert(sizeof(Actions_Entry) == 0x30, "Size check");

struct Attacks
{
	char unknown[0x20];
	ATK_Collections* atkcs;
};

struct Actions									//动作集
{
	char unknown[0x20];							//0x0
	Actions_Entry* entry;						//0x20
	void* hold;									//0x28
};
