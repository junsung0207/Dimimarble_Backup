#include "dimimarble.h"


void Assistant_Text_clear() { //Assistant 창의 내용물 비워주는 함수
	gotoxy(5, 34);
	printf("                                                                             ");
	gotoxy(5, 35);
	printf("                                                                             ");
	gotoxy(5, 36);
	printf("                                                                             ");
	gotoxy(5, 37);
	printf("                                                                             ");
	gotoxy(5, 38);
	printf("                                                                             ");
	gotoxy(5, 39);
	printf("                                                                             ");
}

int print_Assistant_Turn_Start(int player_num) { //턴마다 무엇을 하실건가요 묻고 해당 번호 리턴하는 함수
	int k;
	char n;
	while (1) {
		gotoxy(5, 34);
		setcolor(1, 30);
		printf("%s", player[player_num].name);	//어떤 플레이어의 차례인지 먼저 묻습니다
		setcolor(0, 31);
		printf("의 턴입니다. 무엇을 하시겠습니까? (숫자 입력)	");
		gotoxy(5, 36);
		setcolor(32, 26);
		printf("1. 주사위를 굴린다.");
		gotoxy(5, 37);
		setcolor(32, 27);
		printf("2. 대학 입시에 도전한다");
		gotoxy(5, 38);
		k = 1;
		while (_kbhit()) {
			_getch();
		}
		n = _getch();
		while (_kbhit()) {
			_getch();
		}
		// 플레이어가 누른 숫자를 판단합니다.
			if (n == '1')   // 플레이어가 누른 숫자가 선택지에 있다면 코드를 실행합니다.
				return 1;
			else if (n == '2')
			{
				if (Can_I_am_onAge(player_num) && Can_I_Go(player_num)) { // 1 1 이면 대학을 갈 수 있습니다.
					if (Goto_Dahak(player_num) == 0) return 0; // 대학을 가는 함수, 함수 도중 대학 입시 실패시 return 0을 합니다.
				}
				Sleep(1000);
				AQC();
			}
			else {
				setcolor(32, 31);
				AQC();
				setcolor(31, 0);
				gotoxyS(5, 34, "해당 숫자만 입력해주세요."); // 그렇지 못할 경우 함수를 다시 시행합니다.
				setcolor(31, 31);
				gotoxyS(5, 38, "                                           ");
				Sleep(500);
			}
	}
}

void Go_To_MapPoint(int turnplayer, int PN) { //해당 맵포인트로 플레이어 이동
	Sleep(200);

	if (turnplayer == 1) {
		for (int i = 1; i <= PN; i++) {
			PlaySound(TEXT("knock.wav"), 0, SND_FILENAME | SND_ASYNC);
			setcolor(player[0].color, 31);			//빨강색으로...
			gotoxyS(MapPoint[(Present_P1_MapPoint +i)%20][0], MapPoint[(Present_P1_MapPoint +i)%20][1], player[0].horse_img); //
			if(i>0)
				gotoxyS(MapPoint[(Present_P1_MapPoint+i-1)%20][0], MapPoint[(Present_P1_MapPoint +i-1)%20][1], "  ");
			Sleep(500);
		}
		if (Present_P1_MapPoint + PN >= 20) {
			P1_Life++;
			Present_P1_MapPoint -= 20;
		}
		Present_P1_MapPoint += PN;
	}
	else if (turnplayer == 2)
	{
		for (int i = 1; i <= PN; i++) {
			PlaySound(TEXT("knock.wav"), 0, SND_FILENAME | SND_ASYNC);
			setcolor(player[1].color, 31);			//파란색으로...
			gotoxyS(MapPoint[(Present_P2_MapPoint + i)%20][0]+2, MapPoint[(Present_P2_MapPoint + i)%20][1], player[1].horse_img);
			if (i > 0)
				gotoxyS(MapPoint[(Present_P2_MapPoint +i - 1)%20][0]+2, MapPoint[(Present_P2_MapPoint + i - 1)%20][1], "  ");
			Sleep(500);
		}
		if (Present_P2_MapPoint + PN >= 20) {
			P2_Life++;
			Present_P2_MapPoint -= 20;
		}
		Present_P2_MapPoint += PN;
	}
	

}

int Is_it_right_num(int n,int range) { //스토리 도중 선택지 구문이 나올때 플레이어가 입력한 값이 선택지에 있는지 판단해줍니다.
	if (n>0 && n<=range)   // 플레이어가 누른 숫자가 선택지에 있다면 코드를 실행합니다.
		return 0;
	else {
		setcolor(32, 31);
		AQC();
		setcolor(32, 31);
		gotoxyS(5, 34, "해당 숫자만 입력해주세요."); // 그렇지 못할 경우 함수를 다시 시행합니다.
		if (range == 2)
			gotoxyS(5, 38, "                                                              ");
		else if (range == 3)
			gotoxyS(5, 39, "                                                               ");
		Sleep(500);
		gotoxyS(5, 38, "                                           ");
		return 1;
	}
}

void Print_Life() { // 라이프 포인트 출력 함수
	setcolor(31, 13);
	gotoxy(85,34);
	if (P1_Life < 3) {
		setcolor(31, 8+P1_Life);
		printf("%s : 고%d", player[0].name, P1_Life + 1); 
		if (P1_Life + 1 == 3) //고3 이상부터는 대학을 갈 수 있음을 출력
		{
			gotoxyP(85, 35, "대학을 갈 수 있어요 !");
		}
	}
	else {
		printf("%s : 재수 %d년", player[0].name, (P1_Life + 1) % 3);
		if ((P1_Life + 1) % 3 == 2)
		{
			Game_over = 2;
		}
	}
		
	gotoxy(85, 38);
	if (P2_Life < 3) {
		setcolor(31, 8 + P2_Life);
		printf("%s : 고%d", player[1].name, P2_Life + 1);
		if (P2_Life + 1 == 3)//고3 이상부터는 대학을 갈 수 있음을 출력
		{
			gotoxyP(85, 39, "대학을 갈 수 있어요 !");
		}
	}
	else {
		printf("%s : 재수 %d년", player[1].name, (P2_Life + 1) % 3);
		if ((P2_Life + 1)%3 == 2)
		{
			Game_over = 2;
		}
	}
}

void Dice_space_helper(int n) { // 1받으면 space바를 누르세요 라는 help매세지 출력 (0은 그 메세지 숨김)
	if (n == 1) {
		gotoxyS(120, 21, "스페이스바를");
		gotoxyS(124, 22, "누르세요");
	}
	else {
		gotoxyS(120, 21, "                   ");
		gotoxyS(120, 22, "            ");
	}
		
}