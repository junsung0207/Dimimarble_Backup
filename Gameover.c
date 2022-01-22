#include "dimimarble.h"

void Game_over_print(int a,int turnplayer) { //게임이 끝날시 시작되는 프린트 함수입니다.
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
	if (a == 1) //4개의 if문을 통해 게임이 끝난 이유를 출력
	{
		sprintf(chTemp, "%s (이)가 퇴학당했습니다. ", player[turnplayer - 1].name);
	}
	else if (a == 2)
	{
		sprintf(chTemp, "재수한지 1년이 넘은 %s (이)가 병역의 의무를 짊어져야합니다. ", player[turnplayer - 1].name);
	}
	else if (a == 3)
	{
		sprintf(chTemp, "%s (이)가 명문대을 못갔습니다. ", player[turnplayer - 1].name);
	}
	else if (a == 4)
	{
		sprintf(chTemp, "%s (이)가 명문대을 갔습니다. ", player[turnplayer - 1].name);
	}
	if (a == 4) {
		gotoxyP(WIDTH / 2 - 10, HEIGHT / 2 + 2, chTemp);
		setcolor(32, 7);
		sprintf(chTemp, "%s 승리 !!!  ", player[(turnplayer+1)%2].name); // 누가 이겼는지 출력
		gotoxyP(WIDTH / 2 - 7, HEIGHT / 2 + 4, chTemp);
	}
	else {
		gotoxyP(WIDTH / 2 - 14, HEIGHT / 2 + 2, chTemp);
		setcolor(32, 7);
		sprintf(chTemp, "%s 승리 !  ", player[(turnplayer) % 2].name); // 누가 이겼는지 출력
		gotoxyP(WIDTH / 2 - 7, HEIGHT / 2 + 4, chTemp);
	}
	if(a == 1 || a ==2 || a == 3)
		PlaySound(TEXT("Game_Over.wav"), 0, SND_FILENAME | SND_ASYNC);
	else
		PlaySound(TEXT("Applause.wav"), 0, SND_FILENAME | SND_ASYNC);
}

int RE_GAME() { //return 1은 다시 시작, return 0 은 게임 끝
	char n;
	while (1) {
		setcolor(31, 32);	
		gotoxyS(WIDTH / 2 - 13, HEIGHT / 2 + 6, "다시 시작하겠습니까? (숫자를 입력하세요)");
		gotoxyP(WIDTH / 2 - 10, HEIGHT / 2 + 7, "1. 예            2. 아니요");
		gotoxy(WIDTH / 2 - 10, HEIGHT / 2 + 8);
		while (_kbhit()) {
			_getch();
		}
		n = _getch(); //다시 시작하는 선택지 2개의 입력을 받습니다.
		while (_kbhit()) {
			_getch();
		}
		if (n == '1')
			return 1; // 1 반환시 다시 시작
		else if (n == '2')
			return 0; // 0반환시 게임 완전히 끝남.
		else { // 선택지 외의 다른 숫자 입력시 다시 입력 받습니다.
			setcolor(32, 31);
			gotoxyS(WIDTH / 2 - 7, HEIGHT / 2 + 8, "다시 입력하세요");
			Sleep(300);
			setcolor(31, 32);
			gotoxyS(WIDTH / 2 - 7, HEIGHT / 2 + 8, "                       ");
		}
	}
	
}