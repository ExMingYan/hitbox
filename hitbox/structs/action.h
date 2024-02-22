#pragma once
#include "affected.h"
#include "attack.h"
#include "body.h"
#pragma pack(push,4)
#include "setflag.h"
#include "summonobj.h"
#include "timepause.h"
#pragma pack(pop)

enum class  ACT_Types : int
{
	BodyBoxs = 0x3,								//身位框；0x3
	AffectedBoxs = 0x4,							//受击框；0x4
	AttackBoxs = 0x5,							//攻击框；0x5
	BSetFlag = 0xB,								//向Player+0x328写入Flag；0xB
	CSetFlag = 0xC,								//向Player+0x330写入Flag；0xC
	TimePause = 0x13,							//时停与解除时停；0x13
	SummonObject = 0x15							//生成飞行道具；0x15
};

enum class Action_Types : int
{
	Normal = 0x0,								//普通
	Attack = 0x1,								//攻击
	Affect = 0x2,								//受击
	Guard = 0x3,								//防御
	Fell1 = 0x4,								//倒地
	Fell2 = 0x5,								//倒地
	Throw = 0x7,								//投技
	Voted = 0x8									//被投
};

struct Action_Collections						//ACT指针集
{
	int capacity;						//0x0 总帧数；指针指向内容总大小 = TotalFrame * 0x2C
	ACT_Types types;							//0x4 ACT类型；决定指针指向的内容
	union
	{
		Attack_Boxs* attack;
		Body_Boxs* body;
		Affected_Boxs* affected;
		BSet_Flag* bsetflag;
		CSet_Flag* csetflag;
		Time_Pause* timepause;
		Summon_Object* sumobj;
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
	int unknown1;								//0x0
	Action_Types types;							//0x4
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
	char unknown[0x1C];
	int capacity;								//0x1C；ATK总数
	ATK_Collections* atkcs;
};

struct Actions									//动作集
{
	char unknown[0x1C];							//0x0
	int capacity;								//0x1C；动作代码总数
	Actions_Entry* entry;						//0x20
	void* hold;									//0x28
};
