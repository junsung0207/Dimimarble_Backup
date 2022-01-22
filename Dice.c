#include "dimimarble.h"

int Dice_Go(int *j, int updown_switch) { //주사위를 굴렸을때
	PresentDice_Num = rand() % 6 + 1; //주사위 값이 랜덤으로 부여됩니다.
	//PresentDice_Num
	int gaze_middle = 127;
	Sleep(10);
	if (updown_switch == 1) {
		if ((*j) == 2) {
			setcolor(32, 31);
			gotoxyS(gaze_middle, (*j), "■■");
			gotoxyS(gaze_middle, (*j) + 1, "    ");
			(*j)++;
			return 1;
		}
		else if ((*j) == 19) {
			setcolor(32, 31);
			gotoxyS(gaze_middle, (*j), "■■");
			gotoxyS(gaze_middle, (*j) - 1, "    ");
			return 0;
		}
		else
		{
			setcolor(32, 31);
			gotoxyS(gaze_middle, (*j), "■■");
			gotoxyS(gaze_middle, (*j) - 1, "    ");
			gotoxyS(gaze_middle, (*j) + 1, "    ");
			(*j)++;
			return 1;
		}
	}
	else if (updown_switch == 0)
	{
		if ((*j) == 19) {
			setcolor(32, 31);
			gotoxyS(gaze_middle, (*j), "■■");
			gotoxyS(gaze_middle, (*j) - 1, "    ");
			(*j)--;
			return 0;
		}
		else if ((*j) == 2) {
			setcolor(32, 31);
			gotoxyS(gaze_middle, (*j), "■■");
			gotoxyS(gaze_middle, (*j) + 1, "    ");
			return 1;
		}
		else
		{
			setcolor(32, 31);
			gotoxyS(gaze_middle, (*j), "■■");
			gotoxyS(gaze_middle, (*j) - 1, "    ");
			gotoxyS(gaze_middle, (*j) + 1, "    ");
			(*j)--;
			return 0;
		}
	}
	/*
	int i = 2,c_none;
	//_getch();
	Sleep(50);
	int dice_updown_switch = 1;
	PresentDice_Num = (rand() % 6) + 1;
	while (_kbhit()) {
			//c_none = _getch();
			if (dice_updown_switch) {
					if (i == 2) {
						setcolor(32, 31);
						gotoxyS(128, i, "■");
						gotoxyS(128, i + 1, "  ");
						i++;
						//k_input = _getch();
					}
					else if (i == 19) {
						setcolor(32, 31);
						gotoxyS(128, i, "■");
						gotoxyS(128, i - 1, "  ");
						dice_updown_switch = 0;
						//k_input = _getch();
					}
					else if (i > 2 && i < 19) {
						setcolor(32, 31);
						gotoxyS(128, i, "■");
						gotoxyS(128, i - 1, "  ");
						gotoxyS(128, i + 1, "  ");
						i++;
						//k_input = _getch();
					}
					Sleep(20);
				}
			else {
					if (i == 2) {
						setcolor(32, 31);
						gotoxyS(128, i, "■");
						gotoxyS(128, i + 1, "  ");
						//k_input = _getch();
						dice_updown_switch = 1;
					}
					else if (i == 19) {
						setcolor(32, 31);
						gotoxyS(128, i, "■");
						gotoxyS(128, i - 1, "  ");
						i--;
						//k_input = _getch();
					}
					else if (i > 2 && i < 19) {
						setcolor(32, 31);
						gotoxyS(128, i, "■");
						gotoxyS(128, i - 1, "  ");
						gotoxyS(128, i + 1, "  ");
						i--;
						//k_input = _getch();
					}
					//if (!(_kbhit())) break;
					Sleep(20);
				}
		}
	return;
	*/
}

/*
int Dice_printRand(int i) { //DIce를 굴렸을때 다이스 그래픽도 랜덤으로 나오도록 설정하는 함수
	i = i % 7;
	setcolor(31, 32);
		for (int j = 0; j < 18; j += 2)
		{
			for (int k = 0; k < 9; k++) {
				gotoxy(DICE_X + j, DICE_Y + k);
				if (dice_design[i][j / 2][k] == 1)
					printf("■");
				else
					printf("▦");
			}
		}
		return i++;
}
*/

void Dice_Bar_clear() {
	for (int i = 2; i < 20; i++) {
		gotoxyS(127, i, "    ");
	}
}

void Dice_0_print() {
	setcolor(32, 31);
	for (int j = 0; j < 18; j += 2)
	{
		for (int k = 0; k < 9; k++) {
			gotoxy(DICE_X + j, DICE_Y + k);
			if (dice_design[0][j / 2][k] == 1)
				printf("▦");
			else
				printf("▦");
		}
	}
}

void Display_Dice(int i)
{
	setcolor(32, 31);
	for (int j = 0; j < 18; j += 2)
	{
		for (int k = 0; k < 9; k++) {
			gotoxy(DICE_X + j, DICE_Y + k);
			if (dice_design[i][j / 2][k] == 1)
				printf("■");
			else
				printf("▦");
		}
	}
}