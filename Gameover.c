#include "dimimarble.h"

void Game_over_print(int a,int turnplayer) { //������ ������ ���۵Ǵ� ����Ʈ �Լ��Դϴ�.
	setcolor(31, 32);
	system("cls");
		gotoxy(WIDTH / 2 -30, HEIGHT / 2 -10);
		setcolor(31, 31);
		printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		gotoxy(WIDTH / 2 -30 , HEIGHT / 2 + 10);
		printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		for (int i = -10; i <= 10; i++)
		{
			gotoxy(WIDTH / 2 - 30, HEIGHT / 2 + i);
			printf("aa");
			gotoxy(WIDTH / 2 + 30, HEIGHT / 2 + i);
			printf("aa");
		}
		setcolor(31, 32);
	gotoxyP(WIDTH / 2-5, HEIGHT / 2-3, "Game Finished");
	char chTemp[100];
	if (a == 1) //4���� if���� ���� ������ ���� ������ ���
	{
		sprintf(chTemp, "%s (��)�� ���д��߽��ϴ�. ", player[turnplayer - 1].name);
	}
	else if (a == 2)
	{
		sprintf(chTemp, "������� 1���� ���� %s (��)�� ������ �ǹ��� ���������մϴ�. ", player[turnplayer - 1].name);
	}
	else if (a == 3)
	{
		sprintf(chTemp, "%s (��)�� ������ �������ϴ�. ", player[turnplayer - 1].name);
	}
	else if (a == 4)
	{
		sprintf(chTemp, "%s (��)�� ������ �����ϴ�. ", player[turnplayer - 1].name);
	}
	if (a == 4) {
		gotoxyP(WIDTH / 2 - 10, HEIGHT / 2 + 2, chTemp);
		setcolor(32, 7);
		sprintf(chTemp, "%s �¸� !!!  ", player[(turnplayer+1)%2].name); // ���� �̰���� ���
		gotoxyP(WIDTH / 2 - 7, HEIGHT / 2 + 4, chTemp);
	}
	else {
		gotoxyP(WIDTH / 2 - 14, HEIGHT / 2 + 2, chTemp);
		setcolor(32, 7);
		sprintf(chTemp, "%s �¸� !  ", player[(turnplayer) % 2].name); // ���� �̰���� ���
		gotoxyP(WIDTH / 2 - 7, HEIGHT / 2 + 4, chTemp);
	}
	if(a == 1 || a ==2 || a == 3)
		PlaySound(TEXT("Game_Over.wav"), 0, SND_FILENAME | SND_ASYNC);
	else
		PlaySound(TEXT("Applause.wav"), 0, SND_FILENAME | SND_ASYNC);
}

int RE_GAME() { //return 1�� �ٽ� ����, return 0 �� ���� ��
	char n;
	while (1) {
		setcolor(31, 32);	
		gotoxyS(WIDTH / 2 - 13, HEIGHT / 2 + 6, "�ٽ� �����ϰڽ��ϱ�? (���ڸ� �Է��ϼ���)");
		gotoxyP(WIDTH / 2 - 10, HEIGHT / 2 + 7, "1. ��            2. �ƴϿ�");
		gotoxy(WIDTH / 2 - 10, HEIGHT / 2 + 8);
		while (_kbhit()) {
			_getch();
		}
		n = _getch(); //�ٽ� �����ϴ� ������ 2���� �Է��� �޽��ϴ�.
		while (_kbhit()) {
			_getch();
		}
		if (n == '1')
			return 1; // 1 ��ȯ�� �ٽ� ����
		else if (n == '2')
			return 0; // 0��ȯ�� ���� ������ ����.
		else { // ������ ���� �ٸ� ���� �Է½� �ٽ� �Է� �޽��ϴ�.
			setcolor(32, 31);
			gotoxyS(WIDTH / 2 - 7, HEIGHT / 2 + 8, "�ٽ� �Է��ϼ���");
			Sleep(300);
			setcolor(31, 32);
			gotoxyS(WIDTH / 2 - 7, HEIGHT / 2 + 8, "                       ");
		}
	}
	
}