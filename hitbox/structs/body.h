#pragma once

struct Body_Boxs						//��λ��ṹ��ÿ֡ռ��0x2C�ֽ�
{
	unsigned int frame;					//ƫ��0x00��֡��
	unsigned int fill1;					//ƫ��0x04
	unsigned int fill2;					//ƫ��0x08
	unsigned int fill3;					//ƫ��0x0C
	unsigned int fill4;					//ƫ��0x10
	int isaddoffset;					//ƫ��0x14
	unsigned int fill5;					//ƫ��0x18
	float x;							//ƫ��0x1C
	float y;							//ƫ��0x20
	float w;							//ƫ��0x24
	float h;							//ƫ��0x28
};
static_assert(sizeof(Body_Boxs) == 0x2C, "Size check");
