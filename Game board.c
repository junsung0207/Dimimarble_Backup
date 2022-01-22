//보드 프린트

#include "dimimarble.h"

const char player1[100];
const char player2[100];

const int dice_design[7][9][9] = { //주사위 그래픽 배열
   {
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   },
   {
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 1
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   },
   {
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },// 2
	  { 0, 0, 0, 0, 0, 1, 1, 1, 0 },
	  { 0, 0, 0, 0, 0, 1, 1, 1, 0 },
	  { 0, 0, 0, 0, 0, 1, 1, 1, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 1, 1, 1, 0, 0, 0, 0, 0 },
	  { 0, 1, 1, 1, 0, 0, 0, 0, 0 },
	  { 0, 1, 1, 1, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   },
   {
	  { 1, 1, 1, 0, 0, 0, 0, 0, 0 },// 3
	  { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
	  { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	  { 0, 0, 0, 0, 0, 0, 1, 1, 1 },
	  { 0, 0, 0, 0, 0, 0, 1, 1, 1 }
   },
   {
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },// 4
	  { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	  { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	  { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	  { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	  { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	  { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   },
   {
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 }, // 5
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 },
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 },
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 },
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 }
   },
   {
	  { 1, 1, 1, 0, 0, 0, 0, 0, 0 }, // 6
	  { 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	  { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	  { 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	  { 1, 1, 1, 0, 0, 0, 1, 1, 1 },
	  { 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	  { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	  { 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	  { 0, 0, 0, 0, 0, 0, 1, 1, 1 }
   }
};

void Set_Game_Console_Size() { //콘솔 사이즈 지정 함수
	char chTemp[50];
	sprintf(chTemp, "Mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(chTemp);
}

void Game_board_print() { //보드 출력 함수
	int i, j;        //컬러 변경
	system("color  F0"); //배경 색 변경
	for (i = 0; i <= 112; i++) //보드 윗 줄 출력
	{
		if (i == 0) gotoxyS(i, 0, "┏"); 
		else if (i == 112) gotoxyS(i, 0, "┓");
		else
			gotoxyS(i, 0, "━");
	}
	for (i = 1; i <= 30; i++) // 보드 새로줄 출력
	{
		if ((i >= 1 && i <= 5) || (i >= 25 && i <= 30)) {
			for (j = 0; j <= 7; j++)
			{
				gotoxyS(j * 16, i, "┃");
			}
		}
		else {
			gotoxyS(0, i, "┃");
			gotoxyS(16, i, "┃");
			gotoxyS(96, i, "┃");
			gotoxyS(112, i, "┃");
		}

	}
	for (i = 0; i <= 112; i++) // 보드 아랫줄 출력
	{
		if (i == 0) gotoxyS(i, 30, "┗");
		else if (i == 112) gotoxyS(i, 30, "┛");
		else
			gotoxyS(i, 30, "━");
	}
	for (i = 2; i < 112; i++) { //보드 가운데 줄 출력
		for (j = 6; j < 30; j += 6) {
			if (j == 12 || j == 18) {
				if ((i >= 2 && i <= 14) || (i >= 98 && i <= 112))
					gotoxyS(i, j, "━");
			}
			else
				gotoxyS(i, j, "━");
		}
	}

	// ---- Assistant 창 출력 -----
	setcolor(6, 6);
	gotoxyS(2, 32, "◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎");
	gotoxyS(2, 40, "◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎");
	for (i = 0; i < 7; i++) {
		gotoxyS(2, 33 + i, "◎");
		gotoxyS(82, 33 + i, "◎");
	}
	// ----- Player 1,2 Status 창 -----
	setcolor(32, 31);
	gotoxyS(84, 32, "『");
	gotoxyS(112, 40, "』");
	gotoxyS(85, 36, " 〓〓〓〓〓〓〓〓〓〓〓〓〓");
	gotoxy(86, 32);

}

void Game_board_contents_print() { //게임 보드의 컨텐츠(선생님 이름등)를 출력
	// ----- 윗줄 -----
	setcolor(1, 31);
	gotoxyS(2, 1, "아라마크 Start");
	setcolor(31, 19);
	gotoxyS(18, 1, "류명희 선생님"); // Teacher 구조체 1
	gotoxyS(34, 1, "함지연 선생님");
	gotoxyS(50, 1, "허관무 선생님");
	gotoxyS(66, 1, "제제 선생님");
	gotoxyS(82, 1, "박경수 선생님");
	gotoxyS(98, 1, "김상욱 선생님");
	// ----- 중간오른줄 -----
	setcolor(32, 23);
	gotoxyS(98, 7, "배종우 학봉관");  // Teacher 구조체 7
	gotoxyS(98, 13, "전희진 학봉관");
	gotoxyS(98, 19, "양희정 본관");
	// ----- 맨 아랫줄 -----
	int n = 25; // 맨아랫줄 선생님 칸의 Y값
	setcolor(1, 26);
	gotoxyS(2, n, "이재민 선생님"); // Teacher 구조체 10
	gotoxyS(18, n, "전유원 선생님");
	gotoxyS(34, n, "김재영 선생님");
	gotoxyS(50, n, "남승완 선생님");
	gotoxyS(66, n, "최하은 선생님");
	gotoxyS(82, n, "이택주 선생님");
	setcolor(1, 31);
	gotoxyS(98, n, "스마트팜");
	// ----- 중간왼줄 -----
	int m = 2;
	setcolor(31, 29);
	gotoxyS(m, 7, "정희범 선생님"); // Teacher 구조체 16
	setcolor(31, 29);
	gotoxyS(m, 13, "정동윤 교장쌤");
	setcolor(31, 29);
	gotoxyS(m, 19, "하성봉 선생님");
}


void Assistant_boarder_print() { //Assistant의 테두리 부분만 다시 출력해주는 함수
	setcolor(6, 6);
	gotoxyS(2, 32, "◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎");
	gotoxyS(2, 40, "◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎");
	for (int i = 0; i < 7; i++) {
		gotoxyS(2, 33 + i, "◎");
		gotoxyS(82, 33 + i, "◎");
	}
}

void CL_board_error() { //Assistant 창 프린트 오류 해결 함수
	setcolor(32, 31);
	gotoxyS(0, 39, "  ");
	gotoxyS(0, 40, "  ");
	gotoxyS(0, 41, "  ");
}

void print_before_Start() { // 시작화면 다이스 출력 함수도 포함
	setcolor(31, 32);
	for (int i = 0; i < 7; i++) {
		Sleep(200);
		for (int j = 0; j < 18; j += 2)
		{
			for (int k = 0; k < 9; k++) {
				gotoxy(DICE_X + j, DICE_Y + k);
				if (dice_design[i][j / 2][k] == 1) //다이스 게이지가 왔다리 갔다라 합니다.
					printf("■");
				else
					printf("▦");
			}
		}
	}
	int i = 0;
	for (int j = 0; j < 18; j += 2) {
		for (int k = 0; k < 9; k++) {
			gotoxy(DICE_X + j, DICE_Y + k);
			if (dice_design[i][j / 2][k] == 1)
				printf("▦");
			else
				printf("▦");
		}
	}
}
void printbar() //다이스 게이지 바 출력 함수
{
	int i;
	setcolor(31, 10);
	for (i = 1; i <= 20; i++) // 다이스 게이지 새로줄 출력
	{
		gotoxyS(126, i, "┃");
		gotoxyS(131, i, "┃");
	}
	gotoxyS(126, 20, "━━━━━"); //가로줄 출력
	gotoxyS(126, 1, "━━━━━");
	setcolor(32, 31);
	gotoxyS(124, 10, "▶");
	gotoxyS(132, 10, "◀");
}
void state_print() //플레이어들의 상태 표시 출력 함수
{
	char chTemp[100];
	sprintf(chTemp, "PLAYER 1 : %s", player[0].name);
	gotoxy(85, 33);
	printf("%s",chTemp);
	setcolor(player[0].color, 31);
	printf(" ★");
	setcolor(32, 31);
	int i;
	for (i = 0; i < 2; i++)
	{
		setcolor(player[i].color, 15);
		gotoxy(24, 10 + i);
		printf("%8s %s :  ", player[i].name, player[i].horse_img); //Player status 부분에 플레이어 이름과 해당 말 출력
		setcolor(0, 15);
	}
	sprintf(chTemp, "PLAYER 2 : %s", player[1].name);
	gotoxy(85, 37);
	printf("%s", chTemp);
	setcolor(player[1].color, 31);
	printf(" ♠");
	setcolor(32, 31);
}

void How_Much_Go(int n) { //~칸 이동했습니다 출력 함수
	gotoxy(5, 34);
	setcolor(31, 5);
	printf(" %d ", n);
	setcolor(32, 31);
	printf(" 칸 이동했습니다");
}

void AQC() { // Assistant question clear 함수입니다. Assistant 의 Question부분 한줄 문자열만 비워줌.
	gotoxyS(5, 34, "                                                                        ");
}

void Game_board_printClosePoint() { // 맵의 "친밀도 : " 문자열 출력해두는 함수
	for (int i = 0; i < 20; i++)
	{
		if (!(i == 0 || i == 10))
		{
			setcolor(32, 31);
			gotoxyS(MapPoint[i][0] - 2, MapPoint[i][1] + 1, "친밀도 : ");
		}
	}
}

void Board_Middle_clear() { // 맵의 가운데 뻥 뚫린 곳의 CLear함수
	for (int i = 7; i <= 23; i++)
	{
		setcolor(32, 31);
		gotoxyS(18, i, "                                                                              ");
	}
}

void closeness_recall() { //친밀도 값 갱신해주는 함수
	for (int i = 0; i < 20; i++)
	{
		if (i == 0 || i == 10) continue;
		gotoxy(MapPoint[i][0]+6, MapPoint[i][1]+1);
		if (closeness[i] == 100) {
			setcolor(32, 31);
			printf("%d", closeness[i]-100);
		}
		else if (closeness[i] > 100) {
			setcolor(31,player[1].color);
			printf("%d", closeness[i] - 100);
		}
		else if (closeness[i] < 100) {
			setcolor(31, player[0].color);
			printf("%d", 100 - closeness[i]);
		}
	}
}