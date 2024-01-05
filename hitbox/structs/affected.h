#pragma once

enum class  Affected_Types :int
{
	NormalHitBox = 0x1,						//0x01���ܻ���
	CastBox = 0x2,							//0x02����Ͷ��
	GuardBox = 0x3,							//0x03��������
	DownHitBox = 0x4,						//0x04�������ܻ���
	OffsetFlyingObjectBox = 0x5,			//0x05���������е��߿�
	ReboundFlyingObjectBox = 0x6,			//0x06���������е��߿�
	TyrantsBox = 0x7,						//0x07�������
	GuardPointBox = 0x8,					//0x08�������
};

struct Affected_Boxs						//�ܻ���ṹ��ÿ֡ռ��0x2C�ֽ�
{
	unsigned int frame;						//ƫ��0x00��֡��
	unsigned int fill1;						//ƫ��0x04
	Affected_Types types;					//ƫ��0x08���ܻ�������
	unsigned int flag;						//ƫ��0x0C��Flag�ڲ�ͬ���͵��ܻ����ж�Ӧ�Ĺ��ܲ�һ��
	unsigned int fill2;						//ƫ��0x10
	unsigned int fill3;						//ƫ��0x14
	unsigned int fill4;						//ƫ��0x18
	float x;								//ƫ��0x1C
	float y;								//ƫ��0x20
	float w;								//ƫ��0x24
	float h;								//ƫ��0x28
};
static_assert(sizeof(Affected_Boxs) == 0x2C, "Size check");
