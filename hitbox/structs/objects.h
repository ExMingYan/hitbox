#pragma once
#include "player.h"
#include "props.h"

#pragma pack(push,4)
struct Objects
{
	char unknown1[0x18];				//0x0
	Player* p1;							//0x18
	Player* p2;							//0x20
	void* unknown2;						//0x28
	void* unknown3;						//0x30
	__int32 complete;					//0x38
	char unknown4[0x14];				//0x3C
	Player* b1;							//0x50
	Player* b2;							//0x58
	char unknown5[0x665F0];				//0x60
	Flight_Props_Header* props_list;	//0x66650
	char unknown6[0x124];				//0x66658
	unsigned __int32 PausePlayer1;		//0x6677C；1P引发时停，只判断bit2和bit3
	void *unknown7;						//0x66780
	signed __int32 respauseframe1;		//0x66788；1P引发时停剩余帧数
	char unknown8[0x20];				//0x6678C
	unsigned __int32 unknown9;			//0x667AC
	unsigned __int32 PausePlayer2;		//0x667B0；2P引发时停，只判断bit2和bit3
	void *unknownA;						//0x667B4
	signed __int32 respauseframe2;		//0x667BC；2P引发时停剩余帧数
	char unknownB[0x4E80];				//0x667C0
	unsigned __int32 ready;				//0x6B640
};
#pragma pack(pop)