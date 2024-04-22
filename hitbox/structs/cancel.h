#pragma once
#pragma pack(push,4)
struct DetailCTable
{
	int frame;							//0x00
	unsigned int move : 1;				//0x04
	unsigned int run : 1;
	unsigned int backjump : 1;
	unsigned int jump1 : 1;
	unsigned int shadowjump : 1;
	unsigned int jump2 : 1;
	unsigned int standA : 1;
	unsigned int standB : 1;
	unsigned int standC : 1;
	unsigned int standD : 1;
	unsigned int downA : 1;
	unsigned int downB : 1;
	unsigned int downC : 1;
	unsigned int downD : 1;
	unsigned int standCD : 1;
	unsigned int jumpA : 1;
	unsigned int jumpB : 1;
	unsigned int jumpC : 1;
	unsigned int jumpD : 1;
	unsigned int jumpCD : 1;
	unsigned int redBC : 1;
	unsigned int specialmove : 1;
	unsigned int level5 : 1;			//含粉碎打击
	unsigned int level6 : 1;
	unsigned int level7 : 1;
	unsigned int level8 : 1;
	unsigned int level9 : 1;
	unsigned int shaStrike : 1;
	unsigned int taunt : 1;
	unsigned int advStrike : 1;
	unsigned int forevasion : 1;
	unsigned int backevasion : 1;
	unsigned __int8 forevasiong : 1;	//0x08
	unsigned __int8 backevasiong : 1;
	unsigned __int8 guardCD : 1;
	unsigned __int8 blueBC : 1;
	unsigned __int8 suffer : 1;
	unsigned __int8 RC0 : 1;
	unsigned __int8 RC1 : 1;
	unsigned __int8 RC2 : 1;
	unsigned __int8 RC3A;
	unsigned __int16 RCB1A;
	unsigned int RC1B3A;				//0x0C
	unsigned int needhit;				//是否需要命中才可取消；0x10
	unsigned int RC3B5A;				//0x14
	int advframe;						//可提前输入指令帧数；0x18
	unsigned int RC5B7A;				//0x1C
	unsigned int RC7B9A;				//0x20
	unsigned int RC9BBA;				//0x24
	unsigned int RCBBDA;				//0x28
};

struct CancelTable
{
	int frame;							//0x00
	unsigned int flag1;					//0x04
	unsigned int flag2;					//0x08
	unsigned int flag3;					//0x0C
	unsigned int needhit;				//0x10
	unsigned int flag4;					//0x14
	int advframe;						//0x18
	unsigned int flag5;					//0x1C
	unsigned int flag6;					//0x20
	unsigned int flag7;					//0x24
	unsigned int flag8;					//0x2C
};
#pragma pack(pop)