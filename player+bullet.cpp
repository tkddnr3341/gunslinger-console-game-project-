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


int px = 15;
int py = 37;
int bx = 0;
int by = 0;
bool bullet = false;

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
	gotoxy(px, py);
	printf("бу");
	int key = keyControl();
	switch (key)
	{
	case LEFT:
	{
		if (px > 0)
		{
			gotoxy(px, py);
			printf(" ");
			px -= 1;
			gotoxy(px, py);
			printf("бу");
			break;
		}
		else if (px == 0)
		{
			break;
		}
	}
	case RIGHT:
	{
		if (px < 29)
		{
			gotoxy(px, py);
			printf(" ");
			px += 1;
			gotoxy(px, py);
			printf("бу");
			break;
		}
		else if (px = 29)
		{
			break;
		}

	case SUBMIT:
	{
		int bx = px;
		int by = py - 1;
		bullet = true;

		if (bullet)
		{
			bx = px;
			by = py - 1;
			while (1) {
				
				gotoxy(bx, by);
				printf("б┌");
				by--;
				Sleep(40);
				gotoxy(bx, by + 1);
				printf("    ");
				
				Sleep(25);

				if (by == 1) {
					break;
				}

			}
		}
		
	}
	

	}
	default:
		break;
	}
}