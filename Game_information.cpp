void infoDraw(void)
{
	system("cls"); 
	printf("\n\n");
	printf("                        [ 조작법 ]\n\n");
	printf("                    이동: 왼쪽-'A' 오른쪽-'D'\n");
	printf("                    총알: 스페이스바\n\n\n\n\n\n\n");
	printf("         아이템을 먹으면 타겟들이 모두 사라집니다.");
	printf("               개발자: 김상욱, 김예린 이민욱");
	printf("      스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}