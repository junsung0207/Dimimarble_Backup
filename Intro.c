/*
인트로 화면 부터
유저네임 받는 화면까지..
*/

#include "dimimarble.h"

void Loading() // 로딩 함수
{
	const int MAX = 18; //로딩 바 네모 개수

	char text[11][100] = { {"선생님들 녹음하시는중"}, {"김규빈이 코드짜는중"}, {"관중 모으는중"}, {"배종우선생님 헬스하는중"}, {"로딩바 채우는중"},{"윤준성이 코드짜다 똥싸러가는중"},
	{"보드판 닦는중"}, {"주사위 닦는중"}, {"스페이스바 기름칠 하는중"},{"김상욱쌤 철권하는중"} , {"전희진쌤 타숙실 잡는중"} };
	int stop = 0;            //로딩바 변화주는 변수
	int i = 0, j = 0;
	int textnum = 0;
	int rn;

	gotoxyS(2, 18, "Tip. 친밀도 시스템은 상대적 친밀도지수이며, 플레이어1이 "); //게임 설명 출력
	gotoxyS(2, 19, "높을경우 빨강색, 2가 높을 경우 파란색으로 나타납니다.");

	for (textnum = 0; textnum < 11; textnum++)
	{

		gotoxy(18, 10);
		printf("                              ");
		gotoxy(18, 10);
		printf("%s", text[textnum]);
		for (i = 0; i < MAX; i++) //로딩바가 진행됩니다 ~
		{
			gotoxy(3, 11);
			for (j = 0; j < MAX; j++)
			{
				if (j <= i)
				{
					printf("■ ");
					rn = rand() % 7 + 6;
					if ((j == rn || j == rn + 1 || j == rn + 2) && (textnum == 0 || textnum == 5 || textnum == 8))         //로딩바 렉걸리는 현상
					{
						stop = 400; 
					}
					else stop = 0;
				}
				else
				{
					printf("□ ");
				}
			}

			Sleep(20 + stop);
			stop = 0;


		}

	}

}

void InputUsrName() //유저 네임 입력 받는 함수
{
	system("cls");
	int i, k;
	gotoxyS(30, 2, "1.승리 조건 : 상대가 게임오버");
	gotoxyS(30, 3, "되거나, 대학진학에 성공할경우"); //설명 출력
	gotoxyS(30, 5, "2.게임 진행시 나오는 목소리");
	gotoxyS(30, 6, "는 실제 선생님들의 목소리이며");
	gotoxyS(30, 7, "허락을 받고 사용되었습니다.");
	gotoxyS(30, 9, "3.스토리 전개과정은 게임의 재");
	gotoxyS(30, 10, "미를 위해 허구적 요소가 포함되");
	gotoxyS(30, 11, "어있음을 미리 알려드립니다.");
	gotoxyS(30, 13, "4. 친밀도가 50%이상인 땅에서");
	gotoxyS(30, 14, "추천서를 추출가능합니다");
	gotoxyS(30, 15, "추천서를 보유하고 플레이어가");
	gotoxyS(30, 16, "고3일 경우 대학에 지원할 수 ");
	gotoxyS(30, 17, "있으며,합격여부는 바로나옵니다");

	gotoxyS(4, 3, "______________________");
	gotoxyS(4, 5, "Input your name & Enter ");
	gotoxyS(4, 6, "______________________");
	int player_color[2] = { 12,9 };         //const int   //빨강, 파랑
	while (1)
	{
		if (GetKeyState(VK_RETURN) < 0)            //VK_RETURN : 엔터   /    GetKeyState 엔터키여부
			continue;
		for (i = 0; i < 2; i++)
		{
			gotoxy(3, 8);

			setcolor(15, player_color[i]);         //setcolor(15, 12);            //흰색에 빨강배경
			printf("플레이어%d", i + 1);
			setcolor(0, 15);            //검은색에 흰색배경
			printf("의 닉네임 입력중");

			gotoxyP(3, 10, "(닉네임은 영/한 8자이내로)");
			gotoxyP(2, 12, "입력 : ");
			clearCursor(1);
			do
			{
				gotoxy(8, 12);
				gets(player[i].name);
				gotoxyS(2, 13, "                           ");      //공백처리
				gotoxyS(2, 14, "                           ");      //공백처리 
				gotoxyS(2, 15, "                           ");      //공백처리 
				gotoxyS(2, 16, "                           ");      //공백처리 

				if (i == 1 && (!strcmp(player[0].name, player[1].name)))            //같은 이름이라면 다시.
				{
					gotoxyS(8, 12, "                           ");
					gotoxy(8, 12);
					for (k = 0; k < 15; k++)
					{
						player[1].name[k] = 0;
					}
					setcolor(13, 15);
					gotoxyS(2, 14, "같은 이름입니다.");
					gotoxyS(2, 15, "다시 입력해주세요.");
					setcolor(0, 15);
				}
			} while (strcmp(player[i].name, "") == 0 || player[i].name[0] == ' ');      //공백예외 처리(공백이면 다시 8,12 로 돌아감)
			clearCursor(0);
			gotoxyS(8, 12, "                        ");      //입력받은 곳 초기화
		}

		break;
	}
	system("cls");
	Loading();         //로딩인트로
	Sleep(2000);
}


void MenuIntro() //가장 처음에 보이는 인트로 화면 출력 함수
{
	int inputkeyboard;
	int golever = 1;
	int check = 0;

	system("mode con: cols=60 lines=20"); //인트로 부분은 임의로 콘솔 사이즈를 바꿔줍니다.
	gotoxyS(23, 9, "..Loading...");
	Sleep(2000);
	system("cls");
	while (1)
	{
		gotoxyS(9, 2, "___________________________________________");
		gotoxyS(15, 4, "D  I  M  I      M  A  R  B  L  E");
		gotoxyS(9, 5, "___________________________________________");

		gotoxyS(7, 10, "__________________________________________________");
		gotoxyS(9, 12, "제작:      김규빈      윤준성");
		gotoxyS(7, 13, "__________________________________________________");

		gotoxyP(18, 16, "PLEASE PRESS THE ENTER KEY");

		if (GetKeyState(VK_RETURN) < 0)                  //엔터키 아니면 continue 안됨.
		{
			continue;
		}

		inputkeyboard = _getch();
		switch (inputkeyboard)
		{
		case 13:               //엔터키 누르면 게임 시작 !
			system("cls");
			golever = 0;
			InputUsrName();
			break;
		}
		if (golever == 0)
			break;
	}
}