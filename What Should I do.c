#include "dimimarble.h"

void print_What_Should_I_Do(int Now_Point, int turnplayer) {
	setcolor(32, 7);
	int n = 0;
	char English_T[100];
	int rn, w;
	int Story = 2100;
	char chTemp[200] = { 0 };
	switch (Now_Point)
	{
	case 0: //�ƶ�ũ ���̽� ���丮
		system_( "����� �ƶ�ũ �Դϴ�");
		Sleep(Story);
		AQC();
		system_("�ķ��� �������ִ� �����Դϴ�");
		Sleep(Story);
		AQC();
		system_("���� ���ִ� ���ĵ� �ش�ϴ� !");
		Sleep(Story / 2);
		AQC();
		rn = rand() % 6;
		if (rn == 0) {
			system_("�丶�並 �Ծ����ϴ� !");
			Sleep(Story / 2);
			AQC();
			system_("���־ ��ĭ ������ ���ϴ�.");
		}
		else if (rn == 1) {
			system_("����� �Ծ����ϴ� !");
			Sleep(Story / 2);
			AQC();
			system_("���־ ��ĭ ������ ���ϴ�.");
		}
		else if (rn == 2) {
			system_("���̽�ũ���� �Ծ����ϴ� !");
			Sleep(Story / 2);
			AQC();
			system_("���־ ��ĭ ������ ���ϴ�.");
		}
		else if (rn == 3) {
			system_("���� �ߴٸ��� �Ծ����ϴ� !");
			Sleep(Story / 2);
			AQC();
			system_("���־ ��ĭ ������ ���ϴ�.");
		}
		else if (rn == 4) {
			system_("��ġ�����쵿�� �Ծ����ϴ� !");
			Sleep(Story / 2);
			AQC();
			system_("�ʹ� ���־ �ټ�ĭ ������ ���ϴ�.");
		}
		else if (rn == 5) {
			system_("�δ���� �Ծ����ϴ� !");
			Sleep(Story / 2);
			AQC();
			system_("���� �� ������ ���־ �ټ�ĭ ������ ���ϴ�.");
		}
		Sleep(Story);
		AQC();
		gotoxy(5, 34);
		printf("%dĭ �̵��߽��ϴ�", rn + 1);
		Go_To_MapPoint(turnplayer, rn + 1);
		Sleep(Story);
		break;
	case 1: // ������ �����Խ��丮 ���̽�
		gotoxyP(5, 34, "����� ������ �����Բ��� ����ϰ� �ɾ� ��ʴϴ� ! ");
		PlaySound(TEXT("RyuM.wav"), 0, SND_FILENAME | SND_ASYNC);
		if (closeness[Now_Point] >= 150 && turnplayer == 2)  //ģ�е� ���� IF��
		{
			Sleep(Story);
			AQC();
			sprintf(chTemp, "%s �ݾ�! ȣȣ�P �����̴�?", player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
		}
		else if (closeness[Now_Point] <= 50 && turnplayer == 1)
		{
			Sleep(Story);
			AQC();
			sprintf(chTemp, "%s �ݾ�! ȣȣ�P �����̴� ? ", player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
		}

		Sleep(Story);
		setcolor(32, 7);
		AQC();

		gotoxyP(5, 34, "������ �Ͻðڽ��ϱ�? ");
		Sleep(Story / 3);
		w = 1;
		while (w) { //�Է��� �޴� while ��
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ������ �������� �����縦 �Ѵ� ");
			gotoxyP(5, 37, "2. �׳� ���´�.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2); //�Է��� ���� ���������ִ��� ������ �Ǵ����ִ� �Լ�
		}
		setcolor(32, 31);
		Assistant_Text_clear(); 
		w = 1;
		if (n == 1)
		{
			while (w) {
				gotoxyP(5, 36, "1. ������~ ������~");
				gotoxyP(5, 37, "2. �� ���� ������ �����ϸ�~ ");
				gotoxyP(5, 38, "3. �� Ǯ ���԰� �ִ� �Ҹ� �ϰ� �ֳ�~ ");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 3);
			}
			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 1)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "������ ������ : ��� �� ���� �� �����ϴ� �Ŵ�?");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "�� ���� ����پ����K");
				Sleep(Story);
				AQC();
				system_("ģ�е��� 40 ����߽��ϴ�! ");
				closeness_up(Now_Point, 40, turnplayer);
				Sleep(Story / 2);
				break;
			}
			else if (n == 2)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "������ ������ : ��� �� ���� �� �����ϴ� �Ŵ�?");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ������: Ǫ��, �׷��� �� �ð��� ���й����� �ϳ� �� Ǯ�� !");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 20, turnplayer);
				Sleep(Story / 2);
				break;
			}
			else if (n == 3)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "������ ������ : ��� �� ���� �� �����ϴ� �Ŵ�?");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ������: ���� ���� �׷��� !!");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story / 2);
				break;
			}
		}
		else {
			system_("������ ���Դ� ! ");
			Sleep(Story / 3);
			break;
		}
		break;
	case 2: //������ ������ ���丮 ���̽�
		setcolor(32, 7);
		gotoxyP(5, 34, "����� ������ �����Բ��� �ù� ������ �ϰ� ��ʴϴ� ! ");
		PlaySound(TEXT("HamG.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 31);
		AQC();
		setcolor(32, 7);
		gotoxyP(5, 34, "�ʹ� �ٻڽŰ� ���� �ǵ帱 ���� �����ϴ�. ");
		Sleep(Story*0.6);
		setcolor(32, 31);
		AQC();
		w = 1;
		while (w) {
			setcolor(32, 7);
			gotoxyP(5, 34, "������ �Ͻðڽ��ϱ�?");
			Sleep(Story / 3);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. �׷��� ���پ��� ������ �ٰ������� . ");
			gotoxyP(5, 37, "2. �ʹ� �ٻڽŰ� ���� �׳� ���߰ڴ� . ");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
			Story = 0;
		}
		Story = 3000;
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1)
		{
			setcolor(32, 31);
			AQC();
			rn = rand() % 3;
			if (rn == 0)
			{
				gotoxyP(5, 34, "������ ������ : ��ξ� ���� ? ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "����� : �� , �ƴϿ���. (���ϰ� ���ĸ� ����) ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "������ ������ : ����� �ȵǰڳ� ? ");
				Sleep(Story / 2);
				AQC();
				system_("�����Բ����� (��)����� ȥ���ô��� �ٻڽŵ� �ϴ�");
				Sleep(Story);
				AQC();
				break;
			}
			else if (rn == 1)
			{
				gotoxyP(5, 34, "������ ������ : �⼮�� ���� ? ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "�Ǳ⼮ : ��..����.. ! (���ϰ� ���ͳ� �������� ����)");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "�Ǳ⼮ : ��..��೪���� ..!");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "������ ������ : �⼮�� ����� �Ŵ� ? ");
				Sleep(Story / 2);
				AQC();
				system_("�����Բ����� (��)�⼮�� ���� ���˾Ƶ����� �� �ϴ�");
				Sleep(Story);
				AQC();
				break;
			}
			else if (rn == 2)
			{
				gotoxyP(5, 34, "������ ������ : �Ǿ� ���� ? ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "�̰� : (���ϰ� ��Ʈ���� ����) �� �̰� �׳� �� ���� �� �׳� �ϴٰ� �׳�");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "�̰� : �� ���߾�� �ƹ��͵� ������ ���߾��. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ������ : ���� �����ϳ� ~ ?");
				Sleep(Story);
				AQC();
				system_("���̰� �����ߴٴ� ����� �Ϸ����ƴ���, ������ �����Բ��� �幵���ϽŴ�. ");
				Sleep(Story);
				AQC();
				break;
			}
			break;
		}
		else
		{
			rn = rand() % 5;
			if (rn == 0 || rn == 1)
			{
				setcolor(32, 7);
				gotoxyP(5, 34, "���� �׳� ����� ���� ���̽Ŵ�. ");
				setcolor(32, 31);
				Sleep(Story*0.6);
				AQC();
				setcolor(32, 7);
				gotoxyP(5, 34, "ģ�е��� 10 ����߽��ϴ�! ");
				closeness_up(Now_Point, 10, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				setcolor(32, 7);
				gotoxyP(5, 34, "�ʹ� �ٻڼż� ���� �����ٵ� �𸣰� ��Ŵ�. ");
				setcolor(32, 31);
				Sleep(Story*0.6);
				AQC();
				break;
			}
		}
		break;
	case 3: //����� ������ ���丮 ���̽�
		if (C3_event < 1)
		{
			setcolor(32, 31);
			gotoxyP(5, 34, "����� ����� �����Բ��� ������ ������ �����ϰ� ��ʴϴ� ! ");
			PlaySound(TEXT("HeoG.wav"), 0, SND_FILENAME | SND_ASYNC);
			C3_event++;
			Sleep(Story);
			Assistant_Text_clear();
			w = 1;
			while (w) { //������ ���� while��
				gotoxyP(5, 34, "����� ������ : ���� ! �ֿ� ���� ��� ���ٰ� �׸�.. ������ �η��߷ȱ�	");
				Sleep(Story / 3);
				gotoxyP(5, 36, "1. ���� ������ ���͵帰��.");
				gotoxyP(5, 37, "2. ���� ������ Ǯ��� ");
				gotoxyP(5, 38, "3. �׳� ��ô �ϰ� ����ģ��.");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 3);
				Story = 0;
			}  
			Story = 2100;
			if (n == 1)
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				sprintf(chTemp, "%s : ������..���� ���͵帱��� ? ", player[turnplayer-1].name);
				AQC();
				gotoxyP(5, 34, chTemp);
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "����� ������ : ����, �̹� �� ���ƴܴ�.");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "����� ������ : ������ŭ�� ���� ! ");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 50, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 2) //���� ���� Ǯ��
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				rn = rand() % 3;
				if (rn == 0)
				{
					gotoxyP(5, 34, "�� ���� �ٻڴܴ� ! �׷��� ������ ���ٰ� ~");
					Sleep(Story);
					break;
				}
				else if (rn == 1) // ���� ���� ��Ʈ
				{
					gotoxyP(5, 34, "����,, ������ ���� ������");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "�׷� ! ������ ������");
					Sleep(Story * 0.3);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "���� ������ ����?");
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. �Լ�");
						gotoxyP(5, 37, "2. ���̼�");
						gotoxyP(5, 38, "3. �̽�����");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "�� ����Ѱ�?");
						Sleep(Story / 2);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "�ƴϾ� !! �װ� �ƴϾ� !");
						Sleep(Story / 2);
						break;
					}
				}
				else if (rn == 2)
				{
					gotoxyP(5, 34, "����,, ������ ���� ������");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "�׷� ! ������ ������");
					Sleep(Story * 0.6);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "���󿡼� ���� ���ִ� ����?"); //���� ~
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. �߶���");
						gotoxyP(5, 37, "2. ����");
						gotoxyP(5, 38, "3. ��⵵ �Ȼ�� �ܿ��� �͵� �缼�濭�� 94");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "�� ����Ѱ�?");
						Sleep(Story / 2);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "���� ! Ʋ�ȴܴ� !");
						Sleep(Story / 2);
						break;
					}
				}
			}
			else if (n == 3)
			{
				AQC();
				rn = rand() % 2;
				Assistant_Text_clear();
				if (rn == 1)
				{
					gotoxyP(5, 34, "�ʹ� ������ �������� �ƹ��� �𸣴� �� �ϴ�.");
					Sleep(Story);
					break;
				}
				else
				{
					sprintf(chTemp, "����� ������ : %s ! ��� ! �� ���� ..", player[turnplayer-1].name);
					gotoxyP(5, 34, chTemp);
					Sleep(Story);
					break;
				}
				gotoxyP(5, 34, "�ʹ� ������ �������� �ƹ��� �𸣴� �� �ϴ�.");
				Sleep(Story);
				break;
			}
		}
		else
		{
			gotoxyP(5, 34, "����� �����Բ��� �ֿ� ���� ��� ã�� ��ʴϴ� . "); // �����Ե��� Ư¡�� �ݿ��� ���� ���丮
			PlaySound(TEXT("HeoG.wav"), 0, SND_FILENAME | SND_ASYNC);
			w = 1;
			Sleep(Story);
			while (w) {
				AQC();
				gotoxyP(5, 34, "������ �Ͻðڽ��ϱ�?");
				Sleep(Story / 3);
				gotoxyP(5, 36, "1. ���� ������ Ǯ���.");
				gotoxyP(5, 37, "2. �׳� ������ �������´�.");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 3);
				Story = 0;
			}
			if (n == 1) // 1.������� Ǯ���.�� ������ �� ���
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				rn = rand() % 3; // ���� ���� 3���� ����
				if (rn == 0)
				{
					gotoxyP(5, 34, "�� ���� �ٻڴܴ� ! �׷��� ������ ���ٰ� ~");
					Sleep(Story);
					break;
				}
				else if (rn == 1) // ���� ���� ��Ʈ
				{
					gotoxyP(5, 34, "����,, ������ ���� ������");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "�׷� ! ������ ������");
					Sleep(Story /2);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "���� ������ ����?");
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. �Լ�");
						gotoxyP(5, 37, "2. ���̼�");
						gotoxyP(5, 38, "3. �̽�����");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "�� ����Ѱ�?");
						Sleep(Story/2);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "���� ! Ʋ�ȴܴ� !");
						Sleep(Story);
						break;
					}
				}
				else if (rn == 2)
				{
					gotoxyP(5, 34, "����,, ������ ���� ������");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "�׷� ! ������ ������	");
					Sleep(Story * 0.6);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "���󿡼� ���� ���ִ� ����?");
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. �߶���");
						gotoxyP(5, 37, "2. ����");
						gotoxyP(5, 38, "3. ��⵵ �Ȼ�� �ܿ��� �͵� �缼�濭�� 94");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "�� ����Ѱ�?");
						Sleep(Story);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "���� ! Ʋ�ȴܴ� !");
						Sleep(Story);
						break;
					}
				}
			}
			else if (n == 2) //2. �׳� ������ �������´�. �� ������ �� ���
			{
				AQC();
				rn = rand() % 2;
				if (rn == 1)
				{
					gotoxyP(5, 34, "�ʹ� ������ �������� �ƹ��� �𸣴� �� �ϴ�.");
					Sleep(Story);
					break;
				}
				else
				{
					sprintf(chTemp, "����� ������ : %s ! ��� ! �� ���� ..", player[turnplayer].name);
					gotoxyP(5, 34, chTemp);
					Sleep(Story);
					AQC();
					closeness_down(Now_Point, 10, turnplayer);
					break;
				}
				gotoxyP(5, 34, "�ʹ� ������ �������� �ƹ��� �𸣴� �� �ϴ�.");
			}
			break;
		}
	case 4: //���� �� ���丮 ���̽�
		gotoxyP(5, 34, "����� ���� ! ����� ���� ! ");
		PlaySound(TEXT("JeJe.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		gotoxyP(5, 34, "������ �ָ��ε��� �б��� �����̳� ���ϴ� . ");
		Sleep(Story);
		setcolor(32, 31);
		w = 1;
		while (w)
		{
			Assistant_Text_clear();
			system_("������ �Ͻðڽ��ϱ�?");
			Sleep(Story / 3);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ���� ���̽�ũ���� ��޶�� ���ẻ��.");
			gotoxyP(5, 37, "2. ��ȸ ������ Ǯ���");
			gotoxyP(5, 38, "3. �������� ������� ������ ���� �������� ����.");
			gotoxy(5, 39);
			scanf("%d", &n);
			w = Is_it_right_num(n, 3);
		}
		if (n == 1) //������ 1���� ����������
		{
			Assistant_Text_clear();
			setcolor(32, 31);
			gotoxyP(5, 34, "���� ������ : ���� ��?");
			Sleep(Story / 2);
			AQC();
			sprintf(chTemp, "%s : �� ���̽�ũ�� �ϳ� .. ���ּ��� ",player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			Assistant_Text_clear();
			rn = rand() % 3;
			if (rn == 0)
			{
				gotoxyP(5, 34, "�߾� ~");
				Sleep(Story / 3);
				gotoxyP(5, 35, "���� ���̽�ũ���� ���̽�ũ���̾� ~");
				Assistant_Text_clear();
				gotoxyP(5, 34, "�̻��� �Ҹ� ���� �� ~");
				Sleep(Story);
				system_("�ٵ� ���� ������ ����� ���� ���δ�. ");
				Sleep(Story);
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
			else if (rn == 1)
			{
				gotoxyP(5, 34, "�߾� ~");
				Sleep(Story / 3);
				gotoxyP(5, 35, "���� ���̽�ũ���� ���̽�ũ���̾� ~");
				PlaySound(TEXT("JeJe2.wav"), 0, SND_FILENAME | SND_ASYNC);
				Assistant_Text_clear();
				gotoxyP(5, 34, "�ʰ� �� ������� ~ ! ");
				Sleep(Story);
				system_("�Ȼ����� ������ �� �ϴ� ");
				Sleep(Story);

				closeness_down(Now_Point, 10, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				gotoxyP(5, 34, "�߾� ~");
				Sleep(Story / 3);
				gotoxyP(5, 35, "�� ���� �ٻ� ~");
				Sleep(Story / 2);
				Assistant_Text_clear();
				gotoxyP(5, 34, "�׷��� �ʰ� ��Ծ�  ~ ");
				Sleep(Story);
				system_("�׷��� ���ְ� ���� ��ġ�̴�. ");	
				Sleep(Story);
				closeness_up(Now_Point, 10, turnplayer);
				Sleep(Story);
				break;
			}
		}
		else if (n == 2) //������ 2���� ����������
		{
			Assistant_Text_clear();
			setcolor(32, 31);
			rn = rand() % 3;
			if (rn == 0)
			{
				gotoxyP(5, 34, "���� ������ : ��ҿ� ��ȸ�ð��� �Ḹ �ڴ� ����.. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "��ȸ�� �躸�� �ȵ� ~");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "������ ������.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "������ �ڱ�Ұ��� �ϸ�? (�Է� �� ����) ");
				gotoxy(5, 36);
				scanf("%s", &chTemp);
				if (!strcmp(chTemp, "����"))
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "�� ~  �� �� �Ѵ� ? ");
					Sleep(Story);
					AQC();
					closeness_up(Now_Point, 50, turnplayer);
					Sleep(Story);
					break;
				}
				else
				{
					AQC();
					gotoxyP(5, 34, "�ƴϾ� ~ Ʋ�Ⱦ� ~");
					Sleep(Story/3);
					gotoxyP(5, 35, "������ �� �� �̾� ~ ");
					Sleep(Story);
					AQC();
					break;
				}
			}
			else if (rn == 1)
			{
				gotoxyP(5, 34, "���� ������ : ��ҿ� ��ȸ�ð��� �Ḹ �ڴ� ����.. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "��ȸ�� �躸�� �ȵ� ~");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "����� �� ���ž� ~ ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "�Ҷ� ���� �ε�����? (�Է� �� ����)");
				gotoxy(5, 36);
				scanf("%s", &chTemp);
				if (!strcmp(chTemp, "�Ұ���"))
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "�� ~  �� �� �Ѵ� ? ");
					Sleep(Story);
					AQC();
					closeness_up(Now_Point, 50, turnplayer);
					break;
				}
				else
				{
					AQC();
					gotoxyP(5, 34, "�ƴϾ� ~ Ʋ�Ⱦ� ~ ");
					Sleep(Story/3);
					gotoxyP(5, 35, "������ �� �� �� �̾� ~");
					Sleep(Story);
					AQC();
					break;
				}
			}
			else if (rn == 2)
			{
				gotoxyP(5, 34, "���� ������ : ��ҿ� ��ȸ�ð��� �Ḹ �ڴ� ����.. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "��ȸ�� �躸�� �ȵ� ~");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "����� �� ���ž� ~ ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���� �ڸ���? (�Է� �� ����) ");
				gotoxy(5, 36);
				scanf("%s", &chTemp);
				if (!strcmp(chTemp, "����"))
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "�� ~  �� �� �Ѵ� ? ");
					Sleep(Story);
					AQC();
					closeness_up(Now_Point, 50, turnplayer);
					break;
				}
				else
				{
					AQC();
					gotoxyP(5, 34, "�ƴϾ� ~ Ʋ�Ⱦ� ~ ");
					Sleep(Story/3);
					gotoxyP(5, 35, "������ ���� �̾� ~");
					Sleep(Story);
					break;
				}
			}
		}
		else if (n == 3) // 3��
		{
		Assistant_Text_clear();
			rn = rand() % 2;
			if (rn == 0)
			{
				system_("���� �����Բ����� ���� ���� ������ �ϰ� ��ż�");
				Sleep(Story / 2);
				setcolor(32, 7);
				gotoxyP(5, 35, "���� �����ٵ� �𸣽ô� �� ���Ҵ�.");
				Sleep(Story);
				break;
			}
			else
			{
				system_("���� �����Բ��� ���� ������ �� ���� �� �ϴ�. ");
				Sleep(Story);
				Assistant_Text_clear();
				closeness_down(Now_Point, 10, turnplayer);
			}
		}
		break;
case 5: //�ڰ�� ������ ���丮 ���̽�
	PlaySound(TEXT("ParkG.wav"), 0, SND_FILENAME | SND_ASYNC);
	gotoxyP(5, 34, "����� �ڰ�� �����Բ��� �ѱ��� �̱� ���븦 �������̽ʴϴ� ! ");
	Sleep(Story);
	AQC();
	gotoxyP(5, 34, "������ ��ǥ�� ���ΰ��� ���� �� ���ΰ���? ���� ��������ֳ���??");
	Sleep(Story / 2);
	w = 1;
	while (w)
	{
		setcolor(32, 31);
		gotoxyP(5, 36, "1. ���� �̱⸷�븦 �̴´�.");
		gotoxyP(5, 37, "2. ��ٸ���");
		gotoxy(5, 38);
		scanf("%d", &n);
		w = Is_it_right_num(n, 2);
	}
	setcolor(32, 31);
	Assistant_Text_clear();
	w = 1;
	if (n == 1)
	{
		gotoxyP(5, 34, "��~ ��������!");
		Sleep(Story / 3);
		AQC();
		rn = rand() % 10;
		rn = rn + 2;
		int cnt = 0;
		while (cnt < rn)
		{
			gotoxy(5, 34);
			printf("%d   (66%%�� Ȯ���� ��ǥ����)", rand() % 37);
			Sleep(250);
			cnt++;
		}
		rn = 0;
		Assistant_Text_clear();
		rn = rand() % 3;
		if (rn == 0 || rn == 1)         //66%�� Ȯ���� ��ǥ��÷!
		{
			gotoxy(5, 34);
			sprintf(chTemp, "%s ���ͼ� ��ǥ���ּ���", player[turnplayer].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			AQC();
			gotoxyS(5, 34, "��ǥ���Դϴ�."); Sleep(500);
			gotoxyS(5, 34, "��ǥ���Դϴ�.."); Sleep(500);
			gotoxyS(5, 34, "��ǥ���Դϴ�..."); Sleep(500);
			gotoxyS(5, 34, "��ǥ���Դϴ�...."); Sleep(500);
			gotoxyS(5, 34, "��ǥ�� ������ ���ƴ�.");
			Sleep(Story / 2);
			AQC();
			gotoxyP(5, 34, "�ڰ�� �����Բ��� �߰� ������ �ϽŴ�.");
			Sleep(Story / 3);
			AQC();
			gotoxyP(5, 34, "�ڰ�� ������ : �츮���� 5�� �������� �ƴѰ��� �����ΰ���?");
			Sleep(Story);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ��õ��   2. ������");
			gotoxyP(5, 37, "3. �����ε���   4. ������   5.������");

			w = 1;
			while (w)
			{
				gotoxy(5, 39);
				printf("            ");
				scanf("%d", &n);
				w = Is_it_right_num(n, 5);
			}

			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 3)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "�ڰ�� ������ : �׿�~ �� �˰� ��ó׿�");
				Sleep(Story / 3);
				closeness_up(Now_Point, 50, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 1 || n == 2 || n == 4 || n == 5)
			{
				setcolor(32, 31);
				gotoxyS(5, 34, "�ڰ�� ������ : ...");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "�ڰ�� ������ : ....");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "�ڰ�� ������ : ...");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "�ڰ�� ������ : ....");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "����� �����ô�.");
				Sleep(Story / 3);
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}

		}
		else if (rn == 2)
		{
			rn = (rand() % 35) + 1;
			gotoxy(5, 34);
			sprintf(chTemp, "%d�� �л� ���ͼ� ��ǥ���ּ���.", rn);
			gotoxyP(5, 34, chTemp);
			Sleep(Story / 2);
			AQC();
			gotoxyS(5, 34, "����� ��ǥ��ȸ�� ���󰬽��ϴ�");
			Sleep(Story / 2);
			AQC();
			system_("��ǥ�� �����ð���....");
			Sleep(Story / 2);
			AQC();
			break;
		}
	}
	if (n == 2)
	{
		gotoxyP(5, 34, "�ڰ�� ������ : ���, ������ ��ǥ�� �����ϴ�!");
		Sleep(Story / 2);
		AQC();
		system_("�ڰ�� �����Բ��� ������ �������̽ʴϴ�.");
		Sleep(Story);
		AQC();
		gotoxyS(5, 34, "zzz...");
		Sleep(1000);
		gotoxyS(5, 34, "zzz....");
		Sleep(1000);
		gotoxyS(5, 34, "zzz.....");
		Sleep(1000);
		AQC();
		setcolor(32, 31);
		Assistant_Text_clear();
		gotoxyP(5, 34, "���������ϴ�.");
		Sleep(Story / 3);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ��� �ܴ�");
			gotoxyP(5, 37, "2. �ῡ�� ���� ������ ��´�");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1)
		{
			setcolor(32, 31);
			Assistant_Text_clear();
			system_("��� ���� ��ϴ�...");
			Sleep(Story);
			player_Talk(turnplayer, "���~!");
			Sleep(Story / 3);
			player_Talk(turnplayer, "����....");
			Sleep(Story / 3);
			player_Talk(turnplayer, "���� �����?!!!");
			Sleep(Story);
			system_("����.. ����ȣ�� ���� �����Դϴ�");
			Sleep(Story / 2);
			system_("����� �����ϴ� û���� ������� ��� ȭ���� ���ϼ���.");
			Sleep(Story);
			player_Talk(turnplayer, "???");
			Sleep(Story / 2);
			system_("�����մϴ�");
			Sleep(Story / 2);
			avoidArrow(); //ȭ�� �̴ϰ����� �ҷ��ɴϴ�.
			player_Talk(turnplayer, "ġ���?!");
			Sleep(Story);
			gotoxy(5, 36);
			gotoxyP(5, 36, "�ڰ�� ������ : �Ჿ�븦 �ϴ±���??");
			Sleep(Story);
			AQC();
			system_("�Ჿ�븦 �Ͽ� ģ�е��� �����մϴ�");
			Sleep(Story / 2);
			closeness_down(Now_Point, 10, turnplayer);
			Sleep(Story);
			Assistant_Text_clear();
			break;
		}
		else if (n == 2)
		{
			system_("����� �ῡ�� �����ϴ�.");
			Sleep(Story / 2);
			system_("������, ����� ���ҽ��ϴ�");
			Sleep(Story / 2);
			system_("�����Ͻó���?");
			Sleep(Story);
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. �� �����մϴ�");
				gotoxyP(5, 37, "2. �ƴϿ�. ���� ���� �ʾҽ��ϴ�");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 1)
			{
				player_Talk(turnplayer, "��, ���� ���ҽ��ϴ�");
				Sleep(Story);
				AQC();
				system_("�������Ƿ�, ģ�е��� �����մϴ�");
				Sleep(Story / 2);
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 2)
			{
				player_Talk(turnplayer, "���� ���� �ʾҽ��ϴ�!");
				Sleep(Story);
				AQC();
				system_("�������� �����Ƿ� ģ�е��� �����մϴ�");
				Sleep(Story);
				closeness_down(Now_Point, 40, turnplayer);
				Sleep(Story);
				break;
			}
		}
	}
	break;
	case 6: //���� ������ ���丮 ���̽�
		gotoxyP(5, 34, "����� ���� �����Բ��� ö���� �������̽ʴϴ� ! ");
		Sleep(Story*0.3);
		gotoxyP(5, 35, "���� ������ �ٰ����� ȭ���� �� �մϴ� . ");
		Sleep(Story);
		setcolor(32, 31);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			AQC();
			setcolor(32, 7);
			gotoxyP(5, 34, "������ �Ͻðڽ��ϱ�?");
			Sleep(Story / 3);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ������ �ٰ�����. ");
			gotoxyP(5, 37, "2. ��ġ�� ������. ");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		if (n == 1)
		{
			setcolor(32, 31);
			Assistant_Text_clear();
			gotoxyP(5, 34, "(�ѽ� ! �ؼ� ! ǢǢ !!)");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "���� ������ : ...");
			Sleep(Story*0.6);
			AQC();
			gotoxyP(5, 34, "���� ������: ! ");
			Sleep(Story *0.6);
			AQC();
			if (C6_event < 1)
			{
				gotoxyP(5, 34, "���� ������ : �� �̾��ϴ�. ���� �ʹ� �����߱��� ");
				Sleep(Story);
				C6_event++;
			}
			else
			{
				gotoxyP(5, 34, "���� ������ : �� �� �ɷ����ȳ� ! ���S");
				Sleep(Story);
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
			}
			system_("���̻� �ӹ��� ���ذ� �ɰ� ���� ���Դ�. ");
			Sleep(Story);
			break;
		}
		else if (n == 2)
		{
			rn = rand() % 2;
			if (rn == 0)
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				gotoxyP(5, 34, "ö�ǿ� �ʹ� �����ϼż� ������ ���ϴ�. ");
				Sleep(Story);
			}
			else
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				gotoxyP(5, 34, "���⸦ ���� �Ĵٺ��� �� �ϱ� ������ ũ�� �Ű澲������ �ʴ� �� ����. ");
				Sleep(Story + 1000);
			}
		}
		break;
	case 7: //������ ������ ���丮 ���̽�
		gotoxyP(5, 34, "����� ������ �����Բ��� ������ �ｺ���̽ʴϴ� . ");
		PlaySound(TEXT("BaeJ.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 7);
		AQC();
		gotoxyP(5, 34, "������ �����԰� ������ �Ͻðڽ��ϱ�? ");
		Sleep(Story / 3);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ������ �����԰� �ｺ�� �Ѵ�");
			gotoxyP(5, 37, "2. ������ �����԰� �󱸸� ���� �Ѵ�");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();

		if (n == 1)
		{
			system_("������ �����԰� �ｺ�� �ؼ� ģ�е��� �ö����ϴ�");
			Sleep(Story);
			closeness_up(Now_Point, 15, turnplayer);
			Sleep(Story);
			break;
		}

		if (n == 2)
		{
			gotoxyP(5, 34, "������ ������ : ���� �ʶ� �󱸸� ����");
			Sleep(Story);
			AQC();
			system_("����� .. ");
			Sleep(Story + 2000);
			AQC();
			system_("������ �����԰� �󱸸� �ʹ� ������ �� ģ�е��� �ö����ϴ�.");
			Sleep(Story);
			AQC();
			closeness_up(Now_Point, 40, turnplayer);
			Sleep(Story);
			break;
		}

		break;
	case 8: //������ ������ ���丮 ���̽�
		gotoxyP(5, 34, "����� ������ �������� ������ ����, �к��� �������Դϴ� ! ");
		PlaySound(TEXT("JeonH.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		system_("���� ���� �ȵ� ������ .. ! ");
		Sleep(Story);
		w = 1;
		while (w)
		{
			system_("��� �Ͻðڽ��ϱ� ? ");
			gotoxyP(5, 36, "1. �밨�ϰ� ������ ");
			gotoxyP(5, 37, "2. �ƴϴ�, �׳� ���ư��� "); // ���� �Է� �κп��� ���� ��.
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		if (n == 1) // ������ 1 ����
		{
			Assistant_Text_clear();
			//chTemp[200] =  '\0' ;
			sprintf(chTemp, "%s : (�ȶ�)", player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			AQC();
			setcolor(32, 31);
			gotoxyP(5, 34, "������ ������ : ����, �� ���� ");
			Sleep(Story);
			Assistant_Text_clear();
			w = 1;
			while (w)
			{
				gotoxyP(5, 34, "������ ������ : ���� �� ? ");
				gotoxyP(5, 36, "1. �ƹ��͵� �ƴϿ���. ");
				gotoxyP(5, 37, "2. ������ �ƹ��͵� �ƴϿ���. ");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			if (n == 1 || n == 2)
			{
				rn = rand() % 2;
				if (rn == 0)
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "������ ������ : ... ?");
					Sleep(Story);
					gotoxyP(21, 34, " �� �Ϸ� �ͺ�");
					Sleep(Story);
					gotoxyP(21, 34, "���� ������ ~ ?");
					Sleep(Story);
					AQC();
					gotoxyP(5,34,"������ �ƹ��͵� �ƴϿ��� !!");
					Sleep(Story);
					Assistant_Text_clear();
					Sleep(1000);
					system_("������ ���������� ������ ���������� ������ �����Բ����� ���� �ǽ��ϴ� �� �ϴ�. ");
					Sleep(Story);
					AQC();
					break;
				}
				else if (rn == 1)
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "������ ������ : ... ?");
					Sleep(Story);
					gotoxyP(21, 34, "�� �Ϸ� �ͺ�");
					Sleep(Story);
					gotoxyP(21, 34, "���� �� ���ϴ� ���̾�?");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "�ƴ�, �߸� �Ծ�� ... ! ");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "������ ������ : �� ���ڽ�, �й� �̸� �θ��� ��. ");
					Sleep(Story);
					AQC();
					system_("���� ������ �� ��ȣ�� �޾� ���̴�. ");
					Sleep(Story);
					break;
				}			
			}
		}
		else if (n == 2) //������ 2 ����
		{
			rn = rand() % 2;
			if (rn == 0)
			{
				Assistant_Text_clear();
				gotoxyP(5, 34, "������ ������ : �ۿ� ������ ! �Ϸ� ���� !");
				Sleep(Story);
				AQC();
				system_("������ �������� ���� �����ϰ� ������ ������,");
				Sleep(Story);
				AQC();
				system_("���� ������ ������ ���Ҵ�. ");
				Sleep(Story);
				break;
			}
			else
			{
				Assistant_Text_clear();
				system_("������ �������Դ� ! ");
				Sleep(Story);
				break;
			}
		}
		break;
	case 9: //������ ������ ���丮 ���̽�
		setcolor(32, 7);
		gotoxyP(5, 34, "����� ������ �������� ���� ���߸� ���� �����Դϴ� ! ");
		PlaySound(TEXT("YangH.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		rn = rand() % 3;
		if (rn == 1)
			system_("���� �� ���� ������ ������ �� �մϴ�.");
		else if (rn == 2) {
			system_("���� ������ �ϰ� ��ʴϴ�."); Sleep(Story);
			system_("�Ƿ��� ������ ���ر��̽ʴϴ�. ");
		}
		else
			system_("���𰡿� �����Ͻ� ����� ���Դϴ�. ");
		Sleep(Story);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			system_("������ �Ͻðڽ��ϱ�? ");
			gotoxyP(5, 36, "1. ��ȭ�� �ɾ��. ");
			gotoxyP(5, 37, "2. �׳� ����ģ��. ");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1) //������ 1�� ���ý�
		{
			gotoxyP(5, 34, "��, �������� ���� �λ��ϰڽ��ϴ�! ");
			Sleep(Story);
			gotoxyP(5, 35, "��, �������� �� ������ �λ��ϰڽ��ϴ�! ");
			Sleep(Story);
			Assistant_Text_clear();
			sprintf(chTemp, "%s : �ȳ��ϼ��� ������ ! ",player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "������ ������ : �� ���� ���̴�? ");
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. �� ��� �غ��� �;�� ! ");
				gotoxyP(5, 37, "2. ���� ��� �Ͻ� �ð� �ƴϿ���? ");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1) // ������ 1
			{
				sprintf(chTemp, "%s : ������ �� ��� �ѹ� �غ��� �;�� ! ",player[turnplayer-1].name);
				gotoxyP(5, 34, chTemp);
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ������ : ��� �ϰ� �ʹٰ�? ");
				Sleep(Story);
				gotoxyP(21, 35, "����� ������ ������ ������ ");
				Sleep(Story);
				rn = rand() % 2;
				if (rn == 0)
					gotoxyP(21, 36, "���� �Ǻ� ���� ! �Ǻ� ������ �߿��ϴܴ�. ");
				else
				{
					gotoxyP(21, 36, "Ƽ�� ������ , Ƽ��. ");
					Sleep(Story);
					Assistant_Text_clear();
					gotoxyP(5, 34, "������ ������ : ���� ������ ���⸦ ���� �ϴ°� ���� �߿��ϴܴ�.");
				}
				Sleep(Story + 1000);
				Assistant_Text_clear();
				gotoxyP(5, 34, "������ ������ : �� ��̰����̶�� ǰ ! ���� �޶���� !");
				Sleep(2500);
				gotoxyP(21, 35, "�׷��� ���� ��츦 �� �� ���� ");
				Sleep(2500);
				gotoxyP(21, 36, "�˾���? ���� ����� ���� ���� ���̶���.");
				Sleep(5000);
				Assistant_Text_clear();
				system_(" ( �� �ڷ� ���� ������ �����̴ּ� )");
				Sleep(4000);
				AQC();
				Sleep(2000);
				setcolor(32, 31);
				player_Talk(turnplayer, "���� ���� ��������... !");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ������ : ����!! �׷�^^ ");
				Sleep(Story);
				closeness_up(Now_Point, 40, turnplayer);
				Sleep(Story);
				break;
			}
			else // ������ 2
			{
				gotoxyP(5, 34, "������ ������ : ���� ! �� ���� �� ��");
				Sleep(Story);
				AQC();
				system_("�����Բ����� ���ϰ� ���а� ���̴�..");
				Sleep(Story);
				AQC();
				Sleep(Story / 3);
				system_("�����...");
				Sleep(Story);
				AQC();
				setcolor(7, 31);
				gotoxyP(5, 34, "�� .....");
				Sleep(1000);
				gotoxyP(14, 34, "��....  10�� ���Ҵ�, ");
				gotoxyP(5, 35, "�� �ڶ�");
				Sleep(Story * 2);
				setcolor(32, 31);
				Assistant_Text_clear();
				player_Talk(turnplayer, "���� ���� ���� �ھ߰ڴ�. ");
				Sleep(Story);
				AQC();
				Sleep(Story / 2);
				system_("���� ��ҽ��ϴ�. ");
				Sleep(Story);
				break;
			}
		}
		else if (n == 2) // ������ 2�� ���ý�
		{
			rn = rand() % 3;
			if (rn == 0)
			{
				system_("������ �������Դ�. ");
				Sleep(Story);
				break;
			}
			else if (rn == 1)
			{
				system_("����� �������Դ�. ");
				Sleep(Story);
				break;
			}
			else
			{
				system_("���ϰ� ���ĳ��Դ�..... ");
				Sleep(Story);
				break;
			}
		}
		break;
	case 10: //����Ʈ�� ���丮 ���̽�
		gotoxyP(5, 34, "����� ����Ʈ�� ! ");
		Sleep(Story);
		AQC();
		system_("���۹��� Ű�� �� �ֽ��ϴ�.");
		Sleep(Story);
		AQC();
		system_("���۹��� Ű��ðڽ��ϱ�?");
		w = 1;
		while (w) 
		{
			gotoxyP(5, 36, "1. ��");
			gotoxyP(5, 37, "2. �ƴϿ�");
			gotoxy(5, 39);
			scanf("%d", &n);
			w = Is_it_right_num(n,2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			rn = rand() % 6 + 1; //���۹��� �������� ���ɴϴ�.
			system_("���۹��� Ű��� ���Դϴ�.......");
			Sleep(Story);
			AQC();
			if (rn == 1)
			{
				system_("�丶�䰡 �ڶ����ϴ�");
				Sleep(Story);
				AQC();
				system_("���¿� �����Բ� Ī���޽��ϴ�.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���¿� ������ : �丶�䰡 �� �ڶ�����");
				Sleep(Story);
				AQC();
				closeness_up(13, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 2)
			{
				system_("����� �ڶ����ϴ�");
				Sleep(Story / 2);
				AQC();
				system_("���¿� �����Բ� Ī���޽��ϴ�.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���¿� ������ : ����� �� �ڶ�����");
				Sleep(Story / 2);
				AQC();
				closeness_up(13, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 3)
			{
				system_("������ �ڶ����ϴ�");
				Sleep(Story / 2);
				AQC();
				system_("���¿� �����Բ� Ī���޽��ϴ�.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���¿� ������ : ������ �� �ڶ�����");
				Sleep(Story);
				AQC();
				closeness_up(13, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 4)
			{
				system_("���ڰ� �ڶ����ϴ�");
				Sleep(Story / 2);
				AQC();
				system_("���¿� �����Բ� Ī���޽��ϴ�.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���¿� ������ : ���ڰ� �� �ڶ�����");
				Sleep(Story);
				AQC();
				closeness_up(13, 10, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 5)
			{
				system_("�ñ�ġ�� �ڶ����ϴ�");
				Sleep(Story / 2);
				AQC();
				system_("���¿� �����Բ� Ī���޽��ϴ�.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���¿� ������ : �ñ�ġ�� �� �ڶ�����");
				Sleep(Story);
				AQC();
				closeness_up(13, 20, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 6)
			{
				system_("����� �ڶ����ϴ�");
				Sleep(Story / 2);
				AQC();
				system_("���¿� �����Բ� Ī���޽��ϴ�.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "���¿� ������ : ����� �� �ڶ����� !!");
				Sleep(Story);
				AQC();
				closeness_up(13, 80, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}

		}
		if (n == 2)
		{
			system_("����Ʈ���� �׳� ����Ĩ�ϴ�");
			Sleep(Story);
			AQC();
			break;
		}
		break;
	case 11: //������ ���丮 ���̽�
		gotoxyP(5, 34, "����� ������ �������� ��ġ�� �屸ġ�� ��Ȱ�Ͻô� �����Դϴ� ! ");
		PlaySound(TEXT("LeeT.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 31);
		Assistant_Text_clear();
		gotoxyP(5, 34, "������ �����Բ��� ���ָ� �Ͻ÷��� �մϴ�");
		Sleep(Story);
		AQC();
		system_("�뷡�� ����߸� �մϴ� !");
		Sleep(Story / 2);
		n = print_Song(); //�뷡 ���߱� �̴� ���� �ҷ�����
		Board_Middle_clear();
		Assistant_Text_clear();
		if (n == 0)
		{
			gotoxyP(5, 34, "������ ������ : �����̴�");
			PlaySound(TEXT("LeeT.wav"), 0, SND_FILENAME | SND_ASYNC);
			Sleep(Story);
			AQC();
			closeness_down(Now_Point, 10, turnplayer);
			Sleep(Story);
			break;
		}
		else
		{
			gotoxyP(5, 34, "������ ������ : �¾Ҵܴ� ! ");
			Sleep(Story);
			AQC();
			rn = rand() % 4 + 1;
			closeness_up(Now_Point, rn*10, turnplayer);
			Sleep(Story);
			break;
		}
		////�뷡���߱�/////////
		break;
	case 12: //������ ������ ���丮 ���̽�
		gotoxyP(5, 34, "����� ������ �������� ���� �����Դϴ�. ");
		PlaySound(TEXT("ChoeH.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 31);
		AQC();
		setcolor(32, 7);
		if(C12_event++ <1)
			gotoxyP(5, 34, "��� ���� �ϳ� ��������!  �Ҹ��� �ϳ� Ů�ϴ�");
		else
			gotoxyP(5, 34, "�� ���� �ϳ� �������� ! �Ҹ��� �Ʊ�� �� Ů�ϴ�");
		Sleep(Story);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. �����Բ� �޷�������.");
			gotoxyP(5, 37, "2. ȭ�� ���̷� ���� ������ ����.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1)
		{
			system_("������, �������Ű���????");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "������ ������ : �����ϴ� �Ҹ��� ����, �ƹ��ϵ� ������~");
			Sleep(Story);
			AQC();
			system_("�׷���.");
			Sleep(Story / 3);
			system_("�ƹ��ϵ� ������.");
			Sleep(Story);
			break;
		}
		if (n == 2)
		{
			system_("���̷��� ��Ƚ��ϴ�.");
			Sleep(Story);
			system_("�ڵ���ġ�� ����, �α� �ҹ漭���� �ڵ��Ű������� �Ǿ����ϴ�.");
			Sleep(Story + 1500);
			system_("�Ҹ��� �Ǿ��� ���, ��̰����� �ƹ��ϵ� �Ͼ�� �ʾҽ��ϴ�.");
			Sleep(Story + 1500);
			system_("���� �Ű��˷� ����� ����ó���˴ϴ�");
			Sleep(Story);
			player_Talk(turnplayer, "�ƴ� ���� ���� �Ȥ�.....");
			Sleep(Story);
			system_("���������������. �����Դϴ�.����");
			Sleep(Story);
			Game_over = 1; // �� ������ �ǵ帮�� Game_Finished �Լ� ȣ�� ���θ� �������ݴϴ�.
			break;
		}
		break;
	case 13: //���¿� ������ ���丮 ���̽�
		setcolor(32, 31);
		gotoxyP(5, 34, "����� ���¿� �������� �̼����Դϴ�.");
		Sleep(Story);
		Assistant_Text_clear();
		if (C13_event++ == 0)
			system_("�� ������ �籸�� ġ�� �����̳����ϴ� . ");
		else
			system_("������ �籸�� ġ�� ��Ű� ���ϴ�. ");
		Sleep(Story);
		setcolor(32, 31);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			system_("������ �Ͻðڽ��ϱ�? ");
			Sleep(Story/3);
			gotoxyP(5, 36, "1. ���¿� ������ å���� ��������. ");
			gotoxyP(5, 37, "2. �׳� ������.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1) //������ 1
		{
			player_Talk(turnplayer, "�̼��� å���� �������߰ڴ�. ");
			Sleep(Story);
			Assistant_Text_clear();
			gotoxyP(5, 34, " ( ���� ���� ) ");
			Sleep(Story);
			AQC();
			rn = rand() % 3;
			if (rn == 0)
			{
				system_("�������� �̼� ��ǰ�� ���Դ�.");
				Sleep(Story);
				AQC();
				system_("�߻�ȭ�� �׸��� �� �� ����̴�.");
				Sleep(1000);
				AQC();
				gotoxyP(5, 35, "�׸��� ���� ���̵��� ������ ������ ���ϴ�. ");
				Sleep(1000);
				AQC();
				gotoxyP(5, 36, "������ ..... ���ϰ� �׸��ŵ� �ϴ� .");
				Sleep(Story+1000);
				Assistant_Text_clear();
			}
			else if (rn == 1)
			{
				system_("�������� �Ƴ��ô� �ƺ��� ���Դ�. ");
				Sleep(Story);
				AQC();
				system_("������ ��� ���δ�. ");
				Sleep(Story);
				AQC();
				system_("Ž���� ������ ... �׳� ���־� �ڴ�. ");
				Sleep(Story);
				Assistant_Text_clear();
				Sleep(500);
			}
			else
			{
				system_("�л� ���� ������ �ִ�. ");
				Sleep(Story);
				AQC();
				// ���� ���� ��� ǥ��
			}
			system_("������ ������ �����߰ڴ�.. ");
			Sleep(Story/3);
			break;
		}
		else // ������ 2
		{
			system_("������ �������Դ�.");
			Sleep(Story / 2);
			break;
		}
		break;
	case 14: //���翵 ������ ���丮 ���̽�
		system_(" ����� ���翵 �������� ��� ���Դϴ�. ");
		PlaySound(TEXT("KimJ.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		Assistant_Text_clear();
		system_(" ���� �̰��� ������ ������ ��������ϴ�. ");
		Sleep(Story);
		AQC();
		system_(" ���� �տ� ���翵 �������� �޸���� ���Դϴ�. ");
		Sleep(Story);
		AQC();
		w = 1;
		while (w)
		{
			system_(" ������ �Ͻðڽ��ϱ�? ");
			gotoxyP(5, 36, "1. ���� �ɾ��. ");
			gotoxyP(5, 37, "2. ���� �ɾ��. ");
			gotoxyP(5, 38, "3. ���� �ɾ��. ");
			scanf("%d", &n);
			w = Is_it_right_num(n, 3);
		}
		Assistant_Text_clear();
		if (C14_event++ == 0) {
			gotoxyP(5, 34, "���翵 ������ : �����ڽ�.... ���� �Ž�. ....... ");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "���翵 ������ : �� �׷� ~ ���� �� �̴�?");
		}
		else if (C14_event++ == 1) {
			gotoxyP(5, 34, "���翵 ������ : ���� �� �� ����°ž� ~?");
		}
		else if (C14_event++ >= 2) {
			gotoxyP(5, 34, "���翵 ������ : ���� ������ ~ ");
		}
		Sleep(Story);
		w = 1;
		while (w)
		{
			gotoxyP(5, 36, "1. ���� ���ϼ���?");
			gotoxyP(5, 37, "2. �� ���� ��ƿ� !");
			gotoxy(5, 38); scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			gotoxyP(5, 34, "���翵 ������ : �ʳ� ���� ���� ���� ����� �־��� ~");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "���翵 ������ : ���� ���Ϸ� �Ծ� ?");
			Sleep(Story);
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. ���� ���� ���ּ��� !");
				gotoxyP(5, 37, "2. ������ �ʹ� ���־�� !");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1)
			{
				player_Talk(turnplayer, "�� ���� ���� �ϳ� ���ּ��� !");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "���翵 ������ : ���� ���� ������ ���� ������ .... ~");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "���翵 ������ : �׷� �ð��� ���� ������ �� ~");
				Sleep(500);
				gotoxyP(21, 35, "�ǳ� ���δ� ���� �ϰ�");
				Sleep(500);
				gotoxyP(21, 36, "�ų� ���� �ȶ�����, ���� ~!!");
				Sleep(Story);
				Assistant_Text_clear();
				player_Talk(turnplayer, "�˾Ҿ��,, ���� ���� �Ϸ� ���Կ�. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "�׷� ~ ���� �����̾� ~");
				Sleep(Story);
				AQC();
				rn = rand() % 2 + 1;
				closeness_up(Now_Point, rn*10, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				gotoxyP(5, 34,"���翵 ������ : ���� ���� ������");
				Sleep(Story/3);
				gotoxyP(21, 35, "���� �˰� �־� ~");
				Sleep(Story / 2);
				Assistant_Text_clear();
				system_("����� ������ ���� ���̽Ŵ�. ");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 50, turnplayer);
				Sleep(Story);
				break;
			}
		}
		else if (n == 2)
		{
			gotoxyP(5, 34, "���翵 ������ : ��� �� ��� ~");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "���翵 ������ : �� ���� �ٺ� ~ ���� ���� �� ȥ�� ��� !");
			Sleep(Story);
			AQC();
			system_("�׷��� ����� ���� ���̽Ŵ�.");
			Sleep(Story);
			AQC();
			closeness_up(Now_Point, 50, turnplayer);
			Sleep(Story);
			break;
		}
		break;
	case 15: //������ ������ �׽�Ʈ ���̽�
		sprintf(English_T, "�ȳ� %s ~ !", player[turnplayer - 1].name);
		PlaySound(TEXT("JunY1.wav"), 0, SND_FILENAME | SND_ASYNC);
		gotoxyP(5, 34, English_T);
		Sleep(Story);
		system_("�����Բ��� ����� ���ƺ��̽Ŵ�.");
		Sleep(Story);
		AQC();
		w = 1;
		while (w)
		{
			Assistant_Text_clear();
			gotoxyP(5, 34, "������ ������ : ���� ���̴� ~ ?");
			Sleep(Story);
			gotoxyP(5, 36, "1. ���� �ܾ� å �Ҿ���Ⱦ�� !");
			gotoxyP(5, 37, "2. �׳� �ɽ��ؼ� �ͺþ�� !");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			gotoxyP(5, 34, "������ ������ : ����� ?! �װ� �� �Ҿ� ���� !");
			PlaySound(TEXT("JunY2.wav"), 0, SND_FILENAME | SND_ASYNC);
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "������ ������ : ���ú��� �ܾ� ���� ���� �ʴ� �������̾� !!");
			Sleep(Story);
			AQC();
			player_Talk(turnplayer, "���� ??? ���� �Ҹ����� ???");
			Sleep(Story);
			AQC();
			system_("�ƹ����� ������ ū���� ���Ű���.. ");
			Sleep(Story);
			break;
		}
		else
		{
			rn = rand() % 2;
			if(rn == 0)
			{
				gotoxyP(5, 34, "������ ������ : ���, ȣȣȣȣ");
				Sleep(Story);
				AQC();
				gotoxyP(21, 34, "���� �ϳ� �ٰ� ~ �̰� �԰� ���� ~");
				Sleep(Story);
				AQC();
				system_("������ �ϳ� �޾Ҵ� !");
				Sleep(Story);
				Board_Middle_clear();
				AQC();
				player_Talk(turnplayer, "�����մϴ� ~~!!");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 40, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				gotoxyP(5, 34, "������ ������ : ���, ȣȣȣȣ");
				Sleep(Story);
				gotoxyP(21, 34, "�׷��� ��Ʈ�� �ϳ��� �����ټ� �ְڴ�?");
				gotoxyP(21, 35, "�����ð��� ������ ���� �ؼ� ~");
				Sleep(Story);
				Assistant_Text_clear();
				system_("��Ʈ���� ������ȴ�.");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ������ : ������ ���� ~~~!!");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
		}
		break;
	case 16: // ����� ������ ���丮 ���̽�
		gotoxyP(5, 34, "����� ����� �������� �౸ �����Դϴ� !");
		PlaySound(TEXT("LeeJ2.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		gotoxyP(5, 34, "����� ������: �о���~ �̷��� �ϴ°ž�~, �����ϼ���?");
		Sleep(Story + 700);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. ��, �����߽��ϴ�.");
			gotoxyP(5, 37, "2. �������� ���߽��ϴ�.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1)
		{
			gotoxyP(5, 36, "����� ������ : �Ǹ��ϱ�~!");
			Sleep(Story / 2);
			AQC();
			system_("�Ǹ��ؼ� ģ�е��� ����մϴ�");
			Sleep(Story / 2);
			closeness_up(Now_Point, 15, turnplayer);
			Sleep(Story);
			break;
		}
		else if (n == 2)
		{
			gotoxyP(5, 34, "����� ������ : �̰͵� �������� ���ؼ� �ǰڳ���??");
			Sleep(Story);
			AQC();
			system_("�������� ���ؼ� ģ�е��� �϶��մϴ�");
			Sleep(Story);
			system_("������, ���� �� ���� �����Բ� ���� �н��� �ָ� ģ�е� �϶��� �����մϴ�");
			Sleep(Story);
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. �����մϴ�");
				gotoxyP(5, 37, "2. �������� �ʽ��ϴ�");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 1)
			{
				system_("�÷��̾��� �������ſ� ��ź�Ͽ� ģ�е��� ����մϴ�");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "����� ������ : ũ...");
				Sleep(Story / 2);
				AQC();
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (n == 2)
			{
				system_("�������� �����Ƿ� ģ�е��� �϶��մϴ�");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
		}
		break;
	case 17: // �ϼ��� ������ �׽�Ʈ ���̽�
		gotoxyP(5, 34, "����� �ϼ��� �����Բ��� ���伥�� ����ġ�� ��ʴϴ�.");
		Sleep(Story);
		AQC();
		gotoxyP(5, 34, "�ϼ��� ������ : �ϵ��� ���̴�....");
		Sleep(Story);
		AQC();
		gotoxyP(5, 34, "�ϼ��� ������ : �ϵ���......");
		Sleep(Story / 2);
		AQC();
		gotoxyP(5, 34, "�ϼ��� ������ : �ϵ���...............");
		Sleep(Story);
		//���� AQC���� ����.
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. �Ͻ� ������ ������� �ϴ�. �峭�⸦ �ߵ���Ų��.");
			gotoxyP(5, 37, "2. ������ ��ٸ���.");
			gotoxy(5, 39);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
			Assistant_Text_clear();
		}
		if (n == 1)
		{
			gotoxyP(5, 35, "�ϼ��� ������ : �ϵ���...............");
			Sleep(Story);
			//AQC��������
			player_Talk(turnplayer, "�̻�����ĥ�ȱ�!...");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, ".�ϼ��� ������ : .........");
			Sleep(Story / 2);
			AQC();
			Assistant_Text_clear();
			system_("�����̶�� �Ѵ�.");
			Sleep(Story);
			AQC();
			system_("���н� ���°� �Ǿ����ϴ�.");
			Sleep(Story / 2);
			AQC();
			system_("���н� �˷� �����Դϴ�.");
			Sleep(Story);
			AQC();
			player_Talk(turnplayer, "���� �����̶� �����̶��~~~~~~.....");
			Sleep(Story);
			Game_over = 1;
			break;
		}
		if (n == 2)
		{
			gotoxyP(5, 34, "�ϼ��� ������ : �ϵ���........ ���� ���� �ҷ��� �ʹ� ����.");
			Sleep(Story);
			AQC();
			w = 1;
			while (w)
			{
				system_("����� ���� ����ҷ��Դϴ�. ��� �Ͻðڽ��ϱ�?");
				gotoxyP(5, 36, "1. ������ ���� �����Դ´�.");
				gotoxyP(5, 37, "2. ������ ģ���鵵 ����ҷ������̹Ƿ� �����Ա⺸�� �˼��ϴٰ� �Ѵ�.");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1)
			{
				system_("���� �����Դ���..");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "�ϼ��� ������ : ���ϴ� ���̾�!!!!");
				Sleep(Story / 2);
				AQC();
				system_("�����ð����� ���� ���������� �ȵ˴ϴ�.");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 2)
			{
				AQC();
				player_Talk(turnplayer, "�˼��մϴ� ������...");
				Sleep(Story);
				AQC();
				gotoxyP(5, 36, "�ϼ��� ������ : �˼��ϸ�, �˼������� �������Ҿ����!");
				Sleep(Story);
				Assistant_Text_clear();
				gotoxyP(5, 36, "�ϼ��� ������ : �������� ������ �� �����ϵ���!");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 20, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}

		}
		break;
	case 18: // ������ ������ ���丮 ���̽�
		system_("����� �����, ������ ���� �����Բ��� �л����� �̸��� �ܿ�� ��ʴϴ�.");
		PlaySound(TEXT("JungD.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		system_("���� ���� ������ �ϰ� ��ʴϴ�.");
		Sleep(Story);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			system_("������ �Ͻðڽ��ϱ�?");
			Sleep(Story);
			gotoxyP(5, 36, "1. ���̽�ũ�� ������ �䱸�غ���.");
			gotoxyP(5, 37, "2. �׳� ����.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			player_Talk(turnplayer, "������ �� ���̽�ũ�� ���ּ��� ! ");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "������ ���� ������ : ���̽�ũ�� ? ���ڱ� ���� ���̽�ũ�� ?" );
			Sleep(Story);
			AQC();
			player_Talk(turnplayer, "������ ���̽�ũ�� ���� ���� ���� ����ݾƿ� ~ ");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "������ ���� ������ : ���� �Ҹ��� ~ ���� �׷� ");
			gotoxyP(29, 35, "�׷��� ���� ~");
			Sleep(Story);
			w = 1;
			Assistant_Text_clear();
			while (w)
			{
				gotoxyP(5, 36, "1. �׷��� ���� �� �ϳ��� �ּ���");
				gotoxyP(5, 37, "2. ���� ������ ~");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1)
			{
				player_Talk(turnplayer, "�׷��� ���� �� �ϳ��� �ּ��� !");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ���� ������ : ���� �׷��� ���ٴϱ� ~");
				Sleep(Story);
				AQC();
				system_("���ٰ� �׷��ø鼭 �ָӴϿ� ���𰡸� �־��̴ּ�.");
				Sleep(Story);
				AQC();
				Sleep(500);
				system_("���̽�ũ�� ������ ����� ! ");
				Sleep(Story);
				closeness_up(Now_Point, 20, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				player_Talk(turnplayer, "���� ������ ~");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "������ ���� ������ : ���� ���� ..");
				Sleep(Story);
				AQC();
				system_("���� ��ó�� ���� �Ͻô��� �ָӴϿ� ���𰡸� �־��̴ּ�.");
				Sleep(Story);
				AQC();
				Sleep(500);
				system_("���̽�ũ�� ������ ����� ! ");
				Sleep(Story);
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
		}
		else
		{
			rn = rand() % 3;
			if (rn == 0 || rn == 1)
			{
				system_("������ �������Դ� !");
				Sleep(Story);
				break;
			}
			else
			{
				system_("??? : �� ���� !");
				Sleep(Story);
				AQC();
				system_(" ���� �̿��� �������ȴ�. ");
				Sleep(Story);
				AQC();
				Sleep(Story / 3);
				system_(" ���� ���ߴ�... !");
				Sleep(Story+1000);
				Game_over = 1;
				break;
			}
		}
		break;
	   case 19: // ����� ������ ���丮 ���̽�
		   gotoxyP(5, 34, "����� ����� �����Բ��� ����� �ڽ��� �ű�� ��ʴϴ� !");
		   PlaySound(TEXT("JungH.wav"), 0, SND_FILENAME | SND_ASYNC);
		   Sleep(Story);
		   AQC();
		   gotoxyP(5, 34, "�ֻ� ������!");
		   Sleep(Story);
		   system_("����� ������������� �ֻ��� �Ǿ����ϴ�.");
		   Sleep(Story);
		   AQC();
		   w = 1;
		   while (w)
		   {
			   gotoxyP(5, 34, "����� ������ : �̹� ��̰� ������� �� ������ �ֻ��� ���Ѵ�. �һ��?");
			   gotoxyP(5, 36, "1. ���� �ϰڽ��ϴ�!!");
			   gotoxyP(5, 37, "2. �������� ���Ƹ�������Ʈ�� �־ ������ �����ϰڽ��ϴ�.");
			   gotoxy(5, 38);
			   scanf("%d", &n);
			   w = Is_it_right_num(n, 2);
		   }
		   Assistant_Text_clear();
		   if (n == 1)
		   {
			   gotoxyP(5, 34, "����� ������ : ��... �׷�. �Ǹ��ϱ�!");
			   Sleep(Story);
			   AQC();
			   gotoxyP(5, 34, "����� ������ : �������� ����� �ڽ� �� �Ű��ָ� ���ڴ�.");
			   Sleep(Story);
			   AQC();
			   player_Talk(turnplayer, "��, �˰ڽ��ϴ�!!");
			   Sleep(Story / 2);
			   AQC();
			   closeness_up(Now_Point, 30, turnplayer);
			   Sleep(Story);
			   Assistant_Text_clear();
			   break;
		   }
		   else if (n == 2)
		   {
			   system_("�ֻ꿡�� ������߽��ϴ�");
			   Sleep(Story / 2);
			   AQC();
			   player_Talk(turnplayer, "???????");
			   Sleep(Story / 3);
			   AQC();
			   system_("����� ����������. �����Դϴ�.����");
			   Sleep(Story);
			   Assistant_Text_clear();
			   closeness_down(Now_Point, 20, turnplayer);
			   Sleep(Story);
			   break;
		   }
		   break;
   }
}