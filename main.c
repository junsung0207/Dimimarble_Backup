#include "dimimarble.h"

/*
	��縶���� ��Ƽ��� �Ͽ� ��������� ������� ����Ǵ� ����.
	������ ����� ��縶��������, �Ϲ����� ��縶����� �ٸ�
	�츮���� ������ ����� ���� ��̰� ������� ������ ����.

	�̱�� ���� : ���п� �����ϰų�, ������ ���� ���п� ������ ��� �¸�

	���� ������ �Ϸ���?
	 - �ش� �÷��̾ ��3 �̻��� �Ǿ����.
	 - ģ�е��� 50�̻��� ���� 1�� �̻��̾�� ��.

	������ : ���ؼ�, ��Ժ�
*/



int PresentDice_Num;// ���� ���� �ֻ��� ��
int Present_P1_MapPoint = 0; // �÷��̾� 1�� ���� �� ��ġ
int Present_P2_MapPoint = 0; // �÷��̾� 2�� ���� �� ��ġ
int Go; //���� ���� ���� �÷��̾ ������ ������
int C3_event = 0; //����� ������ ���� �̺�Ʈ ����
int C1_event = 0; //������ ������ ���� �̺�Ʈ ����
int C6_event = 0;//���� ������ ���� �̺�Ʈ ����
int C12_event = 0; //������ ������ ���� �̺�Ʈ ����
int C13_event = 0; // ���¿� ������ ���� �̺�Ʈ ����
int C14_event = 0; // ���翵 ������ ���� �̺�Ʈ ����
int Game_over = 0; // 0�� ���� ����, 1�� ����, 2�� ������ �ǹ� ,3�� ���� ���� ���� 4�� ���� ���� ����

int P1_Life = 0; //Player 1�� ������ ����Ʈ �Դϴ�. 0 =��1, 1 =��2, 2= ��3, 3 = ��� 1��, 4 = ��� 2��
int P2_Life = 0; //Player 2�� ������ ����Ʈ �Դϴ�. 0 =��1, 1 =��2, 2= ��3, 3 = ��� 1��, 4 = ��� 2��

int MapPoint[20][2] = {													 //Map�� �ش� ����Ʈ ��ǥ�� ���
	{5,4} , {21,4} , {37 , 4} , {53 , 4} , {69 , 4} , {85 , 4}, {101, 4}, // ����
																	{101,10},  // ������ ���̵� �� ����+1
																	{101,16},
																	{101,22},
																	{101,28},
														{85,28}, // �� �Ʒ� ������
											 {69, 28},
								  {53,28},
					  {37,28},
			 {21,28},
	{5,28}, // ���� ���̵� �� ����+1
	{5,22},
	{5,16},
	{5,10},
};

int closeness[20] = { 0,100,100,100,100, 100,100,100,100,100, 0,100,100,100,100, 100,100,100,100,100 }; //ģ�е� ��ġ �迭

char T_name[20][100] = { {""}, {"������ ������"}, {"������ ������"},{"����� ������"},{"���� ������"},
								{"�ڰ�� ������"},{"���� ������"},{"������ ������"},{"������ ������"},{"������ ������"},
								{""},{"������ ������"},	{"������ ������"},{"���¿� ������"},{"���翵 ������"},
								{"������ ������"},{"����� ������"}, {"�ϼ��� ������"}, {"������ ������"}, {"����� ������"} 
}; //������ �̸� �迭


int main()
{		

		player[0].horse_img = "��";				//1����
		player[1].horse_img = "��";				//2����
		player[0].color = 12;					//������
		player[1].color = 9;					//�Ķ���
		
		int n_n;
		int Game_turn = 0;
		// -- ��Ʈ�� �κ� -- //
		while (1) { 
			
			PlaySound(TEXT("Game_intro.wav"), 0, SND_FILENAME | SND_ASYNC);
			system("title ��̸���"); // ���� ���
			system("color F0"); // ��� �÷� ����
			srand((unsigned int)time(NULL));

			clearCursor(0); // Ŀ���� �����ݴϴ�.
			system("cls");
			MenuIntro();			//�޴���Ʈ�ν���
			system("cls");
			
			//--������� ��Ʈ�κι�--//
			clearCursor(0);
			int d; //dice ������ ���� ����
			int c, j = 2, updown_switch = 1;
			int turnplayer = 1; // ���� ���� �÷��̾� ���� 1 �ƴϸ� 2

			Set_Game_Console_Size(); // �ܼ� ������ ����
			
			Game_board_print(); //���� ���� �� ��� �Լ�
			Game_board_contents_print(); //���� �� ���� ������ ��� �Լ�
			Game_board_printClosePoint(); //���� �� ���� ģ�е� ���� ��� �Լ�
			print_before_Start(); //�� ���� ��, �ֻ��� �׷��� ���
			Print_Life(); //������ ����Ʈ ��� �Լ�
			printbar(); //�ֻ��� �������� ���� ���� �ٸ� �׷��� ���
			state_print(); //�÷��̾���� ���� ���
			closeness_recall(); //�ʱ� 0���� �Ǿ��ִ� ��� ģ�е� �� ���
			PlaySound(NULL, 0, 0); //���� ���۰� ���ÿ� ��Ʈ�� �뷡 ����.
			/*Sleep(300);
			paint(hWnd, dpi, bitmap);
			Sleep(10000000);*/
			
			while (1) //�� ������ while ��
			{

				closeness_recall(); //ģ�е� �� �Լ��ؼ� ����
				setcolor(32, 31); 
				Assistant_Text_clear();
				Board_Middle_clear();
				Game_turn++; //���� �� ����(���߿�)
				gotoxy(5, 38); 

				n_n = 1; //Ű���� ������ ���� ����(�� ������ ���� Ű���� �������� ���Ʒ��� ������ �� ����.
				Go = print_Assistant_Turn_Start(turnplayer - 1); // �ش� �Ͽ� ������ �Ұ��� ���´�.
				Print_Life(); //�÷��̾���� ���� ���(ex>��Ժ�- ��1)
				Board_Middle_clear(); //������ ��� �κ��� �����.
				Dice_0_print(); //���̽� 0�϶��� �׷��� ���
				if (Go == 0) { //���� ���� ����������,
					Game_over = 4; break; //������ �����ϴ�.
				}
				if (Go == 1) { //Ű���� �������� �����ϴ�.
					while (n_n) //Ű���� ������ ������ �Լ� ����ϴ� while �� (while���� kbhit()�Լ��� �����̽��� �Է� ���� �Ǵ�
					{
						Dice_space_helper(1); //'�����̽��ٸ� ��������' ���ڿ� ���
						updown_switch = Dice_Go(&j, updown_switch); //�������� ���Ʒ��� �Դٰ��� �մϴ�.
						while (_kbhit()) {
							d = _getch(); //�������� �����̴� ���� �����̽� �� �Է��� �޽��ϴ�.
							if (d == 32) { n_n = 0; } //�����̽� �ٸ� ������, �������� ����� ���ÿ� ���̽� �� ���������� �������� ���� ���ϴ�.
							// ---------------��ǥ�� �ֻ��� ���� �ڵ� �Դϴ� -------------//
							
							/* <= �� �ּ��� ���ֽð�, �ֻ��� ������ �Է� â���� �����̽� ��ſ� Ű���� 1,2,3,4,5,6 �� �����ø� �ش� ��ȣ��ŭ
								���� �̵��մϴ� ^^ ���Ͻ� ���� �����ϰ� ���ּ��� ~ ��ǥ�Ҷ��� ����ϴ� �ڵ��Դϴ�.*/
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
				Dice_space_helper(0); //�����̽� �ٸ� ������� �����ִ� ���ڿ� ����ϴ� �Լ�
				Dice_Bar_clear(); //���̽� ������ ����ִ��Լ�
				PlaySound(TEXT("Dice.wav"), 0, SND_FILENAME | SND_ASYNC);
				Assistant_Text_clear(); // Assistant �κ��� ���ڿ� ����ִ� �Լ�
				Sleep(500);
				Display_Dice(PresentDice_Num); //���̽� �׷��� ���
				Sleep(1000);
				How_Much_Go(PresentDice_Num); // ~ĭ �̵��߽��ϴ� ���ڿ� ��� �Լ�
				Go_To_MapPoint(turnplayer, PresentDice_Num); //�ش� �ֻ��� ���ڸ�ŭ ���� �̵�
				Dice_0_print(); //���̽��� 0�϶��� �׷��� ���
				Assistant_Text_clear(); //Assistant â�� ��� ������ ����ϴ�.
				//printf("%d", Present_P1_MapPoint); // *������ ���� �ӽ� ����*
				if (turnplayer == 1) print_What_Should_I_Do(Present_P1_MapPoint%20, turnplayer); //ù��° �÷��̾� �� �̵� �� ���丮 ���


				//if (turnplayer == 1) print_What_Should_I_Do(5, turnplayer); // ������ ���� �ӽ� ����
				//else print_What_Should_I_Do(3, turnplayer);

				else print_What_Should_I_Do(Present_P2_MapPoint % 20, turnplayer); //�ι�° �÷��̾� �� �̵��� ���丮 ���
				CL_board_error(); //���� ����� ������ �����ִ� �Լ�
				Dice_0_print(); //���̽��� 0�϶��� �׷��� ��� �Լ�
				Assistant_boarder_print(); //��ý���Ʈ�� â ��� �Լ�(�̴ϰ��� �ÿ� ������ �ִ� ��ý���Ʈ â�� �ٷ���� �ݴϴ�)
				Print_Life(); // ������ ����Ʈ ���(��1,��2,��3)
				if (P1_Life > 4 || P2_Life > 4) // �� �÷��̾��� ������ ����Ʈ ���� �ϳ��� ��� 1���� ������ ������ �ǹ��� ������ ����˴ϴ�
				{
					Game_over = 2; //2 = ������ �ǹ� , Game_over_print �Լ��� ���� ������ ������ �Ѱ��ݴϴ�.
				}
				if (Game_over != 0) break; //���� ���� ������ 0�� �ƴϸ� ���̻� ���� ������� �ʽ��ϴ�.
				if (turnplayer == 1)  turnplayer = 2; //���� �Ͽ� �ٸ� �÷��̾�� ���� �Ѱ��ݴϴ�. (turnplayer = 1 �Ǵ� 2)
				else turnplayer = 1;
				closeness_recall(); //��� ģ�е� ���� �������ݴϴ�.
			}
			Game_over_print(Game_over, turnplayer);
			Game_over = 0;
			if (RE_GAME()) {
				Present_P1_MapPoint = 0; // �÷��̾� 1�� ���� �� ��ġ
				Present_P2_MapPoint = 0; // �÷��̾� 2�� ���� �� ��ġ
				C3_event = 0; //����� ������ ���� �̺�Ʈ ����
				C1_event = 0;
				C6_event = 0; //���� ������ ���� �̺�Ʈ ����
				C13_event = 0; // ���¿� ������ ���� �̺�Ʈ ����
				C14_event = 0; // ���翵 ������ ���� �̺�Ʈ ����
				Game_over = 0;
				Game_turn = 0;
				for (int k = 0; k < 20; k++) { //��� ģ�е� ���� �ʱ�ȭ ���ݴϴ�.
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
		// ���� ��.
}
