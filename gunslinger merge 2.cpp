#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <sys/timeb.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define SIZE 6

void player();
int keyControl(void);
void titleDraw(void);
void init();
void gotoxy(int, int);
void target();

int t_location_y[SIZE] = { 0,0,0,0,0,0 };
int t_location_x[SIZE] = {};
int* px;
int *py;

int location1 = 0;
int dead_location = 30;
int pKey;
int playing;

int main(void)
{
	int time = 0;
	int key;
	init();
	titleDraw();
	Sleep(800);
	system("cls");
	playing = 1;
	target();
	return 0;
}

void init(void)
{
	system("mode con cols=80 lines=40 | title Gunslinger Game");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
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

int keyControl(void)
{
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
	gotoxy(location1, 39);
	printf("@");
	int key = keyControl();
	switch (key)
	{
	case LEFT:
	{
		if (location1 > 0)
		{
			gotoxy(location1, 39);
			printf(" ");
			location1 -= 1;
			gotoxy(location1, 39);
			printf("@");
			break;
		}

		else if (location1 == 0)
		{
			break;
		}
	}

	case RIGHT:
	{
		if (location1 < 29)
		{
			gotoxy(location1, 39);
			printf(" ");
			location1 += 1;
			gotoxy(location1, 39);
			printf("@");
			break;
		}

		else if (location1 == 29)
		{
			break;
		}
	}

	default:
		break;
	}

}

void target()
{
	int dead_location = 30;
	gotoxy(0, dead_location);
	printf("####");

	py = t_location_y;
	px = t_location_x;
	for (int i = 0;i < SIZE; i++)
	{
		srand(time(NULL));
		int random = rand() / 40;
		*(px + 1) = random;
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d " % (*(px+i)));
		printf("%d\n",%()
	}
	while (1)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (*(py + i) > 0)
			{
				gotoxy(*(px + i), *(py + i) - 1);
				printf(" ");
			}
			gotoxy(*(px + i), *(py + i));
			printf("º");
			*(py + i) += 1;
			if (*(py + i) == dead_location)
				break;
			Sleep(50);
		}
	}
	system("cls");
	printf("게임을 종료합니다.");
}