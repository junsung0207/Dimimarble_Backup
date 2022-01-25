#include "dimimarble.h"

/*
	블루마블을 모티브로 하여 보드게임을 기반으로 진행되는 게임.
	보드판 모양은 블루마블이지만, 일반적인 블루마블과는 다른
	우리만의 게임을 만들기 위해 디미고를 배경으로 게임을 개발.

	이기는 조건 : 대학에 진학하거나, 상대방이 대학 진학에 실패할 경우 승리

	대학 진학을 하려면?
	 - 해당 플레이어가 고3 이상이 되어야함.
	 - 친밀도가 50이상인 땅이 1개 이상이어야 함.

	제작자 : 윤준성, 김규빈
*/



int PresentDice_Num;// 현재 굴린 주사위 수
int Present_P1_MapPoint = 0; // 플레이어 1의 현재 맵 위치
int Present_P2_MapPoint = 0; // 플레이어 2의 현재 맵 위치
int Go; //지금 턴의 지금 플레이어가 선택한 선택지
int C3_event = 0; //허관무 선생님 관련 이벤트 변수
int C1_event = 0; //류명희 선생님 관련 이벤트 변수
int C6_event = 0;//김상욱 선생님 관련 이벤트 변수
int C12_event = 0; //최하은 선생님 관련 이벤트 변수
int C13_event = 0; // 남승완 선생님 관련 이벤트 변수
int C14_event = 0; // 김재영 선생님 관련 이벤트 변수
int Game_over = 0; // 0은 게임 진행, 1은 퇴학, 2는 병역의 의무 ,3은 대학 진학 실패 4는 대학 진학 성공

int P1_Life = 0; //Player 1의 라이프 포인트 입니다. 0 =고1, 1 =고2, 2= 고3, 3 = 재수 1년, 4 = 재수 2년
int P2_Life = 0; //Player 2의 라이프 포인트 입니다. 0 =고1, 1 =고2, 2= 고3, 3 = 재수 1년, 4 = 재수 2년

int MapPoint[20][2] = {													 //Map의 해당 포인트 좌표값 목록
	{5,4} , {21,4} , {37 , 4} , {53 , 4} , {69 , 4} , {85 , 4}, {101, 4}, // 윗줄
																	{101,10},  // 오른쪽 사이드 줄 시작+1
																	{101,16},
																	{101,22},
																	{101,28},
														{85,28}, // 맨 아래 오른쪽
											 {69, 28},
								  {53,28},
					  {37,28},
			 {21,28},
	{5,28}, // 왼쪽 사이드 줄 시작+1
	{5,22},
	{5,16},
	{5,10},
};

int closeness[20] = { 0,100,100,100,100, 100,100,100,100,100, 0,100,100,100,100, 100,100,100,100,100 }; //친밀도 수치 배열

char T_name[20][100] = { {""}, {"류명희 선생님"}, {"함지연 선생님"},{"허관무 선생님"},{"제제 선생님"},
								{"박경수 선생님"},{"김상욱 선생님"},{"배종우 선생님"},{"전희진 선생님"},{"양희정 선생님"},
								{""},{"이택주 선생님"},	{"최하은 선생님"},{"남승완 선생님"},{"김재영 선생님"},
								{"전유원 선생님"},{"이재민 선생님"}, {"하성봉 선생님"}, {"정동윤 선생님"}, {"정희범 선생님"} 
}; //선생님 이름 배열


int main()
{		

		player[0].horse_img = "★";				//1번말
		player[1].horse_img = "♠";				//2번말
		player[0].color = 12;					//빨간말
		player[1].color = 9;					//파란말
		
		int n_n;
		int Game_turn = 0;
		// -- 인트로 부분 -- //
		while (1) { 
			
			PlaySound(TEXT("Game_intro.wav"), 0, SND_FILENAME | SND_ASYNC);
			system("title 디미마블"); // 제목 출력
			system("color F0"); // 배경 컬러 지정
			srand((unsigned int)time(NULL));

			clearCursor(0); // 커서를 지워줍니다.
			system("cls");
			MenuIntro();			//메뉴인트로실행
			system("cls");
			
			//--여기까지 인트로부문--//
			clearCursor(0);
			int d; //dice 게이지 관련 변수
			int c, j = 2, updown_switch = 1;
			int turnplayer = 1; // 현재 턴의 플레이어 값은 1 아니면 2

			Set_Game_Console_Size(); // 콘솔 사이즈 지정
			
			Game_board_print(); //게임 보드 판 출력 함수
			Game_board_contents_print(); //보드 판 위의 컨텐츠 출력 함수
			Game_board_printClosePoint(); //보드 판 위의 친밀도 문구 출력 함수
			print_before_Start(); //턴 시작 전, 주사위 그래픽 출력
			Print_Life(); //라이프 포인트 출력 함수
			printbar(); //주사위 게이지와 보드 외의 다른 그래픽 출력
			state_print(); //플레이어들의 상태 출력
			closeness_recall(); //초기 0으로 되어있는 모든 친밀도 값 출력
			PlaySound(NULL, 0, 0); //게임 시작과 동시에 인트로 노래 멈춤.
			/*Sleep(300);
			paint(hWnd, dpi, bitmap);
			Sleep(10000000);*/
			
			while (1) //턴 돌리는 while 문
			{

				closeness_recall(); //친밀도 값 게속해서 갱신
				setcolor(32, 31); 
				Assistant_Text_clear();
				Board_Middle_clear();
				Game_turn++; //게임 턴 변수(개발용)
				gotoxy(5, 38); 

				n_n = 1; //키보드 게이지 관련 변수(이 변수를 통해 키보드 게이지가 위아래로 움직일 수 있음.
				Go = print_Assistant_Turn_Start(turnplayer - 1); // 해당 턴에 무엇을 할건지 묻는다.
				Print_Life(); //플레이어들의 나이 출력(ex>김규빈- 고1)
				Board_Middle_clear(); //보드의 가운데 부분을 비워줌.
				Dice_0_print(); //다이스 0일때의 그래픽 출력
				if (Go == 0) { //대학 진학 성공했을,
					Game_over = 4; break; //게임이 끝납니다.
				}
				if (Go == 1) { //키보드 게이지를 돌립니다.
					while (n_n) //키보드 게이지 돌리는 함수 출력하는 while 문 (while문의 kbhit()함수가 스페이스바 입력 여부 판단
					{
						Dice_space_helper(1); //'스페이스바를 누르세요' 문자열 출력
						updown_switch = Dice_Go(&j, updown_switch); //게이지가 위아래로 왔다갔다 합니다.
						while (_kbhit()) {
							d = _getch(); //게이지가 움직이는 도중 스페이스 바 입력을 받습니다.
							if (d == 32) { n_n = 0; } //스페이스 바를 누를시, 게이지가 멈춤과 동시에 다이스 값 전역변수에 랜덤으로 값이 들어갑니다.
							// ---------------발표용 주사위 조작 코드 입니다 -------------//
							
							/* 여기서부터 6줄은 치트코드입니다. <= 이 주석을 없애시고, 주사위 게이지 입력 창에서 스페이스 대신에 키보드 1,2,3,4,5,6 을 누르시면 해당 번호만큼
								말이 이동합니다. 발표할때도 사용하는 코드입니다.*/
							if (d == 49) { n_n = 0; PresentDice_Num = 1; }
							if (d == 50) { n_n = 0; PresentDice_Num = 2; }
							if (d == 51) { n_n = 0; PresentDice_Num = 3; }
							if (d == 52) { n_n = 0; PresentDice_Num = 4; }
							if (d == 53) { n_n = 0; PresentDice_Num = 5; }
							if (d == 54) { n_n = 0; PresentDice_Num = 6; } 
							
							
							// -------------------------------------------------------------//
						}
					}
				}
				Dice_space_helper(0); //스페이스 바를 누르라고 도와주는 문자열 출력하는 함수
				Dice_Bar_clear(); //다이스 게이지 비워주는함수
				PlaySound(TEXT("Dice.wav"), 0, SND_FILENAME | SND_ASYNC);
				Assistant_Text_clear(); // Assistant 부분의 문자열 비워주는 함수
				Sleep(500);
				Display_Dice(PresentDice_Num); //다이스 그래픽 출력
				Sleep(1000);
				How_Much_Go(PresentDice_Num); // ~칸 이동했습니다 문자열 출력 함수
				Go_To_MapPoint(turnplayer, PresentDice_Num); //해당 주사위 숫자만큼 맵을 이동
				Dice_0_print(); //다이스가 0일때의 그래픽 출력
				Assistant_Text_clear(); //Assistant 창의 모든 내용을 지웁니다.
				//printf("%d", Present_P1_MapPoint); // *개발을 위한 임시 구문*
				if (turnplayer == 1) print_What_Should_I_Do(Present_P1_MapPoint%20, turnplayer); //첫번째 플레이어 말 이동 후 스토리 출력


				//if (turnplayer == 1) print_What_Should_I_Do(5, turnplayer); // 개발을 위한 임시 구문
				//else print_What_Should_I_Do(3, turnplayer);

				else print_What_Should_I_Do(Present_P2_MapPoint % 20, turnplayer); //두번째 플레이어 말 이동후 스토리 출력
				CL_board_error(); //보드 출력의 오류를 고쳐주는 함수
				Dice_0_print(); //다이스가 0일때의 그래픽 출력 함수
				Assistant_boarder_print(); //어시스턴트의 창 출력 함수(미니게임 시에 오류가 있는 어시스턴트 창을 바로잡아 줍니다)
				Print_Life(); // 라이프 포인트 출력(고1,고2,고3)
				if (P1_Life > 4 || P2_Life > 4) // 두 플레이어의 라이프 포인트 둘중 하나라도 재수 1년이 넘으면 병역의 의무로 게임이 종료됩니다
				{
					Game_over = 2; //2 = 병역의 의무 , Game_over_print 함수에 게임 오버의 원인을 넘겨줍니다.
				}
				if (Game_over != 0) break; //게임 오버 변수가 0이 아니면 더이상 턴이 진행되지 않습니다.
				if (turnplayer == 1)  turnplayer = 2; //다음 턴에 다른 플레이어로 턴을 넘겨줍니다. (turnplayer = 1 또는 2)
				else turnplayer = 1;
				closeness_recall(); //모든 친밀도 값을 갱신해줍니다.
			}
			Game_over_print(Game_over, turnplayer);
			Game_over = 0;
			if (RE_GAME()) {
				Present_P1_MapPoint = 0; // 플레이어 1의 현재 맵 위치
				Present_P2_MapPoint = 0; // 플레이어 2의 현재 맵 위치
				C3_event = 0; //허관무 선생님 관련 이벤트 변수
				C1_event = 0;
				C6_event = 0; //김상욱 선생님 관련 이벤트 변수
				C13_event = 0; // 남승완 선생님 관련 이벤트 변수
				C14_event = 0; // 김재영 선생님 관련 이벤트 변수
				Game_over = 0;
				Game_turn = 0;
				for (int k = 0; k < 20; k++) { //모든 친밀도 값을 초기화 해줍니다.
					if (k == 0 || k == 10)
						closeness[k] = 0;
					else
						closeness[k] = 100;
				}
				P1_Life = 0;
				P2_Life = 0;
				continue;
			}
			else
				break;
		}
		// 게임 끝.
}
