#pragma once
#include "action.h"

struct Flight_Props_List
{
	Flight_Props_List* next;	//0x0
	void* hold;					//0x8
	Player* props;		//0x10
};

struct Flight_Props_Header
{
	char hold[0x30];
	Flight_Props_List* list;		//0x30
};
