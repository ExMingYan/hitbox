#pragma once

struct Body_Boxs						//ÉíÎ»¿ò½á¹¹£»Ã¿Ö¡Õ¼ÓÃ0x2C×Ö½Ú
{
	unsigned int frame;					//Æ«ÒÆ0x00£»Ö¡Êý
	unsigned int fill1;					//Æ«ÒÆ0x04
	unsigned int fill2;					//Æ«ÒÆ0x08
	unsigned int fill3;					//Æ«ÒÆ0x0C
	unsigned int fill4;					//Æ«ÒÆ0x10
	int isaddoffset;					//Æ«ÒÆ0x14
	unsigned int fill5;					//Æ«ÒÆ0x18
	float x;							//Æ«ÒÆ0x1C
	float y;							//Æ«ÒÆ0x20
	float w;							//Æ«ÒÆ0x24
	float h;							//Æ«ÒÆ0x28
};
static_assert(sizeof(Body_Boxs) == 0x2C, "Size check");
