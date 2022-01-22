#ifndef __DIMI_H__			//매크로명 : __DIMI_H__			//c++에선 pragma once

#define __DIMI_H__			//내용 시작:

//////////////해더파일////////////
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <WinUser.h>>

#pragma comment(lib, "winmm.lib")
#pragma warning(disable : 4996)				//스트링함수 경고 제거
////////////////////////////////

#define YES 1
#define NO 0
#define ENTER 13			//엔터키 값
#define PERSON 2			//2인플레이
#define WIDTH 136			//인트로 후, 인게임화면
#define HEIGHT 46			//인트로 후, 인게임화면
#define DICE_X 75
#define DICE_Y 14
#define Console_start_x 5
#define Console_end_x 84

#define ARROW_NUM 30	//박경수선생님 파트 부분 화살개수
#define RIGHT 77
#define LEFT 75
#define MAX_SPEED 5		//화살 스피드


extern int PresentDice_Num; //현재 굴린 주사위의 숫자 저장 변수
extern int Present_P1_MapPoint; //플레이어 1의 맵포인트
extern int Present_P2_MapPoint; //플레이어 2의 맵포인트
extern int MapPoint[20][2]; //맵포인트 배열
// ------이벤트 관련 변수 =--------//
extern int C3_event;
extern int C1_event;
extern int C6_event;
extern int C12_event;
extern int C13_event;
extern int C14_event;
// ----------------------------------//
extern int closeness[20]; //친밀도 관련 배열
extern char T_name[20][100]; //선생님들 이름 배열
extern const int dice_design[7][9][9]; //주사위 그래픽 배열
extern int Game_over; //게임 오버 여부 판단 변수
extern int P1_Life; //플레이어 1의 Life 포인트
extern int P2_Life; //플레이어 2의 Life포인트

/////////////////////구조체///////////////
struct PLAYER {
	int color;			//빨강, 파랑 으로 고정
	char name[100];
	int who;
	int x, y;			//플레이어 위치 좌표값
	int stage;			//1,2,3 스테이지. 4스테이지시 병역의 의무
	int bp;				//베네듀 포인트
	char * horse_img;	//말 이미지. //말 이미지는 캐릭터 변수로 받지못함.

	//
	//

}player[2];




typedef struct _Teacher {
	int closeness; // 선생님과의 친밀도
	int point;
	int recommend_card; // 1,0 으로 결정되며 해당 선생님의 추천서 유무
}Teacher;

typedef struct _Arrow //화살 미니게임에 필요한 화살 구조체
{
	int x, y, speed;
}Arrow;


/////////////////////////////////////////////////////////////////////////////////////////////////////////

//범용 함수(General purpose functioin.c) 목록

void clearCursor(char state);		//커서상태를 매개변수로 1또는0			//1일때 보임		0일때 숨김
void gotoxy(int x, int y); // 좌표값 이동
void gotoxyS(int x, int y, char *str); // 좌표값으로 이동 후 문자열 한번에 출력
void gotoxyP(int x, int y, char *str);		//좌표값으로 이동 후 문자열출력
void setcolor(int color, int bgcolor);			//글자색 / 백그라운드색
/*범용 함수 끝 */


void InputUsrName(); //플레이어 이름 입력받는 함수
void MenuIntro(); //인트로 출력 함수




void Set_Game_Console_Size(); // 콘솔 사이즈 출력 함수
void Game_board_print(); // 게임 보드 출력 함수
void Game_board_contents_print(); //보드의 내용물들 출력 함수
void Assistant_boarder_print(); //Assistant 창의 보더 부분만 다시 출력
void Dice_space_helper(int n); //DIce 스페이스 바를 누르세요 라 알려주는 함수
void print_before_Start();		//시작화면 다이스 출력 함수도 포함.
void printbar();						//다이스 바 출력함수
void state_print();				//플레이어상태출력
int print_Assistant_Turn_Start(int player_num); //턴마다 무엇을 하실건가요 묻고 해당 번호 리턴하는 함수
void Assistant_Text_clear(); //어시스턴트 창의 안쪽 부분 비우는 함수
void Go_To_MapPoint(int turnplayer, int PN); //해당 맵포인트로 이동하는 함수
void How_Much_Go(int n); //~칸 이동했습니다 문자열 출력 함수
void print_What_Should_I_Do(int Now_Point, int turnplayer); //**이쪽 수정** 막 도착한 칸에서 무엇을 해야하는 지 알려주는 함수
void AQC(); //assistant의 question 부분을 비워주는 함수
void Game_board_printClosePoint(); //맵의 "친밀도:" 부분 출력 함수
void Board_Middle_clear(); //맵의 가운데 뻥 뚫린 부분 clear함수
int Is_it_right_num(int n, int range); //선택지의 숫자를 플레이어가 입력했을때 선택지 범위 안의 숫자가 맞으면 그대로 리턴, 틀리면 0 리턴 함수
void closeness_recall(); //친밀도 수치 매번 리필해주는 함수
void system_(char *a); //assistant 문자열 출력 코드를 작성할때 편하게 해주는 함수 (개발자용)
void closeness_up(int Now_Point, int C, int turnplayer); // 친밀도 업 함수
void closeness_down(int Now_Point, int C, int turnplayer); // 친밀도 다운 함수
void player_Talk(int turnplayer, char *a); //Assistant 창에서 플레이어 대화 출력 함수
void Print_Life(); //플레이어들의 LIFE 포인트 출력 함수
void CL_board_error(); //Assistant 창의 프린트 오류 해결 함수

int Dice_Go(int *j, int updown_switch); //주사위 게이지 차는 함수
void Dice_Bar_clear(); //Dice게이지 클리어 함수
void Dice_0_print(); //Dice 0 일때 다이스 그래픽 출력 함수
void Display_Dice(int i); //다이스 그래픽 출력 함수
//int Dice_printRand(int i); //주사위 게이지가 차는 동안 주사위를 순차적으로 프린트 해주는 함수
void Game_over_print(int a, int turnplayer); //게임 오버 화면 출력 함수
int RE_GAME(); //게임 다시 시작하는 지의 여부를 묻는 함수
void avoidArrow();							//화살 피하는 미니게임
int print_Song();					//노래 맞추는 게임 함수
int Can_I_Go(int turnplayer); //추천서를 써줄 수 있는지 알려주는 함수
int Can_I_am_onAge(int turnplayer); //고3이 되었는지 판단해주는 함수
int Goto_Dahak(turnplayer); //대학 가는 함수

/////////////////////////////////////////////////////

#endif					//END