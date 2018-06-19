#include "video.h"


char *video_buffer = (char far *)0xA0000000L;

void Set_Video_Mode(int mode)
{
	asm mov ax,mode;
	asm int 0x10;
}

void Create_Palette()
{
	REGPACK regs;
	char blue[]= {0, 50,  0, 63,  0, 50,  0, 50, 0, 63,  0, 63,  0, 63,  0, 63};
	char red[]=  {0,  0, 50, 63,  0,  0, 50, 50, 0,  0, 63, 63,  0,  0, 63, 63};
	char green[]={0,  0,  0,  0, 50, 50, 50, 50, 0,  0,  0, 31, 63, 63, 63, 63};
	for(int c=0;c<16;c++)
	{
		regs.r_ax = 0x1010;
		regs.r_bx = c;
		regs.r_cx = (red[c]<<8)+green[c];
		regs.r_dx = blue[c]<<8;
		intr(0x10, &regs);
	}
}

void Wait_Vertical_Retrace()
{
	do{
	}while(!(inportb(0x3da)&8));
}

