#pragma once

enum class Attack_Typs : int			//����������
{
	NormalAttack,						//��ͨ������0x0
	FlyingObject,						//���е��ߣ�0x1
	ThrowSkill,							//Ͷ����0x2
	ForcedHit,							//ǿ�����У�0x3
	Unkown,								//0x4
	CauseGuard							//����������0x5
};

struct Attack_Boxs							//������ÿ֡ռ��0x2C�ֽ�
{
	unsigned int frame;					//ƫ��0x00
	unsigned int atk;					//ƫ��0x04����ӦATK���
	unsigned int hit;					//ƫ��0x08������Hit��
	float x;							//ƫ��0x0C
	float y;							//ƫ��0x10
	float w;							//ƫ��0x14
	float h;							//ƫ��0x18
	unsigned int flag;					//ƫ��0x1C��bit 8����ȭ/�ؽŵĹ������б�ʾ��һ֡ΪCͶ/DͶ���ж���
	char unknown[0xc];
};
static_assert(sizeof(Attack_Boxs) == 0x2C, "Size check");
