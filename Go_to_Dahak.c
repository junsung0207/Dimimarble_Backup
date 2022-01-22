#include "dimimarble.h"

void boardingcolor(int n)
{
	n = n % 31 + 1;
	gotoxy(18, 7);
	setcolor(n, 31);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(18, 23);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	for (int i = 8; i <= 22; i++)
	{
		gotoxyP(18, i, "■");
		gotoxyP(94, i, "■");
	}
	setcolor(32, 31);
}

int Can_I_am_onAge(int turnplayer) { //대학을 갈수 있나없나의 여부 판단함수
	setcolor(32, 31);
	Assistant_Text_clear();
	if (turnplayer == 0)
	{
		if (P1_Life >= 2) {
			system_("대학을 갈 나이가 되었답니다 !");
			Sleep(2000);
			return 1;
		}

		else {
			system_("아직 대학을 갈 수 없어요 ㅠㅠ");
			Sleep(2000);
			return 0;
		}
	}
	else
	{
		if (P2_Life >= 2) {
			system_("대학을 갈 나이가 되었답니다 !");
			Sleep(2000);
			return 1;
		}

		else {
			system_("아직 대학을 갈 수 없어요 ㅠㅠ");
			Sleep(2000);
			return 0;
		}
	}
}

int Can_I_Go(int turnplayer) { //turnplayer = 0 또는 1 
	int n = 0, num = 0;
	setcolor(32, 31);
	Assistant_Text_clear();
	if (turnplayer == 0)
	{
		for (int i = 1; i < 20; i++) {
			if (i == 10)  continue;
			if (closeness[i] <= 50) n++;
		}
		if (n > 0) // 친밀도 50 넘는 사람이 한명 이상 있을 경우
		{
			gotoxyP(5, 34, "친밀도가 50이 넘은 사람 : ");
			for (int i = 0; i < 20; i++)
			{
				if (i == 10)  continue;
				if (closeness[i] <= 50 && num < 3) {
					printf("%s  ", T_name[i]);
					num++;
				}
				if (num == 3) //해당 선생님이 3명 이상 일 경우 뒷쪽 선생님은 ...으로 생략합니다.
					printf(" ...");
			}
			Sleep(3000);
			return 1;
		}
		else
			gotoxyP(5, 34, "친밀도가 50이 넘는 사람이 아무도 없습니다.");
		return 0;

	}
	else
	{
		for (int i = 1; i < 20; i++) {
			if (i == 10)  continue;
			if (closeness[i] >= 150) n++;
		}
		if (n > 0) // 친밀도 50 넘는 사람이 한명 이상 있을 경우
		{
			gotoxyP(5, 34, "친밀도가 50이 넘은 사람 : ");
			for (int i = 0; i < 20; i++)
			{
				if (i == 10)  continue;
				if (closeness[i] >= 150 && num < 3) {
					printf("%s  ", T_name[i]);
					num++;
				}
				if (num == 3) //이 또한 위와 마찬가지
					printf("...");
			}
			Sleep(3000);
			return 1;
		}
		else
			gotoxyP(5, 34, "친밀도가 50이 넘는 사람이 아무도 없습니다.");
		return 0;
	}
}

int Goto_Dahak(turnplayer) { //대학 가는 함수
	setcolor(32, 31);
	int k, n = 0;
	Board_Middle_clear();
	Assistant_Text_clear();
	PlaySound(TEXT("league.wav"), 0, SND_FILENAME | SND_ASYNC);
	gotoxyS(45, 8, "■ 대학 진학을 위한 여정 ■");
	setcolor(31, 5);
	int colorplus = 4;
	boardingcolor(colorplus);
	gotoxyP(20, 13, "당신의 추천서는 이분들이 써주셨습니다.");
	gotoxy(50, 14);
	printf(" => ");
	for (int i = 0; i < 20; i++)
	{
		if (i == 10)  continue;
		if (closeness[i] <= 50) {
			printf("%s  ", T_name[i]);
			n++;
			if (n > 5)
				gotoxy(20, 14);
		}
	}
	printf(" <= ");
	Sleep(3000);
	setcolor(31, 32);
	gotoxyP(43, 17, " 그러면 대학에 갈 준비가 되었습니까 ? ");
	Sleep(3000);
	gotoxyP(41, 17, " 준비가 되었다면 스페이스바를 눌러주세요 ");
	while (1) {
		k = _getch();
		if (k == 32)
			break;
	}

	setcolor(32, 31);
	Board_Middle_clear();
	gotoxyS(45, 8, "■ 대학 진학을 위한 여정 ■");
	gotoxyP(39, 17, " 선생님 추천서와 함께 대학 원서를 넣었습니다. "); //대학에 진학하는 과정을 출력해주는 함수
	boardingcolor(4);
	Sleep(2000);
	for (int i = 0; i < 2; i++)
	{
		gotoxyP(48, 20, "기다리는 중 .   ");
		printf("                          ");
		for (int m = 0; m < 7; m++)
		{
			for (i = 0; i < 15; i++) //로딩바가 진행됩니다 ~
			{
				gotoxy(34, 21);
				for (int j = 0; j < 15; j++)
				{
					if (j <= i)
					{
						printf("■ ");
					}
					else
					{
						printf("□ ");
					}
				}
				Sleep(10);
			}
		}
		gotoxyP(48, 20, "기다리는 중 .. ");
		printf("                          ");
		for (int m = 0; m < 7; m++)
		{
			for (i = 0; i < 15; i++) //로딩바가 진행됩니다 ~
			{
				gotoxy(34, 21);
				for (int j = 0; j < 15; j++)
				{
					if (j <= i)
					{
						printf("■ ");
					}
					else
					{
						printf("□ ");
					}
				}
				Sleep(10);
			}
		}
		gotoxyP(48, 20, "기다리는 중 ...");
		printf("                          ");
		for (int m = 0; m < 8; m++)
		{
			for (i = 0; i < 15; i++) //로딩바가 진행됩니다 ~
			{
				gotoxy(34, 21);
				for (int j = 0; j < 15; j++)
				{
					if (j <= i)
					{
						printf("■ ");
					}
					else
					{
						printf("□ ");
					}
				}
				Sleep(10);
			}
		}
		gotoxyP(34, 21, "                                            ");
	}
	gotoxyS(48, 20, "                               ");
	Sleep(1000);
	PlaySound(NULL, 0, 0);
	gotoxyP(39, 17, "결과가 나왔습니다 !                          ");
	Sleep(3000);
	gotoxyP(39, 17, "당신이 가게 된 대학은 ... !");
	Sleep(3000);
	int rn;
	rn = rand() % 6;//대학이 랜덤으로 지정됩니다 ! (게임의 재미있는 요소)
	rn = rand() % 6;
	rn = rand() % 6;
	rn = rand() % 6;
	rn = rand() % 6;

	gotoxyS(39, 17, "                                            ");
	if (rn == 0 || rn == 1 || rn == 2 || rn == 3)
	{
		if (rn == 0)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "당신은 성균관대에 합격했습니다 ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "축하드립니다 !!!");
			Sleep(5000);
			//성공시 return 0
			return 0;
		}
		else if (rn == 1)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "당신은 연세대에 합격했습니다 ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "축하드립니다 !!!");
			Sleep(5000);
			return 0;
		}
		else if (rn == 2)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "당신은 서울대에 합격했습니다 ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "축하드립니다 !!!");
			Sleep(5000);
			return 0;
		}
		else if (rn == 3)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "당신은 카이스트에 합격했습니다 ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "축하드립니다 !!!");
			Sleep(5000);
			return 0;
		}
	}
	else if (rn == 4 || rn == 5)
	{
		setcolor(31, 32);
		gotoxyP(39, 17, "아쉽게 합격하지 못했습니다 ㅠㅠ"); //합격하지 못하면 게임이 이어서 진행됩니다.
		Sleep(1000);
		setcolor(32, 31);
		gotoxyP(46, 18, "너무 슬프네요 ㅜㅜ");
		Sleep(5000);
		Board_Middle_clear();
	}
	return 1;
}