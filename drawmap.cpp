void drawMap(int* pX, int* pY, char(*tMap)[40])
{
	char temp;
	system("cls");
	int h, w;
	for (h = 0; h 80; h++)
	{
		for (w = 0; w < 40; w++)
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
				printf("□");
			}
			else if (temp == 's')
			{
				//플레이어 X,Y 위치 저장
				*pX = w;
				*pY = h;
				setColor(cyan, black);
				printf("@");
			}
			else if (temp == '4')
			{
				setColor(red, black);
				printf("-");
			}
			
		}
		printf("\n");
	}
	setColor(white, black);