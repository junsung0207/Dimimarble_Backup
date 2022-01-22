#include "dimimarble.h"

void boardingcolor(int n)
{
	n = n % 31 + 1;
	gotoxy(18, 7);
	setcolor(n, 31);
	printf("����������������������������������������");
	gotoxy(18, 23);
	printf("����������������������������������������");
	for (int i = 8; i <= 22; i++)
	{
		gotoxyP(18, i, "��");
		gotoxyP(94, i, "��");
	}
	setcolor(32, 31);
}

int Can_I_am_onAge(int turnplayer) { //������ ���� �ֳ������� ���� �Ǵ��Լ�
	setcolor(32, 31);
	Assistant_Text_clear();
	if (turnplayer == 0)
	{
		if (P1_Life >= 2) {
			system_("������ �� ���̰� �Ǿ���ϴ� !");
			Sleep(2000);
			return 1;
		}

		else {
			system_("���� ������ �� �� ����� �Ф�");
			Sleep(2000);
			return 0;
		}
	}
	else
	{
		if (P2_Life >= 2) {
			system_("������ �� ���̰� �Ǿ���ϴ� !");
			Sleep(2000);
			return 1;
		}

		else {
			system_("���� ������ �� �� ����� �Ф�");
			Sleep(2000);
			return 0;
		}
	}
}

int Can_I_Go(int turnplayer) { //turnplayer = 0 �Ǵ� 1 
	int n = 0, num = 0;
	setcolor(32, 31);
	Assistant_Text_clear();
	if (turnplayer == 0)
	{
		for (int i = 1; i < 20; i++) {
			if (i == 10)  continue;
			if (closeness[i] <= 50) n++;
		}
		if (n > 0) // ģ�е� 50 �Ѵ� ����� �Ѹ� �̻� ���� ���
		{
			gotoxyP(5, 34, "ģ�е��� 50�� ���� ��� : ");
			for (int i = 0; i < 20; i++)
			{
				if (i == 10)  continue;
				if (closeness[i] <= 50 && num < 3) {
					printf("%s  ", T_name[i]);
					num++;
				}
				if (num == 3) //�ش� �������� 3�� �̻� �� ��� ���� �������� ...���� �����մϴ�.
					printf(" ...");
			}
			Sleep(3000);
			return 1;
		}
		else
			gotoxyP(5, 34, "ģ�е��� 50�� �Ѵ� ����� �ƹ��� �����ϴ�.");
		return 0;

	}
	else
	{
		for (int i = 1; i < 20; i++) {
			if (i == 10)  continue;
			if (closeness[i] >= 150) n++;
		}
		if (n > 0) // ģ�е� 50 �Ѵ� ����� �Ѹ� �̻� ���� ���
		{
			gotoxyP(5, 34, "ģ�е��� 50�� ���� ��� : ");
			for (int i = 0; i < 20; i++)
			{
				if (i == 10)  continue;
				if (closeness[i] >= 150 && num < 3) {
					printf("%s  ", T_name[i]);
					num++;
				}
				if (num == 3) //�� ���� ���� ��������
					printf("...");
			}
			Sleep(3000);
			return 1;
		}
		else
			gotoxyP(5, 34, "ģ�е��� 50�� �Ѵ� ����� �ƹ��� �����ϴ�.");
		return 0;
	}
}

int Goto_Dahak(turnplayer) { //���� ���� �Լ�
	setcolor(32, 31);
	int k, n = 0;
	Board_Middle_clear();
	Assistant_Text_clear();
	PlaySound(TEXT("league.wav"), 0, SND_FILENAME | SND_ASYNC);
	gotoxyS(45, 8, "�� ���� ������ ���� ���� ��");
	setcolor(31, 5);
	int colorplus = 4;
	boardingcolor(colorplus);
	gotoxyP(20, 13, "����� ��õ���� �̺е��� ���ּ̽��ϴ�.");
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
	gotoxyP(43, 17, " �׷��� ���п� �� �غ� �Ǿ����ϱ� ? ");
	Sleep(3000);
	gotoxyP(41, 17, " �غ� �Ǿ��ٸ� �����̽��ٸ� �����ּ��� ");
	while (1) {
		k = _getch();
		if (k == 32)
			break;
	}

	setcolor(32, 31);
	Board_Middle_clear();
	gotoxyS(45, 8, "�� ���� ������ ���� ���� ��");
	gotoxyP(39, 17, " ������ ��õ���� �Բ� ���� ������ �־����ϴ�. "); //���п� �����ϴ� ������ ������ִ� �Լ�
	boardingcolor(4);
	Sleep(2000);
	for (int i = 0; i < 2; i++)
	{
		gotoxyP(48, 20, "��ٸ��� �� .   ");
		printf("                          ");
		for (int m = 0; m < 7; m++)
		{
			for (i = 0; i < 15; i++) //�ε��ٰ� ����˴ϴ� ~
			{
				gotoxy(34, 21);
				for (int j = 0; j < 15; j++)
				{
					if (j <= i)
					{
						printf("�� ");
					}
					else
					{
						printf("�� ");
					}
				}
				Sleep(10);
			}
		}
		gotoxyP(48, 20, "��ٸ��� �� .. ");
		printf("                          ");
		for (int m = 0; m < 7; m++)
		{
			for (i = 0; i < 15; i++) //�ε��ٰ� ����˴ϴ� ~
			{
				gotoxy(34, 21);
				for (int j = 0; j < 15; j++)
				{
					if (j <= i)
					{
						printf("�� ");
					}
					else
					{
						printf("�� ");
					}
				}
				Sleep(10);
			}
		}
		gotoxyP(48, 20, "��ٸ��� �� ...");
		printf("                          ");
		for (int m = 0; m < 8; m++)
		{
			for (i = 0; i < 15; i++) //�ε��ٰ� ����˴ϴ� ~
			{
				gotoxy(34, 21);
				for (int j = 0; j < 15; j++)
				{
					if (j <= i)
					{
						printf("�� ");
					}
					else
					{
						printf("�� ");
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
	gotoxyP(39, 17, "����� ���Խ��ϴ� !                          ");
	Sleep(3000);
	gotoxyP(39, 17, "����� ���� �� ������ ... !");
	Sleep(3000);
	int rn;
	rn = rand() % 6;//������ �������� �����˴ϴ� ! (������ ����ִ� ���)
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
			gotoxyP(39, 17, "����� ���հ��뿡 �հ��߽��ϴ� ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "���ϵ帳�ϴ� !!!");
			Sleep(5000);
			//������ return 0
			return 0;
		}
		else if (rn == 1)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "����� �����뿡 �հ��߽��ϴ� ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "���ϵ帳�ϴ� !!!");
			Sleep(5000);
			return 0;
		}
		else if (rn == 2)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "����� ����뿡 �հ��߽��ϴ� ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "���ϵ帳�ϴ� !!!");
			Sleep(5000);
			return 0;
		}
		else if (rn == 3)
		{
			setcolor(32, 7);
			PlaySound(TEXT("Godd.wav"), 0, SND_FILENAME | SND_ASYNC);
			gotoxyP(39, 17, "����� ī�̽�Ʈ�� �հ��߽��ϴ� ! ");
			Sleep(1000);
			setcolor(32, 31);
			gotoxyP(46, 18, "���ϵ帳�ϴ� !!!");
			Sleep(5000);
			return 0;
		}
	}
	else if (rn == 4 || rn == 5)
	{
		setcolor(31, 32);
		gotoxyP(39, 17, "�ƽ��� �հ����� ���߽��ϴ� �Ф�"); //�հ����� ���ϸ� ������ �̾ ����˴ϴ�.
		Sleep(1000);
		setcolor(32, 31);
		gotoxyP(46, 18, "�ʹ� �����׿� �̤�");
		Sleep(5000);
		Board_Middle_clear();
	}
	return 1;
}