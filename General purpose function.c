//�����Լ�

#include "dimimarble.h"

void clearCursor(char state)			//Ŀ�����¸� �Ű������� 1�Ǵ�0
{
	CONSOLE_CURSOR_INFO statecursor = { 0 };
	statecursor.dwSize = 1;							//Ŀ��������
	statecursor.bVisible = state;						//Ŀ�� ����,�Ⱥ���
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &statecursor);
}

void gotoxy(int x, int y) //�ش� ��ǥ������ �̵�
{
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

void gotoxyS(int x, int y, char *a)			//��ǥ������ �̵��� ���ڿ����
{
	gotoxy(x, y);
	puts(a);
}

void gotoxyP(int x, int y, char *a) { //��ǥ�� �̵� �� ���ڿ� �Ҹ��� ���
	gotoxy(x, y);
	int i = 0;
	int n = 3;
	while (a[i] != NULL) //Ű���� �Է½� ���ڿ� �¸����� �̳� ������.(���߿� �ڵ�)
	{
		while (_kbhit())
		{
			if (_getch() == 13)
				n = 0;
		}
		printf("%c", a[i]);
		i++;
		Sleep(n);
	}
}



void setcolor(int color, int bgcolor) { //�ؽ�Ʈ �÷�, ���̶���Ʈ �÷�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor & 0xf) << 4) | (color & 0xf));
}