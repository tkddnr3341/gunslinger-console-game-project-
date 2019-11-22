#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void player();
int keyControl(void);
void titleDraw(void);
void init();
void gotoxy(int, int);
int location = 0;

int main(void)
{
	init();
	titleDraw();
	system("cls");
	while (1)
	{
		player();
	}
}

void init(void)
{
	system("mode con cols=30 lines=40 | title Escape Game");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

	pKey = 0;
	playing = 1;

}


void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


int keyControl(void) {
	char temp = _getch();

	if (temp == 'w' || temp == 'W')
	{
		return UP;
	}
	else if (temp == 'a' || temp == 'A')
	{
		return LEFT;
	}
	else if (temp == 's' || temp == 'S')
	{
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D')
	{
		return RIGHT;
	}
	else if (temp == ' ')
	{ 
		return SUBMIT;
	}
}


void titleDraw(void) 
{
	printf("\n\n\n\n"); 
	printf("   #####  #    #  ##    #    ####  #     ###  ##    #  #####  #####  ####       \n");
	printf("   #      #    #  # #   #   #      #      #   # #   #  #      #      #   #      \n");
	printf("   #  ##  #    #  #  #  #   ####   #      #   #  #  #  #  ##  ####   ####       \n");
	printf("   #   #  #    #  #   # #       #  #      #   #   # #  #   #  #      #   #      \n");
	printf("   #####   ####   #    ##   ####   ##### ###  #    ##  #####  #####  #   #     \n");
}


void player()
{
	gotoxy(location, 39);
	printf("@");
	gotoxy(10, 10);
	int key = keyControl();
	switch(key)
	{
		case LEFT:
		{
			if (location >0)
			{
				gotoxy(location, 39);
				printf(" ");
				location -= 1;
				gotoxy(location, 39);
				printf("@");
				break;
			}
			else if (location == 0)
			{
				break;
			}
		}
		case RIGHT:
		{
			if (location <29)
			{	
				gotoxy(location, 39);
				printf(" ");
				location += 1;
				gotoxy(location, 39);
				printf("@");
				break;
			}
			else if (location = 29)
			{
				break;
			}
		}
		default:
			break;
	}
}
