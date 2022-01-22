#include "dimimarble.h"

void system_(char *a) { //스토리 진행에 있어서 코드 간략화를 위한 함수, 시스템 대사 출력 함수
	setcolor(32, 31);
	AQC();
	setcolor(32, 7);
	gotoxyP(5, 34, a);
	setcolor(32, 31);
}

//----------친밀도 상승 함수---------//
void closeness_up(int Now_Point, int C,int turnplayer) { //closeness_up(현재 위치, 해당 수치, 턴플레이어)
	PlaySound(TEXT("Up.wav"), 0, SND_FILENAME | SND_ASYNC);
	Assistant_Text_clear();
	setcolor(32, 31);
	gotoxy(5, 34);
	printf("친밀도가 %d 상승했습니다! ", C);
	if (turnplayer == 1) {
		if (closeness[Now_Point] < C)
			closeness[Now_Point] = 0;
		else
			closeness[Now_Point] -= C;
	}
	else
	{
		if (closeness[Now_Point] > 200-C) closeness[2] = 200;
		else
			closeness[Now_Point] += C;
	}
}
// -------------------------------//

//-----------------친밀도 하강 함수 ------------------//
void closeness_down(int Now_Point, int C,int turnplayer) {
	PlaySound(TEXT("Down.wav"), 0, SND_FILENAME | SND_ASYNC);
	Assistant_Text_clear();
	setcolor(32, 31);
	gotoxy(5, 34);
	printf("친밀도가 %d 하강했습니다! ", C);
	if (turnplayer == 1) {
		if (closeness[Now_Point] > 100-C)
			closeness[Now_Point] = 100;
		else
			closeness[Now_Point] += C;
	}
	else
	{
		if (closeness[Now_Point] < 100+C) closeness[2] = 100;
		else
			closeness[Now_Point] -= C;
	}
}
//--------------------------------------------------//

void player_Talk(int turnplayer, char *a) { //해당 플레이어의 본인 대사 출력 간략화 함수
	Assistant_Text_clear();
	setcolor(32, 31);
	char chTemp2[100] = { 0 };
	sprintf(chTemp2, "%s : %s", player[turnplayer - 1].name, a);
	gotoxyP(5, 34, chTemp2);
}