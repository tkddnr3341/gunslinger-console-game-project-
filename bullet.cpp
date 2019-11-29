void bullet()
{
	int key = keyControl();
	int yb_location = 39;
	switch (key)
	{
		case SUBMIT:
	{
			while (yb_location > 1)
			{
				gotoxy(location, yb_location);
				printf("*");
				Sleep(100);
				gotoxy(location, yb_location);
				printf(" ");
				yb_location -= 1;
				gotoxy(location, yb_location);
				printf("*");
				break;
			}
	}
	default:
		break;
	}
}
