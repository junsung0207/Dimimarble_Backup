#include "dimimarble.h"


void Assistant_Text_clear() { //Assistant â�� ���빰 ����ִ� �Լ�
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

int print_Assistant_Turn_Start(int player_num) { //�ϸ��� ������ �Ͻǰǰ��� ���� �ش� ��ȣ �����ϴ� �Լ�
	int k;
	char n;
	while (1) {
		gotoxy(5, 34);
		setcolor(1, 30);
		printf("%s", player[player_num].name);	//� �÷��̾��� �������� ���� �����ϴ�
		setcolor(0, 31);
		printf("�� ���Դϴ�. ������ �Ͻðڽ��ϱ�? (���� �Է�)	");
		gotoxy(5, 36);
		setcolor(32, 26);
		printf("1. �ֻ����� ������.");
		gotoxy(5, 37);
		setcolor(32, 27);
		printf("2. ���� �Խÿ� �����Ѵ�");
		gotoxy(5, 38);
		k = 1;
		while (_kbhit()) {
			_getch();
		}
		n = _getch();
		while (_kbhit()) {
			_getch();
		}
		// �÷��̾ ���� ���ڸ� �Ǵ��մϴ�.
			if (n == '1')   // �÷��̾ ���� ���ڰ� �������� �ִٸ� �ڵ带 �����մϴ�.
				return 1;
			else if (n == '2')
			{
				if (Can_I_am_onAge(player_num) && Can_I_Go(player_num)) { // 1 1 �̸� ������ �� �� �ֽ��ϴ�.
					if (Goto_Dahak(player_num) == 0) return 0; // ������ ���� �Լ�, �Լ� ���� ���� �Խ� ���н� return 0�� �մϴ�.
				}
				Sleep(1000);
				AQC();
			}
			else {
				setcolor(32, 31);
				AQC();
				setcolor(31, 0);
				gotoxyS(5, 34, "�ش� ���ڸ� �Է����ּ���."); // �׷��� ���� ��� �Լ��� �ٽ� �����մϴ�.
				setcolor(31, 31);
				gotoxyS(5, 38, "                                           ");
				Sleep(500);
			}
	}
}

void Go_To_MapPoint(int turnplayer, int PN) { //�ش� ������Ʈ�� �÷��̾� �̵�
	Sleep(200);

	if (turnplayer == 1) {
		for (int i = 1; i <= PN; i++) {
			PlaySound(TEXT("knock.wav"), 0, SND_FILENAME | SND_ASYNC);
			setcolor(player[0].color, 31);			//����������...
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
			setcolor(player[1].color, 31);			//�Ķ�������...
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

int Is_it_right_num(int n,int range) { //���丮 ���� ������ ������ ���ö� �÷��̾ �Է��� ���� �������� �ִ��� �Ǵ����ݴϴ�.
	if (n>0 && n<=range)   // �÷��̾ ���� ���ڰ� �������� �ִٸ� �ڵ带 �����մϴ�.
		return 0;
	else {
		setcolor(32, 31);
		AQC();
		setcolor(32, 31);
		gotoxyS(5, 34, "�ش� ���ڸ� �Է����ּ���."); // �׷��� ���� ��� �Լ��� �ٽ� �����մϴ�.
		if (range == 2)
			gotoxyS(5, 38, "                                                              ");
		else if (range == 3)
			gotoxyS(5, 39, "                                                               ");
		Sleep(500);
		gotoxyS(5, 38, "                                           ");
		return 1;
	}
}

void Print_Life() { // ������ ����Ʈ ��� �Լ�
	setcolor(31, 13);
	gotoxy(85,34);
	if (P1_Life < 3) {
		setcolor(31, 8+P1_Life);
		printf("%s : ��%d", player[0].name, P1_Life + 1); 
		if (P1_Life + 1 == 3) //��3 �̻���ʹ� ������ �� �� ������ ���
		{
			gotoxyP(85, 35, "������ �� �� �־�� !");
		}
	}
	else {
		printf("%s : ��� %d��", player[0].name, (P1_Life + 1) % 3);
		if ((P1_Life + 1) % 3 == 2)
		{
			Game_over = 2;
		}
	}
		
	gotoxy(85, 38);
	if (P2_Life < 3) {
		setcolor(31, 8 + P2_Life);
		printf("%s : ��%d", player[1].name, P2_Life + 1);
		if (P2_Life + 1 == 3)//��3 �̻���ʹ� ������ �� �� ������ ���
		{
			gotoxyP(85, 39, "������ �� �� �־�� !");
		}
	}
	else {
		printf("%s : ��� %d��", player[1].name, (P2_Life + 1) % 3);
		if ((P2_Life + 1)%3 == 2)
		{
			Game_over = 2;
		}
	}
}

void Dice_space_helper(int n) { // 1������ space�ٸ� �������� ��� help�ż��� ��� (0�� �� �޼��� ����)
	if (n == 1) {
		gotoxyS(120, 21, "�����̽��ٸ�");
		gotoxyS(124, 22, "��������");
	}
	else {
		gotoxyS(120, 21, "                   ");
		gotoxyS(120, 22, "            ");
	}
		
}