#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <thread>
#include <iostream>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4
#define SIZE 3
#define COLS 92
#define LINES 40

void player();
int keyControl(void);
int title(void);
void init();
void gotoxy(int, int);
void setColor(int foreground, int background);
void makeTarget(int count, int* px, int* py);
int check(int count, int element, int num, int* p);
int fall(int count, int* px, int* py);
void target(int* px, int* py);
void playgame(int* px, int* py, int* php);
int info();
void drawMap(int* pX, int* pY, char(*tMap)[92]);
int move(char(*tMap)[92], int* pX, int* pY, int _x, int _y, int* pKey);
void gLoop(void);


enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

char map[40][92] = {

	{"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},//0:�����
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},// 1 : ��
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},// 4 : deadline
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1444444444444444444444444444444444444444444444444444444444444444444444444444444444444444441"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"},
    {"100000000000000000000000000000000000000000s0000000000000000000000000000000000000000001"},
    {"1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"}
};
int location1 = 40;
int dead_location = 35;
int wavenumber = 1;
int count = 0;
int bx = 40;
int by = 0;

int main(void)
{
	int menucode;
	int target_location_x[SIZE * LINES] = {};
	int target_location_y[SIZE * LINES] = {};
	int* p_tlx;
	int* p_tly;
	int target_hp[SIZE * LINES] = {};
	int* p_thp;
	p_tlx = target_location_x;
	p_tly = target_location_y;
	p_thp = target_hp;
	for (int i = 0; i < SIZE * LINES; i++)
	{
		p_tlx[i] = 0;
		p_tly[i] = 0;
		p_thp[i] = 1;
	}
	init();
	while (1)
	{
		menucode = title();
		if (menucode == 0)
		{
			gLoop();
			playgame(p_tlx, p_tly, p_thp);
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

void drawMap(int* pX, int* pY, char(*tMap)[92])
{
	char temp;
	system("cls");
	int h, w;
	for (h = 0; h < 40; h++)
	{
		for (w = 0; w < 92; w++)
		{
			temp = tMap[h][w];
			if (temp == '0')
			{
				setColor(black, black);
				printf(" ");
			}
			else if (temp == '1')
			{
				setColor(white, white);
				printf("#");
			}
			else if (temp == 's')
			{
				//�÷��̾� X,Y ��ġ ����
				*pX = w;
				*pY = h;
				setColor(green, black);
				printf("��ݡ�");
			}
			else if (temp == '4')
			{
				setColor(red, black);
				printf("=");
			}

		}
		printf("\n");
	}
	setColor(white, black);
}

void init(void)
{
	system("mode con cols=92 lines=40 | title Gunslinger Game");
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

void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

int title()
{
	int input;
	int pointer_x = 36;
	int pointer_y = 28;
	setColor(yellow, black);

	printf("\n\n\n\n\n");
	printf("                          �ââââ�  ��     ��  �â�    �� \n");
	printf("                          ��          ��     ��  �� ��   �� \n");
	printf("                          ��    �â�  ��     ��  ��  ��  �� \n");
	printf("                          ��      ��  ��     ��  ��   �� �� \n");
	printf("                          �ââââ�   �ââ�    ��    �â� \n");


	printf("\n\n\n\n");

	printf("    �âââ�  ��        �ââ�  �â�    ��  �ââââ�  �âââ�  �âââ�   �âââ�      \n");
	printf("   ��         ��          ��    �� ��   ��  ��          ��        ��         ��     ��     \n");
	printf("    �âââ�  ��          ��    ��  ��  ��  ��    �â�  �ââ�    �âââ�   �âââ�      \n");
	printf("          ��  ��          ��    ��   �� ��  ��      ��        ��  ��         ��     ��     \n");
	printf("   �âââ�   �âââ�  �ââ�  ��    �â�  �ââââ�  �âââ�  �âââ�   ��     ��     \n");

	setColor(white, black);

	gotoxy(38, 28);
	printf("start game");
	gotoxy(38, 30);
	printf("game info");
	gotoxy(38, 32);
	printf("exit game");
	gotoxy(36, 28);
	printf(">");
	while (1)
	{
		input = keyControl();
		switch (input)
		{
		case UP:
		{
			if (pointer_y > 28)
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
			if (pointer_y < 32)
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
			if (pointer_y == 28)
			{
				return 0;
			}
			else if (pointer_y == 30)
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

void gLoop(void)
{
	int mKey;
	int cX, cY;
	int cKey = 0;
	int playing = 1;
	char tempMap[40][92]; // �� �ӽ������� �迭  

	memcpy(tempMap, map, sizeof(tempMap));

	drawMap(&cX, &cY, tempMap);
	while (playing)
	{
		
		mKey = keyControl();
		switch (mKey)
		{
		case RIGHT:
			playing = move(tempMap, &cX, &cY, 1, 0, &cKey);
			break;
		case LEFT:
			playing = move(tempMap, &cX, &cY, -1, 0, &cKey);
			break;
		}

	}
	//playing = 1;
}

int move(char(*tMap)[92], int* pX, int* pY, int _x, int _y, int* pKey)
{
	int playflag = 1;
	char mapObject = tMap[*pY + _y][*pX + _x];
	setColor(white, black);


	if (mapObject == '0')
	{
		gotoxy(*pX, *pY);
		printf(" ");

		setColor(green, black);
		gotoxy(*pX + _x, *pY + _y);
		printf("��ݡ�");
		*pX += _x;
		*pY += _y;
	}
	//	else if (mapObject == '1')
	//	{
			// �ƹ��ϵ� ���� ����
	//	}
	return playflag;
}

void player()
{
	system("cls");
	setColor(lightblue, black);
	gotoxy(location1, LINES - 1);
	printf("��ݡ�");
	int key = keyControl();
	switch (key)
	{
	case LEFT:
	{

		if (location1 > 0)
		{
			gotoxy(location1, LINES - 1);
			printf("    ");
			location1 -= 1;
			gotoxy(location1, LINES - 1);
			printf("��ݡ�");
			break;
		}

		else if (location1 == 0)
		{
			break;
		}
	}

	case RIGHT:
	{
		if (location1 < COLS - 6)
		{
			gotoxy(location1, LINES - 1);
			printf("      ");
			location1 += 1;
			gotoxy(location1, LINES - 1);
			printf("��ݡ�");
			break;
		}

		else if (location1 == COLS - 6)
		{
			break;
		}
	}

	case SUBMIT:
	{
		int bx = location1 + 2;
		int by = LINES - 2;
		gotoxy(bx, by);
		printf("��");
		while (by != 0)
		{
			gotoxy(bx, by);
			printf("    ");
			by -= 2;
			gotoxy(bx, by);
			printf("��");
			Sleep(25);
		}
		gotoxy(bx, by);
		printf("  ");
		break;
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
				random = 2 * (rand() % ((COLS - 2) / 2)) + 1;
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
		setColor(green, black);
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
		*(py + i) += 2;
		if (*(py + i) == dead_location)
			return 0;
	}
	return 1;
}

void target(int* px, int* py)
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

void playgame(int* px, int* py, int* php)
{
	while (1)
	{
		player();
	}
}

int info()
{
	int input;
	system("cls");
	printf("\n\n");
	printf("                                  [ ���۹� ]\n\n");
	printf("                         �̵�: ����-'A' ������-'D'\n");
	printf("                              �Ѿ�: �����̽���\n\n\n\n\n\n\n");
	printf("                Ÿ���� deadline�� ������ ������ ����˴ϴ�.\n\n");
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
