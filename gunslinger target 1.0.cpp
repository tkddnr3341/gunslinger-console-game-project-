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
#define SIZE 6
#define COLS 80
#define LINES 40

void player();
int keyControl(void);
void titleDraw(void);
void init();
void gotoxy(int, int);
void makeTarget(int count);
int check(int count,int element,int num,int *p);
int fall(int count);

int t_location_y[SIZE*LINES] = { };
int t_location_x[SIZE*LINES] = { };
int *px;
int *py;

int location1 = 0;
int dead_location = 35;

int main(void)
{
	int count=0,playing=1;
	init();
	titleDraw();
	Sleep(800);
	system("cls");
	gotoxy(0, dead_location);
	for (int i = 0; i < 80; i++)
	{
		printf("-");
	}
	py = t_location_y;
	px = t_location_x;
	while (playing == 1)
	{
		makeTarget(count);
		playing=fall(count);
		count += 1;
		Sleep(200);
	}
	system("cls");
	printf("게임이 종료되었습니다.");
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
	gotoxy(location1, LINES-1);
	printf("@");
	int key = keyControl();
	switch (key)
	{
	case LEFT:
	{
		if (location1 > 0)
		{
			gotoxy(location1, LINES-1);
			printf(" ");
			location1 -= 1;
			gotoxy(location1, LINES-1);
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
		if (location1 < COLS-1)
		{
			gotoxy(location1, LINES-1);
			printf(" ");
			location1 += 1;
			gotoxy(location1, LINES-1);
			printf("@");
			break;
		}

		else if (location1 == COLS-1)
		{
			break;
		}
	}

	default:
		break;
	}

}

void makeTarget(int count)
{
	int result=0,random;
	srand(time(NULL));
	for (int i = SIZE * count; i < SIZE * (count + 1); i++)
	{
		if (i > SIZE*count)
		{
			while (result == 0)
			{
				random = rand() % COLS;
				result = check(count, random, i, px);
			}
		}
		else
		{
			random = rand() % COLS;
		}
		*(px + i) = random;
		result = 0;
	}

	for (int i = SIZE * count; i < SIZE * (count + 1); i++)
	{
		gotoxy(*(px + i), *(py + i));
		printf("º");
		*(py + i) += 1;
	}
}

int check(int count,int element, int num, int *p)
{
	int result=1;
	for (int i = SIZE*count; i < num; i++)
	{
		result *= (element - *(p+i));
	}
	if (result == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int fall(int count)
{
	for (int i = 0; i < SIZE*(1+count); i++)
	{
		gotoxy(*(px + i), *(py + i) - 1);
		printf(" ");
		gotoxy(*(px + i), *(py + i));
		printf("º");
		*(py + i) += 1;
		if (*(py + i) == dead_location)
			return 0;
	}
	return 1;
}

