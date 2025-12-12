#pragma once

enum class AttackTypes : int			//攻击框类型
{
	normal = 0x0,					//普通攻击
	projectile = 0x1,				//飞行道具
	grasp = 0x2,					//投技
	force = 0x3,					//强制命中
	guard = 0x5,					//引发防御

	none = 0x9999
};

struct attack_collections
{
	AttackTypes types;
	int level;				//招式等级
	int damage;				//伤害
	int minimum;			//最低伤害
	int penetrate;			//穿透伤害
	int stun;				//晕值
	int loss;				//破防
	int selfaddpower;		//
	int oppoaddpower;
	char fill[0x1A4];
};
static_assert(sizeof(attack_collections) == 0x1C8, "Size check");

struct attacks
{
	char unknown[0x20];
	attack_collections* atccs;
};
