/*
��Ʈ�� ȭ�� ����
�������� �޴� ȭ�����..
*/

#include "dimimarble.h"

void Loading() // �ε� �Լ�
{
	const int MAX = 18; //�ε� �� �׸� ����

	char text[11][100] = { {"�����Ե� �����Ͻô���"}, {"��Ժ��� �ڵ�¥����"}, {"���� ��������"}, {"�����켱���� �ｺ�ϴ���"}, {"�ε��� ä�����"},{"���ؼ��� �ڵ�¥�� �˽η�������"},
	{"������ �۴���"}, {"�ֻ��� �۴���"}, {"�����̽��� �⸧ĥ �ϴ���"},{"����� ö���ϴ���"} , {"�������� Ÿ���� �����"} };
	int stop = 0;            //�ε��� ��ȭ�ִ� ����
	int i = 0, j = 0;
	int textnum = 0;
	int rn;

	gotoxyS(2, 18, "Tip. ģ�е� �ý����� ����� ģ�е������̸�, �÷��̾�1�� "); //���� ���� ���
	gotoxyS(2, 19, "������� ������, 2�� ���� ��� �Ķ������� ��Ÿ���ϴ�.");

	for (textnum = 0; textnum < 11; textnum++)
	{

		gotoxy(18, 10);
		printf("                              ");
		gotoxy(18, 10);
		printf("%s", text[textnum]);
		for (i = 0; i < MAX; i++) //�ε��ٰ� ����˴ϴ� ~
		{
			gotoxy(3, 11);
			for (j = 0; j < MAX; j++)
			{
				if (j <= i)
				{
					printf("�� ");
					rn = rand() % 7 + 6;
					if ((j == rn || j == rn + 1 || j == rn + 2) && (textnum == 0 || textnum == 5 || textnum == 8))         //�ε��� ���ɸ��� ����
					{
						stop = 400; 
					}
					else stop = 0;
				}
				else
				{
					printf("�� ");
				}
			}

			Sleep(20 + stop);
			stop = 0;


		}

	}

}

void InputUsrName() //���� ���� �Է� �޴� �Լ�
{
	system("cls");
	int i, k;
	gotoxyS(30, 2, "1.�¸� ���� : ��밡 ���ӿ���");
	gotoxyS(30, 3, "�ǰų�, �������п� �����Ұ��"); //���� ���
	gotoxyS(30, 5, "2.���� ����� ������ ��Ҹ�");
	gotoxyS(30, 6, "�� ���� �����Ե��� ��Ҹ��̸�");
	gotoxyS(30, 7, "����� �ް� ���Ǿ����ϴ�.");
	gotoxyS(30, 9, "3.���丮 ���������� ������ ��");
	gotoxyS(30, 10, "�̸� ���� �㱸�� ��Ұ� ���Ե�");
	gotoxyS(30, 11, "�������� �̸� �˷��帳�ϴ�.");
	gotoxyS(30, 13, "4. ģ�е��� 50%�̻��� ������");
	gotoxyS(30, 14, "��õ���� ���Ⱑ���մϴ�");
	gotoxyS(30, 15, "��õ���� �����ϰ� �÷��̾");
	gotoxyS(30, 16, "��3�� ��� ���п� ������ �� ");
	gotoxyS(30, 17, "������,�հݿ��δ� �ٷγ��ɴϴ�");

	gotoxyS(4, 3, "______________________");
	gotoxyS(4, 5, "Input your name & Enter ");
	gotoxyS(4, 6, "______________________");
	int player_color[2] = { 12,9 };         //const int   //����, �Ķ�
	while (1)
	{
		if (GetKeyState(VK_RETURN) < 0)            //VK_RETURN : ����   /    GetKeyState ����Ű����
			continue;
		for (i = 0; i < 2; i++)
		{
			gotoxy(3, 8);

			setcolor(15, player_color[i]);         //setcolor(15, 12);            //����� �������
			printf("�÷��̾�%d", i + 1);
			setcolor(0, 15);            //�������� ������
			printf("�� �г��� �Է���");

			gotoxyP(3, 10, "(�г����� ��/�� 8���̳���)");
			gotoxyP(2, 12, "�Է� : ");
			clearCursor(1);
			do
			{
				gotoxy(8, 12);
				gets(player[i].name);
				gotoxyS(2, 13, "                           ");      //����ó��
				gotoxyS(2, 14, "                           ");      //����ó�� 
				gotoxyS(2, 15, "                           ");      //����ó�� 
				gotoxyS(2, 16, "                           ");      //����ó�� 

				if (i == 1 && (!strcmp(player[0].name, player[1].name)))            //���� �̸��̶�� �ٽ�.
				{
					gotoxyS(8, 12, "                           ");
					gotoxy(8, 12);
					for (k = 0; k < 15; k++)
					{
						player[1].name[k] = 0;
					}
					setcolor(13, 15);
					gotoxyS(2, 14, "���� �̸��Դϴ�.");
					gotoxyS(2, 15, "�ٽ� �Է����ּ���.");
					setcolor(0, 15);
				}
			} while (strcmp(player[i].name, "") == 0 || player[i].name[0] == ' ');      //���鿹�� ó��(�����̸� �ٽ� 8,12 �� ���ư�)
			clearCursor(0);
			gotoxyS(8, 12, "                        ");      //�Է¹��� �� �ʱ�ȭ
		}

		break;
	}
	system("cls");
	Loading();         //�ε���Ʈ��
	Sleep(2000);
}


void MenuIntro() //���� ó���� ���̴� ��Ʈ�� ȭ�� ��� �Լ�
{
	int inputkeyboard;
	int golever = 1;
	int check = 0;

	system("mode con: cols=60 lines=20"); //��Ʈ�� �κ��� ���Ƿ� �ܼ� ����� �ٲ��ݴϴ�.
	gotoxyS(23, 9, "..Loading...");
	Sleep(2000);
	system("cls");
	while (1)
	{
		gotoxyS(9, 2, "___________________________________________");
		gotoxyS(15, 4, "D  I  M  I      M  A  R  B  L  E");
		gotoxyS(9, 5, "___________________________________________");

		gotoxyS(7, 10, "__________________________________________________");
		gotoxyS(9, 12, "����:      ��Ժ�      ���ؼ�");
		gotoxyS(7, 13, "__________________________________________________");

		gotoxyP(18, 16, "PLEASE PRESS THE ENTER KEY");

		if (GetKeyState(VK_RETURN) < 0)                  //����Ű �ƴϸ� continue �ȵ�.
		{
			continue;
		}

		inputkeyboard = _getch();
		switch (inputkeyboard)
		{
		case 13:               //����Ű ������ ���� ���� !
			system("cls");
			golever = 0;
			InputUsrName();
			break;
		}
		if (golever == 0)
			break;
	}
}