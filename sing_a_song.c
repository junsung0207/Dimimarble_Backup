#include "dimimarble.h"

int print_Song() { // �뷡�� ���߸� 1 Ʋ���� 0�� ��ȯ
	int k, n, w;
	Board_Middle_clear();
	setcolor(31, 5);
	gotoxyS(40, 8, "~ ������ �������� �뷡 ���� ~");
	setcolor(4, 31);
	gotoxyS(35, 12, "������ �����Ϸ��� �����̽��ٸ� ��������.");
	gotoxy(45, 13);
	Sleep(100);
	while (1) { //Ű���� �Է��� �޽��ϴ�. �����̽��� ���� �� while �� Ż��
		k = _getch();
		if (k == 32)
			break;
	}
	Board_Middle_clear();
	Sleep(1000);
	gotoxyS(33, 8, "�뷡�� ������ �ش� �뷡 ��ȣ�� �Է����ּ���!");
	Sleep(1000);
	setcolor(32, 31);
	gotoxyS(36, 14, "1");
	gotoxyS(50, 14, "2");
	gotoxyS(64, 14, "3");
	Sleep(1000);
	int rn;
	rn = rand() % 3; //�뷡�� �������� ���ɴϴ�.
	if (rn == 0) {
		gotoxyP(33, 10, "1�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(36, 14, "1");
		PlaySound(TEXT("Bomnal.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(36, 14, "1");

		gotoxyP(33, 10, "2�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(50, 14, "2");
		PlaySound(TEXT("Chicha.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(50, 14, "2");

		gotoxyP(33, 10, "3�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(64, 14, "3");
		PlaySound(TEXT("energetic.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(64, 14, "3");
		setcolor(32, 31);
		gotoxyS(33, 10, "                                     ");
		gotoxyP(33, 10, "����� - ���� �� �����ϱ��?");
		w = 1;
		while (w) { //�뷡�� ���ߴ� while �� �Դϴ�.
			gotoxy(50, 11);
			scanf("%d", &n);
			if (n == 1 || n == 3)
			{
				gotoxyP(33, 10, "�� ! �����Դϴ� !!!!                 ");
				Sleep(2500);
				return 0;
			}
			else if (n == 2)
			{
				gotoxyP(33, 10, "�����Դϴ� !!                        ");
				PlaySound(TEXT("right.wav"), 0, SND_FILENAME | SND_ASYNC);
				Sleep(2500);
				return 1;
			}
			else {
				gotoxyS(50, 11, "                               ");
				setcolor(31, 32);
				gotoxyS(45, 12, "�ٽ� �Է����ּ���.");
				Sleep(300);
				setcolor(32, 31);
				gotoxyS(45, 12, "                            ");
			}
		}
	}
	else if (rn == 1)
	{
		gotoxyP(33, 10, "1�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(36, 14, "1");
		PlaySound(TEXT("instagram.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(36, 14, "1");

		gotoxyP(33, 10, "2�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(50, 14, "2");
		PlaySound(TEXT("Jogni.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(50, 14, "2");

		gotoxyP(33, 10, "3�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(64, 14, "3");
		PlaySound(TEXT("Pidam.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(64, 14, "3");
		setcolor(32, 31);
		gotoxyS(33, 10, "                                     ");
		gotoxyP(33, 10, "��ź�ҳ�� - �Ƕ������� �����ϱ��?");
		w = 1;
		while (w) {
			gotoxy(50, 11);
			scanf("%d", &n);
			if (n == 1 || n == 2)
			{
				gotoxyP(33, 10, "�� ! �����Դϴ� !!!!                         ");
				Sleep(2500);
				return 0;
			}
			else if (n == 3)
			{
				gotoxyP(33, 10, "�����Դϴ� !!                              ");
				Sleep(2500);
				return 1;
			}
			else {
				gotoxyS(50, 11, "                               ");
				setcolor(31, 32);
				gotoxyS(45, 12, "�ٽ� �Է����ּ���.");
				Sleep(300);
				setcolor(32, 31);
				gotoxyS(45, 12, "                            ");
			}
		}
	}
	else
	{
		gotoxyP(33, 10, "1�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(36, 14, "1");
		PlaySound(TEXT("Present.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(36, 14, "1");

		gotoxyP(33, 10, "2�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(50, 14, "2");
		PlaySound(TEXT("rc.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(50, 14, "2");

		gotoxyP(33, 10, "3�� �뷡�Դϴ�.");
		setcolor(31, 9);
		gotoxyS(64, 14, "3");
		PlaySound(TEXT("soy.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(64, 14, "3");
		setcolor(32, 31);
		gotoxyS(33, 10, "                                     ");
		gotoxyP(33, 10, "û�� - �ѷ��ڽ��ʹ� �����ϱ��?");
		w = 1;
		while (w) {
			gotoxy(50, 11);
			scanf("%d", &n);
			if (n == 1 || n == 3)
			{
				gotoxyP(33, 10, "�� ! �����Դϴ� !!!!                          ");
				Sleep(2500);
				return 0;
			}
			else if (n == 2)
			{
				gotoxyP(33, 10, "�����Դϴ� !!                             ");
				Sleep(2500);
				return 1;
			}
			else {
				gotoxyS(50, 11, "                               ");
				setcolor(31, 32);
				gotoxyS(45, 12, "�ٽ� �Է����ּ���.");
				Sleep(300);
				setcolor(32, 31);
				gotoxyS(45, 12, "                            ");
			}
		}
	}
}