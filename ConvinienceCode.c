#include "dimimarble.h"

void system_(char *a) { //���丮 ���࿡ �־ �ڵ� ����ȭ�� ���� �Լ�, �ý��� ��� ��� �Լ�
	setcolor(32, 31);
	AQC();
	setcolor(32, 7);
	gotoxyP(5, 34, a);
	setcolor(32, 31);
}

//----------ģ�е� ��� �Լ�---------//
void closeness_up(int Now_Point, int C,int turnplayer) { //closeness_up(���� ��ġ, �ش� ��ġ, ���÷��̾�)
	PlaySound(TEXT("Up.wav"), 0, SND_FILENAME | SND_ASYNC);
	Assistant_Text_clear();
	setcolor(32, 31);
	gotoxy(5, 34);
	printf("ģ�е��� %d ����߽��ϴ�! ", C);
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

//-----------------ģ�е� �ϰ� �Լ� ------------------//
void closeness_down(int Now_Point, int C,int turnplayer) {
	PlaySound(TEXT("Down.wav"), 0, SND_FILENAME | SND_ASYNC);
	Assistant_Text_clear();
	setcolor(32, 31);
	gotoxy(5, 34);
	printf("ģ�е��� %d �ϰ��߽��ϴ�! ", C);
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

void player_Talk(int turnplayer, char *a) { //�ش� �÷��̾��� ���� ��� ��� ����ȭ �Լ�
	Assistant_Text_clear();
	setcolor(32, 31);
	char chTemp2[100] = { 0 };
	sprintf(chTemp2, "%s : %s", player[turnplayer - 1].name, a);
	gotoxyP(5, 34, chTemp2);
}