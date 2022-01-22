#include "dimimarble.h"

int print_Song() { // 노래를 맟추면 1 틀리면 0을 반환
	int k, n, w;
	Board_Middle_clear();
	setcolor(31, 5);
	gotoxyS(40, 8, "~ 이택주 선생님의 노래 교실 ~");
	setcolor(4, 31);
	gotoxyS(35, 12, "게임을 시작하려면 스페이스바를 누르세요.");
	gotoxy(45, 13);
	Sleep(100);
	while (1) { //키보드 입력을 받습니다. 스페이스바 누를 시 while 문 탈출
		k = _getch();
		if (k == 32)
			break;
	}
	Board_Middle_clear();
	Sleep(1000);
	gotoxyS(33, 8, "노래가 나오면 해당 노래 번호를 입력해주세요!");
	Sleep(1000);
	setcolor(32, 31);
	gotoxyS(36, 14, "1");
	gotoxyS(50, 14, "2");
	gotoxyS(64, 14, "3");
	Sleep(1000);
	int rn;
	rn = rand() % 3; //노래가 랜덤으로 나옵니다.
	if (rn == 0) {
		gotoxyP(33, 10, "1번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(36, 14, "1");
		PlaySound(TEXT("Bomnal.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(36, 14, "1");

		gotoxyP(33, 10, "2번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(50, 14, "2");
		PlaySound(TEXT("Chicha.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(50, 14, "2");

		gotoxyP(33, 10, "3번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(64, 14, "3");
		PlaySound(TEXT("energetic.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(64, 14, "3");
		setcolor(32, 31);
		gotoxyS(33, 10, "                                     ");
		gotoxyP(33, 10, "우원재 - 시차 는 무엇일까요?");
		w = 1;
		while (w) { //노래를 맞추는 while 문 입니다.
			gotoxy(50, 11);
			scanf("%d", &n);
			if (n == 1 || n == 3)
			{
				gotoxyP(33, 10, "땡 ! 오답입니다 !!!!                 ");
				Sleep(2500);
				return 0;
			}
			else if (n == 2)
			{
				gotoxyP(33, 10, "정답입니다 !!                        ");
				PlaySound(TEXT("right.wav"), 0, SND_FILENAME | SND_ASYNC);
				Sleep(2500);
				return 1;
			}
			else {
				gotoxyS(50, 11, "                               ");
				setcolor(31, 32);
				gotoxyS(45, 12, "다시 입력해주세요.");
				Sleep(300);
				setcolor(32, 31);
				gotoxyS(45, 12, "                            ");
			}
		}
	}
	else if (rn == 1)
	{
		gotoxyP(33, 10, "1번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(36, 14, "1");
		PlaySound(TEXT("instagram.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(36, 14, "1");

		gotoxyP(33, 10, "2번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(50, 14, "2");
		PlaySound(TEXT("Jogni.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(50, 14, "2");

		gotoxyP(33, 10, "3번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(64, 14, "3");
		PlaySound(TEXT("Pidam.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(64, 14, "3");
		setcolor(32, 31);
		gotoxyS(33, 10, "                                     ");
		gotoxyP(33, 10, "방탄소년단 - 피땀눈물은 무엇일까요?");
		w = 1;
		while (w) {
			gotoxy(50, 11);
			scanf("%d", &n);
			if (n == 1 || n == 2)
			{
				gotoxyP(33, 10, "땡 ! 오답입니다 !!!!                         ");
				Sleep(2500);
				return 0;
			}
			else if (n == 3)
			{
				gotoxyP(33, 10, "정답입니다 !!                              ");
				Sleep(2500);
				return 1;
			}
			else {
				gotoxyS(50, 11, "                               ");
				setcolor(31, 32);
				gotoxyS(45, 12, "다시 입력해주세요.");
				Sleep(300);
				setcolor(32, 31);
				gotoxyS(45, 12, "                            ");
			}
		}
	}
	else
	{
		gotoxyP(33, 10, "1번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(36, 14, "1");
		PlaySound(TEXT("Present.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(36, 14, "1");

		gotoxyP(33, 10, "2번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(50, 14, "2");
		PlaySound(TEXT("rc.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(50, 14, "2");

		gotoxyP(33, 10, "3번 노래입니다.");
		setcolor(31, 9);
		gotoxyS(64, 14, "3");
		PlaySound(TEXT("soy.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(3000);
		setcolor(32, 31);
		gotoxyS(64, 14, "3");
		setcolor(32, 31);
		gotoxyS(33, 10, "                                     ");
		gotoxyP(33, 10, "청하 - 롤러코스터는 무엇일까요?");
		w = 1;
		while (w) {
			gotoxy(50, 11);
			scanf("%d", &n);
			if (n == 1 || n == 3)
			{
				gotoxyP(33, 10, "땡 ! 오답입니다 !!!!                          ");
				Sleep(2500);
				return 0;
			}
			else if (n == 2)
			{
				gotoxyP(33, 10, "정답입니다 !!                             ");
				Sleep(2500);
				return 1;
			}
			else {
				gotoxyS(50, 11, "                               ");
				setcolor(31, 32);
				gotoxyS(45, 12, "다시 입력해주세요.");
				Sleep(300);
				setcolor(32, 31);
				gotoxyS(45, 12, "                            ");
			}
		}
	}
}