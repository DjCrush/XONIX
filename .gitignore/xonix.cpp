#include <stdio.h>
#include <conio.h>
#include "video.h"
#include "image.h"
#include "keyboard.h"
#include "sprite.h"
#include "game.h"
#include "balls.h"

///////////////////// GLOBAL VARIABLES ////////////////////////////////////////////////////////////////////////////
Image *font;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Player{
	int x, y, dir_x, dir_y;
} player = {40, 0, 0, 0};


struct {
	int x, y, dir_x, dir_y;
} Enemy;


int main(void)
{
	unsigned char key;
	int i;
	int flag_draw = 0;
	Set_Video_Mode(0x13);
	font = Load_Image("font16.bmp");


	Game();
}
