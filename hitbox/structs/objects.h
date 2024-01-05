#pragma once
#include "player.h"
#include "props.h"

struct Objects
{
	char unknown1[0x18];				//0x0
	Player* p1;							//0x18
	Player* p2;							//0x20
	void* unknown2;						//0x28
	void* unknown3;						//0x30
	int complete;						//0x38
	char unknown4[0x66610];
	Flight_Props_Header* props_list;	//0x66650
};