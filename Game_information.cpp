void infoDraw(void)
{
	system("cls"); 
	printf("\n\n");
	printf("                        [ ���۹� ]\n\n");
	printf("                    �̵�: ����-'A' ������-'D'\n");
	printf("                    �Ѿ�: �����̽���\n\n\n\n\n\n\n");
	printf("         �������� ������ Ÿ�ٵ��� ��� ������ϴ�.");
	printf("               ������: ����, �迹�� �̹ο�");
	printf("      �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}