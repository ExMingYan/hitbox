#pragma once
struct RecordFrame
{
	unsigned int body : 1;			//身位框
	unsigned int norhit : 1;		//受击
	unsigned int cast : 1;			//被投
	unsigned int guard : 1;			//防御
	unsigned int down : 1;			//倒地
	unsigned int ofo : 1;			//抵消飞行道具
	unsigned int rfo : 1;			//反弹飞行道具
	unsigned int guardpoint : 1;	//当身
	unsigned int flyobjpoint : 1;	//对飞行道具当身
	unsigned int throwpoint : 1;	//对投当身
	unsigned int noratk : 1;		//普通攻击
	unsigned int flyobj : 1;		//飞行道具
	unsigned int throwatk : 1;		//投技
	unsigned int force : 1;			//强制命中
	unsigned int causeguard : 1;	//引发防御
	unsigned int crawl : 1;			//抓取
	unsigned int cancel : 1;		//可取消
	unsigned int timepause : 1;		//时间暂停
	unsigned int summonobj : 1;		//生成飞行道具
};