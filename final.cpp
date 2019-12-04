#include <stdio.h>
#include <stdlib.h>
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
int title(void);
void init();
void gotoxy(int, int);
void makeTarget(int count, int* px, int* py);
int check(int count, int element, int num, int* p);
int fall(int count, int* px, int* py);
void startgame(int* px, int* py);
int info();

int location1 = 0;
int dead_location = 35;
int wavenumber = 1;
int count = 0;

int main(void)
{
	int menucode;
	int* p_tlx;
	int* p_tly;
	p_tlx = (int*)malloc(SIZE * LINES * sizeof(int));
	p_tly = (int*)malloc(SIZE * LINES * sizeof(int));
	for (int i = 0; i < SIZE * LINES; i++)
	{
		p_tlx[i] = 0;
		p_tly[i] = 0;
	}
	init();
	while (1)
	{
		menucode = title();
		if (menucode == 0)
		{
			startgame(p_tlx, p_tly);
			for (int i = 0; i < SIZE * LINES; i++)
			{
				p_tlx[i] = 0;
				p_tly[i] = 0;
			}
			continue;
		}

		else if (menucode == 1)
		{
			info();
			continue;
		}

		else if (menucode == 2)
		{
			system("cls");
			printf("������ �����մϴ�.");
			return 0;
		}
		else
			break;
	}
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

int title()
{
	int input;
	int pointer_x = 31;
	int pointer_y = 22;

	printf("\n\n\n\n");
	printf("   #####  #    #  ##    #    ####  #     ###  ##    #  #####  #####  #####       \n");
	printf("   #      #    #  # #   #   #      #      #   # #   #  #      #      #    #      \n");
	printf("   #  ##  #    #  #  #  #   ####   #      #   #  #  #  #  ##  ####   #####       \n");
	printf("   #   #  #    #  #   # #       #  #      #   #   # #  #   #  #      #  #        \n");
	printf("   #####   ####   #    ##   ####   ##### ###  #    ##  #####  #####  #    #      \n");

	gotoxy(33, 22);
	printf("start game");
	gotoxy(33, 24);
	printf("game info");
	gotoxy(33, 26);
	printf("exit game");
	gotoxy(31, 22);
	printf(">");
	while (1)
	{
		input = keyControl();
		switch (input)
		{
		case UP:
		{
			if (pointer_y > 22)
			{
				gotoxy(pointer_x, pointer_y);
				printf(" ");
				pointer_y -= 2;
				gotoxy(pointer_x, pointer_y);
				printf(">");
				break;;
			}
			else
			{
				break;;
			}
		}

		case DOWN:
		{
			if (pointer_y < 26)
			{
				gotoxy(pointer_x, pointer_y);
				printf(" ");
				pointer_y += 2;
				gotoxy(pointer_x, pointer_y);
				printf(">");
				break;
			}
			else
			{
				break;
			}
		}
		case SUBMIT:
		{
			if (pointer_y == 22)
			{
				return 0;
			}
			else if (pointer_y == 24)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		default:
			break;
		}
	}
}

void player()
{
	gotoxy(location1, LINES - 1);
	printf("@");
	int key = keyControl();
	switch (key)
	{
	case LEFT:
	{
		if (location1 > 0)
		{
			gotoxy(location1, LINES - 1);
			printf(" ");
			location1 -= 1;
			gotoxy(location1, LINES - 1);
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
		if (location1 < COLS - 1)
		{
			gotoxy(location1, LINES - 1);
			printf(" ");
			location1 += 1;
			gotoxy(location1, LINES - 1);
			printf("@");
			break;
		}

		else if (location1 == COLS - 1)
		{
			break;
		}
	}

	default:
		break;
	}
}

void makeTarget(int count, int* px, int* py)
{
	int result = 0, random;
	srand(time(NULL));
	for (int i = SIZE * count; i < SIZE * (count + 1); i++)
	{
		if (i > SIZE * count)
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
		printf("��");
		*(py + i) += 1;
	}
}

int check(int count, int element, int num, int* p)
{
	int result = 1;
	for (int i = SIZE * count; i < num; i++)
	{
		result *= (element - *(p + i));
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

int fall(int count, int* px, int* py)
{
	for (int i = 0; i < SIZE * (1 + count); i++)
	{
		gotoxy(*(px + i), *(py + i) - 1);
		printf(" ");
		gotoxy(*(px + i), *(py + i));
		printf("��");
		*(py + i) += 1;
		if (*(py + i) == dead_location)
			return 0;
	}
	return 1;
}

void startgame(int* px, int* py)
{
	int playing = 1;
	system("cls");
	gotoxy(0, dead_location);
	for (int i = 0; i < COLS; i++)
	{
		printf("-");
	}
	while (playing == 1)
	{
		makeTarget(count, px, py);
		playing = fall(count, px, py);
		count += 1;
		Sleep(500);
	}
	system("cls");
	printf("\n\n\n\n");
	printf("   #####     #     ##       ## #####       ####    #        # ##### #####    \n");
	printf("   #        # #    # #     # # #         ##    ##   #      #  #     #    #   \n");
	printf("   #  ##   #####   #  #   #  # #####     #      #    #    #   ##### #####    \n");
	printf("   #   #  #     #  #   # #   # #         ##    ##     #  #    #     #  #     \n");
	printf("   ##### #       # #    ##   # #####       ####        #      ##### #    #   \n");
	count = 0;
	Sleep(500);
	system("cls");
}

int info()
{
	int input;
	system("cls");
	printf("\n\n");
	printf("                                  [ ���۹� ]\n\n");
	printf("                         �̵�: ����-'A' ������-'D'\n");
	printf("                              �Ѿ�: �����̽���\n\n\n\n\n\n\n");
	printf("                   �������� ������ Ÿ�ٵ��� ��� ������ϴ�.\n");
	printf("                         ������: ����, �迹�� �̹ο�\n");
	printf("                �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.\n");
	input = keyControl();
	while (input != SUBMIT)
	{
		input = keyControl();
	}
	return 0;
}