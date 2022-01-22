//���� ����Ʈ

#include "dimimarble.h"

const char player1[100];
const char player2[100];

const int dice_design[7][9][9] = { //�ֻ��� �׷��� �迭
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

void Set_Game_Console_Size() { //�ܼ� ������ ���� �Լ�
	char chTemp[50];
	sprintf(chTemp, "Mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(chTemp);
}

void Game_board_print() { //���� ��� �Լ�
	int i, j;        //�÷� ����
	system("color  F0"); //��� �� ����
	for (i = 0; i <= 112; i++) //���� �� �� ���
	{
		if (i == 0) gotoxyS(i, 0, "��"); 
		else if (i == 112) gotoxyS(i, 0, "��");
		else
			gotoxyS(i, 0, "��");
	}
	for (i = 1; i <= 30; i++) // ���� ������ ���
	{
		if ((i >= 1 && i <= 5) || (i >= 25 && i <= 30)) {
			for (j = 0; j <= 7; j++)
			{
				gotoxyS(j * 16, i, "��");
			}
		}
		else {
			gotoxyS(0, i, "��");
			gotoxyS(16, i, "��");
			gotoxyS(96, i, "��");
			gotoxyS(112, i, "��");
		}

	}
	for (i = 0; i <= 112; i++) // ���� �Ʒ��� ���
	{
		if (i == 0) gotoxyS(i, 30, "��");
		else if (i == 112) gotoxyS(i, 30, "��");
		else
			gotoxyS(i, 30, "��");
	}
	for (i = 2; i < 112; i++) { //���� ��� �� ���
		for (j = 6; j < 30; j += 6) {
			if (j == 12 || j == 18) {
				if ((i >= 2 && i <= 14) || (i >= 98 && i <= 112))
					gotoxyS(i, j, "��");
			}
			else
				gotoxyS(i, j, "��");
		}
	}

	// ---- Assistant â ��� -----
	setcolor(6, 6);
	gotoxyS(2, 32, "�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�");
	gotoxyS(2, 40, "�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�");
	for (i = 0; i < 7; i++) {
		gotoxyS(2, 33 + i, "��");
		gotoxyS(82, 33 + i, "��");
	}
	// ----- Player 1,2 Status â -----
	setcolor(32, 31);
	gotoxyS(84, 32, "��");
	gotoxyS(112, 40, "��");
	gotoxyS(85, 36, " ��������������");
	gotoxy(86, 32);

}

void Game_board_contents_print() { //���� ������ ������(������ �̸���)�� ���
	// ----- ���� -----
	setcolor(1, 31);
	gotoxyS(2, 1, "�ƶ�ũ Start");
	setcolor(31, 19);
	gotoxyS(18, 1, "������ ������"); // Teacher ����ü 1
	gotoxyS(34, 1, "������ ������");
	gotoxyS(50, 1, "����� ������");
	gotoxyS(66, 1, "���� ������");
	gotoxyS(82, 1, "�ڰ�� ������");
	gotoxyS(98, 1, "���� ������");
	// ----- �߰������� -----
	setcolor(32, 23);
	gotoxyS(98, 7, "������ �к���");  // Teacher ����ü 7
	gotoxyS(98, 13, "������ �к���");
	gotoxyS(98, 19, "������ ����");
	// ----- �� �Ʒ��� -----
	int n = 25; // �ǾƷ��� ������ ĭ�� Y��
	setcolor(1, 26);
	gotoxyS(2, n, "����� ������"); // Teacher ����ü 10
	gotoxyS(18, n, "������ ������");
	gotoxyS(34, n, "���翵 ������");
	gotoxyS(50, n, "���¿� ������");
	gotoxyS(66, n, "������ ������");
	gotoxyS(82, n, "������ ������");
	setcolor(1, 31);
	gotoxyS(98, n, "����Ʈ��");
	// ----- �߰����� -----
	int m = 2;
	setcolor(31, 29);
	gotoxyS(m, 7, "����� ������"); // Teacher ����ü 16
	setcolor(31, 29);
	gotoxyS(m, 13, "������ �����");
	setcolor(31, 29);
	gotoxyS(m, 19, "�ϼ��� ������");
}


void Assistant_boarder_print() { //Assistant�� �׵θ� �κи� �ٽ� ������ִ� �Լ�
	setcolor(6, 6);
	gotoxyS(2, 32, "�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�");
	gotoxyS(2, 40, "�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�");
	for (int i = 0; i < 7; i++) {
		gotoxyS(2, 33 + i, "��");
		gotoxyS(82, 33 + i, "��");
	}
}

void CL_board_error() { //Assistant â ����Ʈ ���� �ذ� �Լ�
	setcolor(32, 31);
	gotoxyS(0, 39, "  ");
	gotoxyS(0, 40, "  ");
	gotoxyS(0, 41, "  ");
}

void print_before_Start() { // ����ȭ�� ���̽� ��� �Լ��� ����
	setcolor(31, 32);
	for (int i = 0; i < 7; i++) {
		Sleep(200);
		for (int j = 0; j < 18; j += 2)
		{
			for (int k = 0; k < 9; k++) {
				gotoxy(DICE_X + j, DICE_Y + k);
				if (dice_design[i][j / 2][k] == 1) //���̽� �������� �Դٸ� ���ٶ� �մϴ�.
					printf("��");
				else
					printf("��");
			}
		}
	}
	int i = 0;
	for (int j = 0; j < 18; j += 2) {
		for (int k = 0; k < 9; k++) {
			gotoxy(DICE_X + j, DICE_Y + k);
			if (dice_design[i][j / 2][k] == 1)
				printf("��");
			else
				printf("��");
		}
	}
}
void printbar() //���̽� ������ �� ��� �Լ�
{
	int i;
	setcolor(31, 10);
	for (i = 1; i <= 20; i++) // ���̽� ������ ������ ���
	{
		gotoxyS(126, i, "��");
		gotoxyS(131, i, "��");
	}
	gotoxyS(126, 20, "����������"); //������ ���
	gotoxyS(126, 1, "����������");
	setcolor(32, 31);
	gotoxyS(124, 10, "��");
	gotoxyS(132, 10, "��");
}
void state_print() //�÷��̾���� ���� ǥ�� ��� �Լ�
{
	char chTemp[100];
	sprintf(chTemp, "PLAYER 1 : %s", player[0].name);
	gotoxy(85, 33);
	printf("%s",chTemp);
	setcolor(player[0].color, 31);
	printf(" ��");
	setcolor(32, 31);
	int i;
	for (i = 0; i < 2; i++)
	{
		setcolor(player[i].color, 15);
		gotoxy(24, 10 + i);
		printf("%8s %s :  ", player[i].name, player[i].horse_img); //Player status �κп� �÷��̾� �̸��� �ش� �� ���
		setcolor(0, 15);
	}
	sprintf(chTemp, "PLAYER 2 : %s", player[1].name);
	gotoxy(85, 37);
	printf("%s", chTemp);
	setcolor(player[1].color, 31);
	printf(" ��");
	setcolor(32, 31);
}

void How_Much_Go(int n) { //~ĭ �̵��߽��ϴ� ��� �Լ�
	gotoxy(5, 34);
	setcolor(31, 5);
	printf(" %d ", n);
	setcolor(32, 31);
	printf(" ĭ �̵��߽��ϴ�");
}

void AQC() { // Assistant question clear �Լ��Դϴ�. Assistant �� Question�κ� ���� ���ڿ��� �����.
	gotoxyS(5, 34, "                                                                        ");
}

void Game_board_printClosePoint() { // ���� "ģ�е� : " ���ڿ� ����صδ� �Լ�
	for (int i = 0; i < 20; i++)
	{
		if (!(i == 0 || i == 10))
		{
			setcolor(32, 31);
			gotoxyS(MapPoint[i][0] - 2, MapPoint[i][1] + 1, "ģ�е� : ");
		}
	}
}

void Board_Middle_clear() { // ���� ��� �� �ո� ���� CLear�Լ�
	for (int i = 7; i <= 23; i++)
	{
		setcolor(32, 31);
		gotoxyS(18, i, "                                                                              ");
	}
}

void closeness_recall() { //ģ�е� �� �������ִ� �Լ�
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