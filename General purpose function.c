//범용함수

#include "dimimarble.h"

void clearCursor(char state)			//커서상태를 매개변수로 1또는0
{
	CONSOLE_CURSOR_INFO statecursor = { 0 };
	statecursor.dwSize = 1;							//커서사이즈
	statecursor.bVisible = state;						//커서 보임,안보임
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &statecursor);
}

void gotoxy(int x, int y) //해당 좌표값으로 이동
{
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

void gotoxyS(int x, int y, char *a)			//좌표값으로 이동후 문자열출력
{
	gotoxy(x, y);
	puts(a);
}

void gotoxyP(int x, int y, char *a) { //좌표값 이동 후 문자열 쫘르륵 출력
	gotoxy(x, y);
	int i = 0;
	int n = 3;
	while (a[i] != NULL) //키보드 입력시 문자열 좌르륵이 겁나 빨라짐.(개발용 코드)
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



void setcolor(int color, int bgcolor) { //텍스트 컬러, 하이라이트 컬러
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((bgcolor & 0xf) << 4) | (color & 0xf));
}