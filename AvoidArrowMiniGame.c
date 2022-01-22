#include "dimimarble.h"


void displayStart() //화살 미니 게임시작 전, 인터페이스를 출력합니다.
{
	while (1)
	{
		system_("시작하려면 아무키나 누르세요 / 화면 중앙에서 시작됩니다, ← →로 이동가능");
		Sleep(500);
		AQC();
		if (_kbhit())
		{
			_getch();
			break;
		}
	}
	Sleep(500);
}

void displayScore(int s) //점수 출력 함수
{
	gotoxy(5, 38);
	printf("점수 : %2d", s);
}

void move(int x, int dir) //무브 함수
{
	if (dir == RIGHT)
	{
		gotoxy(x - 1, 23);
		printf(" ");
	}
	else if (dir == LEFT)
	{
		gotoxy(x + 1, 23);
		printf(" ");
	}
	gotoxy(x, 23);
	printf("?");
}


void initArrow(Arrow *s)            //화살생성
{
	for (int i = 0; i < ARROW_NUM; i++)
	{
		s[i].x = rand() % 77 + 18;         //18~94
		s[i].y = 33;
		s[i].speed = (rand() % MAX_SPEED + 10);
	}
}

void displayStar(Arrow *s, int count) //화살 불러오기 함수
{
	for (int i = 0; i < ARROW_NUM; i++)
	{
		if (s[i].y - 1 > 23 && (count % s[i].speed == 0 || s[i].y == 22))
		{
			gotoxy(s[i].x, s[i].y - 1);
			printf(" ");
		}
		if (s[i].y > 23)
		{
			s[i].y = 8;
			s[i].x = rand() % 77 + 18;      //18~94
			s[i].speed = (rand() % MAX_SPEED + 7);
		}
		if (count % s[i].speed == 0)
		{
			gotoxy(s[i].x, s[i].y);
			printf("↓");
			gotoxy(s[i].x, s[i].y - 1);
			printf(" ");
			s[i].y++;

		}
	}
}

int checkCursh(int x, Arrow *s) //플레이어랑 화살이 부딫혔는지 판단해주는 함수
{
	for (int i = 0; i < ARROW_NUM; i++)
	{
		if (s[i].y == 23 && (s[i].x == x || s[i].x == x + 1))
			return 1;
	}
	return 0;
}

void avoidArrow() //화살 미니게임 전체적 함수
{
	int score = 0;
	char ch;
	int xPosition = 56;
	Arrow arw[ARROW_NUM]; //화살 구조체
	int count = 0;

	clearCursor(0);
	displayStart();
	PlaySound(TEXT("Boss.wav"), 0, SND_FILENAME | SND_ASYNC);
	Board_Middle_clear(); // 보드의 가운데 부분을 비워줌.

	displayScore(score);
	move(xPosition, RIGHT); // 플레이어가 움직인다.

	initArrow(arw);

	while (1)
	{
		if (count % 100 == 0) // 미니게임이 끝날시 점수를 출력
		{
			score++;
			displayScore(score);
			count = 0;
		}
		displayStar(arw, count); // 게임 진행 중에 계속해서 화살 랜덤으로 출력

		if (_kbhit())
		{
			ch = _getch();
			if (ch == RIGHT && xPosition < 93)
			{
				move(++xPosition, RIGHT);
			}
			else if (ch == LEFT && xPosition > 18)
				move(--xPosition, LEFT);
		}
		if (checkCursh(xPosition, arw)) // 플레이어가 화살에 맞아 게임이 끝날시, 출력 함수
		{
			Board_Middle_clear();
			system_("화살에 맞아 치명상을 입었습니다");
			Sleep(3000);
			PlaySound(NULL, 0, 0);
			break;
		}
		Sleep(10);
		count++;
	}
	//getchar();
}