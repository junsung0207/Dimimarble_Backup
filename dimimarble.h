#ifndef __DIMI_H__			//��ũ�θ� : __DIMI_H__			//c++���� pragma once

#define __DIMI_H__			//���� ����:

//////////////�ش�����////////////
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <WinUser.h>>

#pragma comment(lib, "winmm.lib")
#pragma warning(disable : 4996)				//��Ʈ���Լ� ��� ����
////////////////////////////////

#define YES 1
#define NO 0
#define ENTER 13			//����Ű ��
#define PERSON 2			//2���÷���
#define WIDTH 136			//��Ʈ�� ��, �ΰ���ȭ��
#define HEIGHT 46			//��Ʈ�� ��, �ΰ���ȭ��
#define DICE_X 75
#define DICE_Y 14
#define Console_start_x 5
#define Console_end_x 84

#define ARROW_NUM 30	//�ڰ�������� ��Ʈ �κ� ȭ�찳��
#define RIGHT 77
#define LEFT 75
#define MAX_SPEED 5		//ȭ�� ���ǵ�


extern int PresentDice_Num; //���� ���� �ֻ����� ���� ���� ����
extern int Present_P1_MapPoint; //�÷��̾� 1�� ������Ʈ
extern int Present_P2_MapPoint; //�÷��̾� 2�� ������Ʈ
extern int MapPoint[20][2]; //������Ʈ �迭
// ------�̺�Ʈ ���� ���� =--------//
extern int C3_event;
extern int C1_event;
extern int C6_event;
extern int C12_event;
extern int C13_event;
extern int C14_event;
// ----------------------------------//
extern int closeness[20]; //ģ�е� ���� �迭
extern char T_name[20][100]; //�����Ե� �̸� �迭
extern const int dice_design[7][9][9]; //�ֻ��� �׷��� �迭
extern int Game_over; //���� ���� ���� �Ǵ� ����
extern int P1_Life; //�÷��̾� 1�� Life ����Ʈ
extern int P2_Life; //�÷��̾� 2�� Life����Ʈ

/////////////////////����ü///////////////
struct PLAYER {
	int color;			//����, �Ķ� ���� ����
	char name[100];
	int who;
	int x, y;			//�÷��̾� ��ġ ��ǥ��
	int stage;			//1,2,3 ��������. 4���������� ������ �ǹ�
	int bp;				//���׵� ����Ʈ
	char * horse_img;	//�� �̹���. //�� �̹����� ĳ���� ������ ��������.

	//
	//

}player[2];




typedef struct _Teacher {
	int closeness; // �����԰��� ģ�е�
	int point;
	int recommend_card; // 1,0 ���� �����Ǹ� �ش� �������� ��õ�� ����
}Teacher;

typedef struct _Arrow //ȭ�� �̴ϰ��ӿ� �ʿ��� ȭ�� ����ü
{
	int x, y, speed;
}Arrow;


/////////////////////////////////////////////////////////////////////////////////////////////////////////

//���� �Լ�(General purpose functioin.c) ���

void clearCursor(char state);		//Ŀ�����¸� �Ű������� 1�Ǵ�0			//1�϶� ����		0�϶� ����
void gotoxy(int x, int y); // ��ǥ�� �̵�
void gotoxyS(int x, int y, char *str); // ��ǥ������ �̵� �� ���ڿ� �ѹ��� ���
void gotoxyP(int x, int y, char *str);		//��ǥ������ �̵� �� ���ڿ����
void setcolor(int color, int bgcolor);			//���ڻ� / ��׶����
/*���� �Լ� �� */


void InputUsrName(); //�÷��̾� �̸� �Է¹޴� �Լ�
void MenuIntro(); //��Ʈ�� ��� �Լ�




void Set_Game_Console_Size(); // �ܼ� ������ ��� �Լ�
void Game_board_print(); // ���� ���� ��� �Լ�
void Game_board_contents_print(); //������ ���빰�� ��� �Լ�
void Assistant_boarder_print(); //Assistant â�� ���� �κи� �ٽ� ���
void Dice_space_helper(int n); //DIce �����̽� �ٸ� �������� �� �˷��ִ� �Լ�
void print_before_Start();		//����ȭ�� ���̽� ��� �Լ��� ����.
void printbar();						//���̽� �� ����Լ�
void state_print();				//�÷��̾�������
int print_Assistant_Turn_Start(int player_num); //�ϸ��� ������ �Ͻǰǰ��� ���� �ش� ��ȣ �����ϴ� �Լ�
void Assistant_Text_clear(); //��ý���Ʈ â�� ���� �κ� ���� �Լ�
void Go_To_MapPoint(int turnplayer, int PN); //�ش� ������Ʈ�� �̵��ϴ� �Լ�
void How_Much_Go(int n); //~ĭ �̵��߽��ϴ� ���ڿ� ��� �Լ�
void print_What_Should_I_Do(int Now_Point, int turnplayer); //**���� ����** �� ������ ĭ���� ������ �ؾ��ϴ� �� �˷��ִ� �Լ�
void AQC(); //assistant�� question �κ��� ����ִ� �Լ�
void Game_board_printClosePoint(); //���� "ģ�е�:" �κ� ��� �Լ�
void Board_Middle_clear(); //���� ��� �� �ո� �κ� clear�Լ�
int Is_it_right_num(int n, int range); //�������� ���ڸ� �÷��̾ �Է������� ������ ���� ���� ���ڰ� ������ �״�� ����, Ʋ���� 0 ���� �Լ�
void closeness_recall(); //ģ�е� ��ġ �Ź� �������ִ� �Լ�
void system_(char *a); //assistant ���ڿ� ��� �ڵ带 �ۼ��Ҷ� ���ϰ� ���ִ� �Լ� (�����ڿ�)
void closeness_up(int Now_Point, int C, int turnplayer); // ģ�е� �� �Լ�
void closeness_down(int Now_Point, int C, int turnplayer); // ģ�е� �ٿ� �Լ�
void player_Talk(int turnplayer, char *a); //Assistant â���� �÷��̾� ��ȭ ��� �Լ�
void Print_Life(); //�÷��̾���� LIFE ����Ʈ ��� �Լ�
void CL_board_error(); //Assistant â�� ����Ʈ ���� �ذ� �Լ�

int Dice_Go(int *j, int updown_switch); //�ֻ��� ������ ���� �Լ�
void Dice_Bar_clear(); //Dice������ Ŭ���� �Լ�
void Dice_0_print(); //Dice 0 �϶� ���̽� �׷��� ��� �Լ�
void Display_Dice(int i); //���̽� �׷��� ��� �Լ�
//int Dice_printRand(int i); //�ֻ��� �������� ���� ���� �ֻ����� ���������� ����Ʈ ���ִ� �Լ�
void Game_over_print(int a, int turnplayer); //���� ���� ȭ�� ��� �Լ�
int RE_GAME(); //���� �ٽ� �����ϴ� ���� ���θ� ���� �Լ�
void avoidArrow();							//ȭ�� ���ϴ� �̴ϰ���
int print_Song();					//�뷡 ���ߴ� ���� �Լ�
int Can_I_Go(int turnplayer); //��õ���� ���� �� �ִ��� �˷��ִ� �Լ�
int Can_I_am_onAge(int turnplayer); //��3�� �Ǿ����� �Ǵ����ִ� �Լ�
int Goto_Dahak(turnplayer); //���� ���� �Լ�

/////////////////////////////////////////////////////

#endif					//END