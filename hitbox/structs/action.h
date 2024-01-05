#pragma once
#include "body.h"
#include "attack.h"
#include "affected.h"

enum class  Action_Types : int
{
	BodyBoxs = 0x3,								//��λ��0x3
	AffectedBoxs = 0x4,							//�ܻ���0x4
	AttackBoxs = 0x5,							//������0x5
};

struct Action_Collections						//ACTָ�뼯
{
	unsigned int capacity;						//0x0 ��֡����ָ��ָ�������ܴ�С = TotalFrame * 0x2C
	Action_Types types;							//0x4 ACT���ͣ�����ָ��ָ�������
	union
	{
		Attack_Boxs* attack;
		Body_Boxs* body;
		Affected_Boxs* affected;
	};
};
static_assert(sizeof(Action_Collections) == 0x10, "Size check");

struct Actions_Entry							//����ʵ����
{
	void* unknown1;								//0x0
	int mar;									//0x08���������֡��
	int reset;									//0x0C����������֡��
	void* unknown2;								//0x10
	void* unknown3;								//0x18
	int unknown4;								//0x20
	int capacity;								//0x24��ACTָ�뼯��ָ����
	Action_Collections* actcs;					//0x28��ACTָ�뼯
};
static_assert(sizeof(Actions_Entry) == 0x30, "Size check");

struct Actions									//������
{
	char unknown[0x20];							//0x0
	Actions_Entry* entry;						//0x20
	void* hold;									//0x28
};
