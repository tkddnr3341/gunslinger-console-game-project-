int item()
{
	int y_location = 0;
	int dead_location = 20;
	int cols_deadline = 80;
	int x_location = rand() % (cols_deadline+1);
	
	gotoxy(x_location,y_location);
	setColor(yellow, black);
	printf("*");
	
	while (y_location < dead_location) {
		gotoxy(x_location, y_location);
		printf(" ");
		x_location += 1;
		y_location += 1;
		gotoxy(x_location, y_location);
		setColor(yellow, black);
		printf("*");
		switch (x_location) {
		case x_location >= cols_deadline: {
			gotoxy(x_location, y_location);
			printf(" ");
			x_location -= 1;
			y_location += 1;
			gotoxy(x_location, y_location);
			setColor(yellow, black);
			printf("*");
			break;
		}
		case x_location <= 0: {
			gotoxy(x_location, y_location);
			printf(" ");
			x_location += 1;
			y_location += 1;
			gotoxy(x_location, y_location);
			setColor(yellow, black);
			printf("*");
			break;
		}
		}
	}

	return 0;
}
