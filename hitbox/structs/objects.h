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
	char unknown4[0x14];				//0x3C
	Player* b1;							//0x50
	Player* b2;							//0x58
	char unknown5[0x665F0];				//0x60
	Flight_Props_Header* props_list;	//0x66650
	char unknown6[0x124];				//0x66658
	unsigned int PausePlayer;			//0x6677C；被时停方，bit2为1P，bit3为2P
	unsigned __int64 unknown7;			//0x66780
	signed int respauseframe;			//0x66788；剩余时停帧数
	char unknown8[0x4EB4];				//0x6678C
	unsigned int ready;					//0x6B640
};