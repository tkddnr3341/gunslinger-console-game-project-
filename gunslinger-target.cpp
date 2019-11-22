int target()
{
	int location = 0;
	int dead_location = 20;
	gotoxy(0, location);
	printf("####");
	while (location < dead_location)
	{
		Sleep(100);
		gotoxy(0, location);
		printf("    ");
		location += 1;
		gotoxy(0, location);
		printf("@@@@");
	}
	return 0;
}