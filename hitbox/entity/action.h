#pragma once
#include "attack.h"

enum class CategoryID : int32_t
{
	Stand = 0x0,
	Crouch = 0x1,
	OnAir = 0x2,
	FaceUpFall = 0x3,
	FaceDownFall = 0x4,
	FlyObject = 0x6,
};

enum class SubCategoryID : int32_t
{
	Normal,
	Attack,
	BeAttack,
	Defense,
	Fallen1,
	Fallen2,
	Kneel,
	Throw,
	BeThrown,
};

enum class ActionLineID : int32_t
{
	Body = 0x3,							//身位框
	Hit = 0x4,							//受击框
	Attack = 0x5,						//攻击框
};

enum class CollisionTypes : int32_t
{
	body = 0x0,
	normal = 0x1,							//受击框
	capture = 0x2,							//被投框
	guard = 0x3,							//防御框
	ground = 0x4,							//地面受击框
	negative = 0x5,							//抵消飞行道具框
	reflects = 0x6,							//反弹飞行道具框
	invulnerability = 0x7,					//霸体框
	parries = 0x8,							//当身框
	avoid = 0x9,							//回避触发框
	parriesex = 0xA,						//投技当身框
	none = 0x9999
};

struct HitRect
{
	float x;
	float y;
	float w;
	float h;
};

struct Collision
{
	int32_t RectID;
	union {
		int32_t RectAttr;
		CollisionTypes Type;
	};
	int32_t Flag;
	int32_t BranchKey;
	int32_t BindIndex;
	float PushRate;
	HitRect rect;
};

struct Attack
{
	int32_t DataID;
	int32_t GroupID;
	HitRect rect;
	int32_t Flag;
};

struct ActionStructure
{
	int32_t frame;
	union {
		Collision collision;
		Attack attack;
	};
};
static_assert(sizeof(ActionStructure) == 0x2C, "Size check");

struct ActionLine
{
	unsigned int capacity;
	ActionLineID ActionLineID;
	ActionStructure* actions;
};
static_assert(sizeof(ActionLine) == 0x10, "Size check");

struct actions_entry							//动作实体类
{
	CategoryID CategoryID;						//0x0；姿势
	SubCategoryID SubCategoryID;				//0x4；动作类型
	int max;									//0x08；动作最大帧数
	int reset;									//0x0C；动作重置帧数
	void* _0x10;								//0x10
	void* _0x18;								//0x18
	int unknown4;								//0x20
	int capacity;								//0x24；ACT指针集内指针数
	ActionLine* actcs;							//0x28；ACT指针集
};
static_assert(sizeof(actions_entry) == 0x30, "Size check");

struct actions									//动作集
{
	char _0x0[0x20];							//0x0
	actions_entry* entry;						//0x20
	void* hold;									//0x28
};
static_assert(sizeof(actions) == 0x30, "Size check");
