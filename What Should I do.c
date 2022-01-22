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
	case 0: //아라마크 케이스 스토리
		system_( "여기는 아라마크 입니다");
		Sleep(Story);
		AQC();
		system_("식량을 공급해주는 공간입니다");
		Sleep(Story);
		AQC();
		system_("가끔 맛있는 음식도 준답니다 !");
		Sleep(Story / 2);
		AQC();
		rn = rand() % 6;
		if (rn == 0) {
			system_("토마토를 먹었습니다 !");
			Sleep(Story / 2);
			AQC();
			system_("맛있어서 한칸 앞으로 갑니다.");
		}
		else if (rn == 1) {
			system_("사과를 먹었습니다 !");
			Sleep(Story / 2);
			AQC();
			system_("맛있어서 두칸 앞으로 갑니다.");
		}
		else if (rn == 2) {
			system_("아이스크림을 먹었습니다 !");
			Sleep(Story / 2);
			AQC();
			system_("맛있어서 세칸 앞으로 갑니다.");
		}
		else if (rn == 3) {
			system_("구운 닭다리를 먹었습니다 !");
			Sleep(Story / 2);
			AQC();
			system_("맛있어서 네칸 앞으로 갑니다.");
		}
		else if (rn == 4) {
			system_("김치버섯우동를 먹었습니다 !");
			Sleep(Story / 2);
			AQC();
			system_("너무 맛있어서 다섯칸 앞으로 갑니다.");
		}
		else if (rn == 5) {
			system_("부대찌개를 먹었습니다 !");
			Sleep(Story / 2);
			AQC();
			system_("눈물 날 정도로 맛있어서 다섯칸 앞으로 갑니다.");
		}
		Sleep(Story);
		AQC();
		gotoxy(5, 34);
		printf("%d칸 이동했습니다", rn + 1);
		Go_To_MapPoint(turnplayer, rn + 1);
		Sleep(Story);
		break;
	case 1: // 류명희 선생님스토리 케이스
		gotoxyP(5, 34, "여기는 류명희 선생님께서 우아하게 앉아 계십니다 ! ");
		PlaySound(TEXT("RyuM.wav"), 0, SND_FILENAME | SND_ASYNC);
		if (closeness[Now_Point] >= 150 && turnplayer == 2)  //친밀도 관련 IF문
		{
			Sleep(Story);
			AQC();
			sprintf(chTemp, "%s 잖아! 호호홓 뭔일이니?", player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
		}
		else if (closeness[Now_Point] <= 50 && turnplayer == 1)
		{
			Sleep(Story);
			AQC();
			sprintf(chTemp, "%s 잖아! 호호홓 뭔일이니 ? ", player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
		}

		Sleep(Story);
		setcolor(32, 7);
		AQC();

		gotoxyP(5, 34, "무엇을 하시겠습니까? ");
		Sleep(Story / 3);
		w = 1;
		while (w) { //입력을 받는 while 문
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 류명희 선생님의 성대모사를 한다 ");
			gotoxyP(5, 37, "2. 그냥 나온다.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2); //입력한 값이 선택지에있는지 없는지 판단해주는 함수
		}
		setcolor(32, 31);
		Assistant_Text_clear(); 
		w = 1;
		if (n == 1)
		{
			while (w) {
				gotoxyP(5, 36, "1. 내지는~ 내지는~");
				gotoxyP(5, 37, "2. 요 정도 센스를 발휘하면~ ");
				gotoxyP(5, 38, "3. 개 풀 뜯어먹고 있는 소리 하고 있네~ ");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 3);
			}
			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 1)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "류명희 선생님 : 어머 너 지금 나 따라하는 거니?");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "얘 정말 웃긴다아하핳");
				Sleep(Story);
				AQC();
				system_("친밀도가 40 상승했습니다! ");
				closeness_up(Now_Point, 40, turnplayer);
				Sleep(Story / 2);
				break;
			}
			else if (n == 2)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "류명희 선생님 : 어머 너 지금 나 따라하는 거니?");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "류명희 선생님: 푸훗, 그런거 할 시간에 수학문제나 하나 더 풀어 !");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 20, turnplayer);
				Sleep(Story / 2);
				break;
			}
			else if (n == 3)
			{
				setcolor(32, 31);
				gotoxyP(5, 34, "류명희 선생님 : 어머 너 지금 나 따라하는 거니?");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "류명희 선생님: 내가 언제 그랬어 !!");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story / 2);
				break;
			}
		}
		else {
			system_("무사히 나왔다 ! ");
			Sleep(Story / 3);
			break;
		}
		break;
	case 2: //함지연 선생님 스토리 케이스
		setcolor(32, 7);
		gotoxyP(5, 34, "여기는 함지연 선생님께서 플밍 수업을 하고 계십니다 ! ");
		PlaySound(TEXT("HamG.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 31);
		AQC();
		setcolor(32, 7);
		gotoxyP(5, 34, "너무 바쁘신거 같아 건드릴 수가 없습니다. ");
		Sleep(Story*0.6);
		setcolor(32, 31);
		AQC();
		w = 1;
		while (w) {
			setcolor(32, 7);
			gotoxyP(5, 34, "무엇을 하시겠습니까?");
			Sleep(Story / 3);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 그래도 빠꾸없이 가까이 다가가본다 . ");
			gotoxyP(5, 37, "2. 너무 바쁘신거 같아 그냥 가야겠다 . ");
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
				gotoxyP(5, 34, "함지연 선생님 : 재민아 뭐해 ? ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "양재민 : 엇 , 아니에요. (급하게 피파를 끄며) ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "함지연 선생님 : 재민이 안되겠네 ? ");
				Sleep(Story / 2);
				AQC();
				system_("선생님께서는 (양)재민을 혼내시느라 바쁘신듯 하다");
				Sleep(Story);
				AQC();
				break;
			}
			else if (rn == 1)
			{
				gotoxyP(5, 34, "함지연 선생님 : 기석아 뭐해 ? ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "권기석 : 나..나닛.. ! (급하게 인터넷 브라우저를 끄며)");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "권기석 : 고..고멘나사이 ..!");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "함지연 선생님 : 기석이 뭐라는 거니 ? ");
				Sleep(Story / 2);
				AQC();
				system_("선생님께서는 (권)기석의 말을 못알아들으신 듯 하다");
				Sleep(Story);
				AQC();
				break;
			}
			else if (rn == 2)
			{
				gotoxyP(5, 34, "함지연 선생님 : 건아 뭐해 ? ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "이건 : (급하게 노트북을 끄며) 아 이거 그냥 뭐 공부 좀 그냥 하다가 그냥");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "이건 : 뭐 안했어요 아무것도 정말로 안했어요. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "함지연 선생님 : 뭔가 수상하네 ~ ?");
				Sleep(Story);
				AQC();
				system_("건이가 게임했다는 사실을 일러바쳤더니, 함지연 선생님께서 흐뭇해하신다. ");
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
				gotoxyP(5, 34, "왠지 그냥 기분이 좋아 보이신다. ");
				setcolor(32, 31);
				Sleep(Story*0.6);
				AQC();
				setcolor(32, 7);
				gotoxyP(5, 34, "친밀도가 10 상승했습니다! ");
				closeness_up(Now_Point, 10, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				setcolor(32, 7);
				gotoxyP(5, 34, "너무 바쁘셔서 내가 나온줄도 모르고 계신다. ");
				setcolor(32, 31);
				Sleep(Story*0.6);
				AQC();
				break;
			}
		}
		break;
	case 3: //허관무 선생님 스토리 케이스
		if (C3_event < 1)
		{
			setcolor(32, 31);
			gotoxyP(5, 34, "여기는 허관무 선생님께서 망가진 분필을 수리하고 계십니다 ! ");
			PlaySound(TEXT("HeoG.wav"), 0, SND_FILENAME | SND_ASYNC);
			C3_event++;
			Sleep(Story);
			Assistant_Text_clear();
			w = 1;
			while (w) { //선택지 도는 while문
				gotoxyP(5, 34, "허관무 선생님 : 허허 ! 주요 어휘 어구를 쓰다가 그만.. 분필을 부러뜨렸군	");
				Sleep(Story / 3);
				gotoxyP(5, 36, "1. 분필 수리를 도와드린다.");
				gotoxyP(5, 37, "2. 국어 문제를 풀어보자 ");
				gotoxyP(5, 38, "3. 그냥 모른척 하고 지나친다.");
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
				sprintf(chTemp, "%s : 선생님..제가 도와드릴까요 ? ", player[turnplayer-1].name);
				AQC();
				gotoxyP(5, 34, chTemp);
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "허관무 선생님 : 허허, 이미 다 고쳤단다.");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "허관무 선생님 : 마음만큼은 고맙다 ! ");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 50, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 2) //국어 문제 풀기
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				rn = rand() % 3;
				if (rn == 0)
				{
					gotoxyP(5, 34, "나 지금 바쁘단다 ! 그런건 다음에 해줄게 ~");
					Sleep(Story);
					break;
				}
				else if (rn == 1) // 국어 문제 파트
				{
					gotoxyP(5, 34, "어허,, 무엇을 내면 좋을까");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "그래 ! 문제를 내보마");
					Sleep(Story * 0.3);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "가장 달콤한 술은?");
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. 입술");
						gotoxyP(5, 37, "2. 참이술");
						gotoxyP(5, 38, "3. 이슬툭툭");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "오 대단한걸?");
						Sleep(Story / 2);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "아니야 !! 그거 아니야 !");
						Sleep(Story / 2);
						break;
					}
				}
				else if (rn == 2)
				{
					gotoxyP(5, 34, "어허,, 무엇을 내면 좋을까");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "그래 ! 문제를 내보마");
					Sleep(Story * 0.6);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "세상에서 가장 맛있는 집은?"); //문제 ~
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. 닭똥집");
						gotoxyP(5, 37, "2. 움집");
						gotoxyP(5, 38, "3. 경기도 안산시 단원구 와동 사세충열로 94");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "오 대단한걸?");
						Sleep(Story / 2);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "저런 ! 틀렸단다 !");
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
					gotoxyP(5, 34, "너무 조용히 빠져나와 아무도 모르는 듯 하다.");
					Sleep(Story);
					break;
				}
				else
				{
					sprintf(chTemp, "허관무 선생님 : %s ! 어디가 ! 허 거참 ..", player[turnplayer-1].name);
					gotoxyP(5, 34, chTemp);
					Sleep(Story);
					break;
				}
				gotoxyP(5, 34, "너무 조용히 빠져나와 아무도 모르는 듯 하다.");
				Sleep(Story);
				break;
			}
		}
		else
		{
			gotoxyP(5, 34, "허관무 선생님께서 주요 어휘 어구를 찾고 계십니다 . "); // 선생님들의 특징을 반영한 게임 스토리
			PlaySound(TEXT("HeoG.wav"), 0, SND_FILENAME | SND_ASYNC);
			w = 1;
			Sleep(Story);
			while (w) {
				AQC();
				gotoxyP(5, 34, "무엇을 하시겠습니까?");
				Sleep(Story / 3);
				gotoxyP(5, 36, "1. 국어 문제를 풀어본다.");
				gotoxyP(5, 37, "2. 그냥 조용히 빠져나온다.");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 3);
				Story = 0;
			}
			if (n == 1) // 1.국어문제를 풀어본다.의 선택지 문 경로
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				rn = rand() % 3; // 국어 문제 3개중 랜덤
				if (rn == 0)
				{
					gotoxyP(5, 34, "나 지금 바쁘단다 ! 그런건 다음에 해줄게 ~");
					Sleep(Story);
					break;
				}
				else if (rn == 1) // 국어 문제 파트
				{
					gotoxyP(5, 34, "어허,, 무엇을 내면 좋을까");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "그래 ! 문제를 내보마");
					Sleep(Story /2);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "가장 달콤한 술은?");
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. 입술");
						gotoxyP(5, 37, "2. 참이술");
						gotoxyP(5, 38, "3. 이슬툭툭");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "오 대단한걸?");
						Sleep(Story/2);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "저런 ! 틀렸단다 !");
						Sleep(Story);
						break;
					}
				}
				else if (rn == 2)
				{
					gotoxyP(5, 34, "어허,, 무엇을 내면 좋을까");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "그래 ! 문제를 내보마	");
					Sleep(Story * 0.6);
					w = 1;
					while (w) {
						AQC();
						gotoxyP(5, 34, "세상에서 가장 맛있는 집은?");
						Sleep(Story / 3);
						gotoxyP(5, 36, "1. 닭똥집");
						gotoxyP(5, 37, "2. 움집");
						gotoxyP(5, 38, "3. 경기도 안산시 단원구 와동 사세충열로 94");
						gotoxy(5, 39);
						scanf("%d", &n);
						w = Is_it_right_num(n, 3);
					}
					if (n == 1)
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "오 대단한걸?");
						Sleep(Story);
						closeness_up(Now_Point, 30, turnplayer);
						Sleep(Story);
						break;
					}
					else
					{
						Assistant_Text_clear();
						gotoxyP(5, 34, "저런 ! 틀렸단다 !");
						Sleep(Story);
						break;
					}
				}
			}
			else if (n == 2) //2. 그냥 조용히 빠져나온다. 의 선택지 문 경로
			{
				AQC();
				rn = rand() % 2;
				if (rn == 1)
				{
					gotoxyP(5, 34, "너무 조용히 빠져나와 아무도 모르는 듯 하다.");
					Sleep(Story);
					break;
				}
				else
				{
					sprintf(chTemp, "허관무 선생님 : %s ! 어디가 ! 허 거참 ..", player[turnplayer].name);
					gotoxyP(5, 34, chTemp);
					Sleep(Story);
					AQC();
					closeness_down(Now_Point, 10, turnplayer);
					break;
				}
				gotoxyP(5, 34, "너무 조용히 빠져나와 아무도 모르는 듯 하다.");
			}
			break;
		}
	case 4: //제제 쌤 스토리 케이스
		gotoxyP(5, 34, "여기는 제제 ! 여기는 제제 ! ");
		PlaySound(TEXT("JeJe.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		gotoxyP(5, 34, "오늘은 주말인데도 학교에 나오셨나 봅니다 . ");
		Sleep(Story);
		setcolor(32, 31);
		w = 1;
		while (w)
		{
			Assistant_Text_clear();
			system_("무엇을 하시겠습니까?");
			Sleep(Story / 3);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 가서 아이스크림을 사달라고 떼써본다.");
			gotoxyP(5, 37, "2. 사회 문제를 풀어본다");
			gotoxyP(5, 38, "3. 제제쌤을 만나고는 싶지만 참고 가던길을 간다.");
			gotoxy(5, 39);
			scanf("%d", &n);
			w = Is_it_right_num(n, 3);
		}
		if (n == 1) //선택지 1번을 선택했을때
		{
			Assistant_Text_clear();
			setcolor(32, 31);
			gotoxyP(5, 34, "제제 선생님 : 무슨 일?");
			Sleep(Story / 2);
			AQC();
			sprintf(chTemp, "%s : 저 아이스크림 하나 .. 사주세요 ",player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			Assistant_Text_clear();
			rn = rand() % 3;
			if (rn == 0)
			{
				gotoxyP(5, 34, "야야 ~");
				Sleep(Story / 3);
				gotoxyP(5, 35, "무슨 아이스크림은 아이스크림이야 ~");
				Assistant_Text_clear();
				gotoxyP(5, 34, "이상한 소리 하지 마 ~");
				Sleep(Story);
				system_("근데 왠지 제제쌤 기분은 좋아 보인다. ");
				Sleep(Story);
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
			else if (rn == 1)
			{
				gotoxyP(5, 34, "야야 ~");
				Sleep(Story / 3);
				gotoxyP(5, 35, "무슨 아이스크림은 아이스크림이야 ~");
				PlaySound(TEXT("JeJe2.wav"), 0, SND_FILENAME | SND_ASYNC);
				Assistant_Text_clear();
				gotoxyP(5, 34, "너가 나 사줘야지 ~ ! ");
				Sleep(Story);
				system_("안사드려서 삐지신 듯 하다 ");
				Sleep(Story);

				closeness_down(Now_Point, 10, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				gotoxyP(5, 34, "야야 ~");
				Sleep(Story / 3);
				gotoxyP(5, 35, "나 지금 바뻐 ~");
				Sleep(Story / 2);
				Assistant_Text_clear();
				gotoxyP(5, 34, "그런거 너가 사먹어  ~ ");
				Sleep(Story);
				system_("그래도 사주고 싶은 눈치셨다. ");	
				Sleep(Story);
				closeness_up(Now_Point, 10, turnplayer);
				Sleep(Story);
				break;
			}
		}
		else if (n == 2) //선택지 2번을 선택했을때
		{
			Assistant_Text_clear();
			setcolor(32, 31);
			rn = rand() % 3;
			if (rn == 0)
			{
				gotoxyP(5, 34, "제제 선생님 : 평소에 사회시간에 잠만 자는 놈이.. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "사회를 얕보면 안돼 ~");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "문제를 내보마.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "흑인이 자기소개를 하면? (입력 후 엔터) ");
				gotoxy(5, 36);
				scanf("%s", &chTemp);
				if (!strcmp(chTemp, "암흑"))
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "야 ~  너 좀 한다 ? ");
					Sleep(Story);
					AQC();
					closeness_up(Now_Point, 50, turnplayer);
					Sleep(Story);
					break;
				}
				else
				{
					AQC();
					gotoxyP(5, 34, "아니야 ~ 틀렸어 ~");
					Sleep(Story/3);
					gotoxyP(5, 35, "정답은 암 흑 이야 ~ ");
					Sleep(Story);
					AQC();
					break;
				}
			}
			else if (rn == 1)
			{
				gotoxyP(5, 34, "제제 선생님 : 평소에 사회시간에 잠만 자는 놈이.. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "사회를 얕보면 안돼 ~");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "어려운 거 낼거야 ~ ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "소랑 개랑 부딪히면? (입력 후 엔터)");
				gotoxy(5, 36);
				scanf("%s", &chTemp);
				if (!strcmp(chTemp, "소개팅"))
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "야 ~  너 좀 한다 ? ");
					Sleep(Story);
					AQC();
					closeness_up(Now_Point, 50, turnplayer);
					break;
				}
				else
				{
					AQC();
					gotoxyP(5, 34, "아니야 ~ 틀렸어 ~ ");
					Sleep(Story/3);
					gotoxyP(5, 35, "정답은 소 개 팅 이야 ~");
					Sleep(Story);
					AQC();
					break;
				}
			}
			else if (rn == 2)
			{
				gotoxyP(5, 34, "제제 선생님 : 평소에 사회시간에 잠만 자는 놈이.. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "사회를 얕보면 안돼 ~");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "어려운 거 낼거야 ~ ");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "물을 자르면? (입력 후 엔터) ");
				gotoxy(5, 36);
				scanf("%s", &chTemp);
				if (!strcmp(chTemp, "수컷"))
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "야 ~  너 좀 한다 ? ");
					Sleep(Story);
					AQC();
					closeness_up(Now_Point, 50, turnplayer);
					break;
				}
				else
				{
					AQC();
					gotoxyP(5, 34, "아니야 ~ 틀렸어 ~ ");
					Sleep(Story/3);
					gotoxyP(5, 35, "정답은 수컷 이야 ~");
					Sleep(Story);
					break;
				}
			}
		}
		else if (n == 3) // 3번
		{
		Assistant_Text_clear();
			rn = rand() % 2;
			if (rn == 0)
			{
				system_("제제 선생님께서는 무언가 일을 열심히 하고 계셔서");
				Sleep(Story / 2);
				setcolor(32, 7);
				gotoxyP(5, 35, "내가 나온줄도 모르시는 것 같았다.");
				Sleep(Story);
				break;
			}
			else
			{
				system_("제제 선생님께서 내가 나가는 걸 보신 듯 하다. ");
				Sleep(Story);
				Assistant_Text_clear();
				closeness_down(Now_Point, 10, turnplayer);
			}
		}
		break;
case 5: //박경수 선생님 스토리 케이스
	PlaySound(TEXT("ParkG.wav"), 0, SND_FILENAME | SND_ASYNC);
	gotoxyP(5, 34, "여기는 박경수 선생님께서 한국사 뽑기 막대를 수리중이십니다 ! ");
	Sleep(Story);
	AQC();
	gotoxyP(5, 34, "오늘의 발표의 주인공은 누가 될 것인가요? 막대 뽑을사람있나요??");
	Sleep(Story / 2);
	w = 1;
	while (w)
	{
		setcolor(32, 31);
		gotoxyP(5, 36, "1. 직접 뽑기막대를 뽑는다.");
		gotoxyP(5, 37, "2. 기다린다");
		gotoxy(5, 38);
		scanf("%d", &n);
		w = Is_it_right_num(n, 2);
	}
	setcolor(32, 31);
	Assistant_Text_clear();
	w = 1;
	if (n == 1)
	{
		gotoxyP(5, 34, "자~ 뽑으세요!");
		Sleep(Story / 3);
		AQC();
		rn = rand() % 10;
		rn = rn + 2;
		int cnt = 0;
		while (cnt < rn)
		{
			gotoxy(5, 34);
			printf("%d   (66%%의 확률로 발표뽑힘)", rand() % 37);
			Sleep(250);
			cnt++;
		}
		rn = 0;
		Assistant_Text_clear();
		rn = rand() % 3;
		if (rn == 0 || rn == 1)         //66%의 확률로 발표당첨!
		{
			gotoxy(5, 34);
			sprintf(chTemp, "%s 나와서 발표해주세요", player[turnplayer].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			AQC();
			gotoxyS(5, 34, "발표중입니다."); Sleep(500);
			gotoxyS(5, 34, "발표중입니다.."); Sleep(500);
			gotoxyS(5, 34, "발표중입니다..."); Sleep(500);
			gotoxyS(5, 34, "발표중입니다...."); Sleep(500);
			gotoxyS(5, 34, "발표를 무사히 마쳤다.");
			Sleep(Story / 2);
			AQC();
			gotoxyP(5, 34, "박경수 선생님께서 추가 질문을 하신다.");
			Sleep(Story / 3);
			AQC();
			gotoxyP(5, 34, "박경수 선생님 : 우리나라 5대 국경일이 아닌것은 무엇인가요?");
			Sleep(Story);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 개천절   2. 삼일절");
			gotoxyP(5, 37, "3. 빼빼로데이   4. 제헌절   5.광복절");

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
				gotoxyP(5, 34, "박경수 선생님 : 네에~ 잘 알고 계시네요");
				Sleep(Story / 3);
				closeness_up(Now_Point, 50, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 1 || n == 2 || n == 4 || n == 5)
			{
				setcolor(32, 31);
				gotoxyS(5, 34, "박경수 선생님 : ...");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "박경수 선생님 : ....");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "박경수 선생님 : ...");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "박경수 선생님 : ....");
				Sleep(Story / 2);
				AQC();
				gotoxyS(5, 34, "대답이 없으시다.");
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
			sprintf(chTemp, "%d번 학생 나와서 발표해주세요.", rn);
			gotoxyP(5, 34, chTemp);
			Sleep(Story / 2);
			AQC();
			gotoxyS(5, 34, "당신의 발표기회는 날라갔습니다");
			Sleep(Story / 2);
			AQC();
			system_("발표는 다음시간에....");
			Sleep(Story / 2);
			AQC();
			break;
		}
	}
	if (n == 2)
	{
		gotoxyP(5, 34, "박경수 선생님 : 사실, 오늘은 발표가 없습니다!");
		Sleep(Story / 2);
		AQC();
		system_("박경수 선생님께서 열심히 수업중이십니다.");
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
		gotoxyP(5, 34, "잠들었나봅니다.");
		Sleep(Story / 3);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 계속 잔다");
			gotoxyP(5, 37, "2. 잠에서 깨고 수업을 듣는다");
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
			system_("계속 잠을 잡니다...");
			Sleep(Story);
			player_Talk(turnplayer, "어엇~!");
			Sleep(Story / 3);
			player_Talk(turnplayer, "여긴....");
			Sleep(Story / 3);
			player_Talk(turnplayer, "여긴 어디지?!!!");
			Sleep(Story);
			system_("여긴.. 병자호란 때의 조선입니다");
			Sleep(Story / 2);
			system_("당신을 위협하는 청나라 군사들이 쏘는 화살을 피하세요.");
			Sleep(Story);
			player_Talk(turnplayer, "???");
			Sleep(Story / 2);
			system_("시작합니다");
			Sleep(Story / 2);
			avoidArrow(); //화살 미니게임을 불러옵니다.
			player_Talk(turnplayer, "치명상?!");
			Sleep(Story);
			gotoxy(5, 36);
			gotoxyP(5, 36, "박경수 선생님 : 잠꼬대를 하는군요??");
			Sleep(Story);
			AQC();
			system_("잠꼬대를 하여 친밀도가 감소합니다");
			Sleep(Story / 2);
			closeness_down(Now_Point, 10, turnplayer);
			Sleep(Story);
			Assistant_Text_clear();
			break;
		}
		else if (n == 2)
		{
			system_("당신은 잠에서 깼습니다.");
			Sleep(Story / 2);
			system_("하지만, 당신은 졸았습니다");
			Sleep(Story / 2);
			system_("인정하시나요?");
			Sleep(Story);
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. 예 인정합니다");
				gotoxyP(5, 37, "2. 아니요. 저는 졸지 않았습니다");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 1)
			{
				player_Talk(turnplayer, "예, 저는 졸았습니다");
				Sleep(Story);
				AQC();
				system_("졸았으므로, 친밀도가 감소합니다");
				Sleep(Story / 2);
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 2)
			{
				player_Talk(turnplayer, "저는 졸지 않았습니다!");
				Sleep(Story);
				AQC();
				system_("거짓말을 했으므로 친밀도가 감소합니다");
				Sleep(Story);
				closeness_down(Now_Point, 40, turnplayer);
				Sleep(Story);
				break;
			}
		}
	}
	break;
	case 6: //김상욱 선생님 스토리 케이스
		gotoxyP(5, 34, "여기는 김상욱 선생님께서 철권을 연습중이십니다 ! ");
		Sleep(Story*0.3);
		gotoxyP(5, 35, "왠지 가까이 다가가면 화내실 듯 합니다 . ");
		Sleep(Story);
		setcolor(32, 31);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			AQC();
			setcolor(32, 7);
			gotoxyP(5, 34, "무엇을 하시겠습니까?");
			Sleep(Story / 3);
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 가까이 다가간다. ");
			gotoxyP(5, 37, "2. 눈치껏 나간다. ");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		if (n == 1)
		{
			setcolor(32, 31);
			Assistant_Text_clear();
			gotoxyP(5, 34, "(뿌슝 ! 쀼숭 ! 퐝퐝 !!)");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "김상욱 선생님 : ...");
			Sleep(Story*0.6);
			AQC();
			gotoxyP(5, 34, "김상욱 선생님: ! ");
			Sleep(Story *0.6);
			AQC();
			if (C6_event < 1)
			{
				gotoxyP(5, 34, "김상욱 선생님 : 엇 미안하다. 내가 너무 집중했구나 ");
				Sleep(Story);
				C6_event++;
			}
			else
			{
				gotoxyP(5, 34, "김상욱 선생님 : 아 또 걸려버렸네 ! 허헣");
				Sleep(Story);
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
			}
			system_("더이상 머물면 방해가 될거 같아 나왔다. ");
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
				gotoxyP(5, 34, "철권에 너무 집중하셔서 못보신 듯하다. ");
				Sleep(Story);
			}
			else
			{
				setcolor(32, 31);
				Assistant_Text_clear();
				gotoxyP(5, 34, "여기를 힐끗 쳐다보신 듯 하긴 하지만 크게 신경쓰시지는 않는 것 같다. ");
				Sleep(Story + 1000);
			}
		}
		break;
	case 7: //배종우 선생님 스토리 케이스
		gotoxyP(5, 34, "여기는 배종우 선생님께서 열심히 헬스중이십니다 . ");
		PlaySound(TEXT("BaeJ.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 7);
		AQC();
		gotoxyP(5, 34, "배종우 선생님과 무엇을 하시겠습니까? ");
		Sleep(Story / 3);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 배종우 선생님과 헬스를 한다");
			gotoxyP(5, 37, "2. 배종우 선생님과 농구를 하자 한다");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();

		if (n == 1)
		{
			system_("배종우 선생님과 헬스를 해서 친밀도가 올랐습니다");
			Sleep(Story);
			closeness_up(Now_Point, 15, turnplayer);
			Sleep(Story);
			break;
		}

		if (n == 2)
		{
			gotoxyP(5, 34, "배종우 선생님 : 내가 너랑 농구를 왜해");
			Sleep(Story);
			AQC();
			system_("잠시후 .. ");
			Sleep(Story + 2000);
			AQC();
			system_("배종우 선생님과 농구를 너무 열심히 해 친밀도가 올랐습니다.");
			Sleep(Story);
			AQC();
			closeness_up(Now_Point, 40, turnplayer);
			Sleep(Story);
			break;
		}

		break;
	case 8: //전희진 선생님 스토리 케이스
		gotoxyP(5, 34, "여기는 전희진 선생님의 은밀한 공간, 학봉간 교무실입니다 ! ");
		PlaySound(TEXT("JeonH.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		system_("왠지 들어가면 안될 분위기 .. ! ");
		Sleep(Story);
		w = 1;
		while (w)
		{
			system_("어떻게 하시겠습니까 ? ");
			gotoxyP(5, 36, "1. 용감하게 들어가본다 ");
			gotoxyP(5, 37, "2. 아니다, 그냥 돌아간다 "); // 여기 입력 부분에서 오류 뜸.
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		if (n == 1) // 선택지 1 선택
		{
			Assistant_Text_clear();
			//chTemp[200] =  '\0' ;
			sprintf(chTemp, "%s : (똑똑)", player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			AQC();
			setcolor(32, 31);
			gotoxyP(5, 34, "전희진 선생님 : 뭐야, 너 나와 ");
			Sleep(Story);
			Assistant_Text_clear();
			w = 1;
			while (w)
			{
				gotoxyP(5, 34, "전희진 선생님 : 무슨 일 ? ");
				gotoxyP(5, 36, "1. 아무것도 아니에요. ");
				gotoxyP(5, 37, "2. 정말로 아무것도 아니에요. ");
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
					gotoxyP(5, 34, "전희진 선생님 : ... ?");
					Sleep(Story);
					gotoxyP(21, 34, " 너 일로 와봐");
					Sleep(Story);
					gotoxyP(21, 34, "뭔가 수상해 ~ ?");
					Sleep(Story);
					AQC();
					gotoxyP(5,34,"정말로 아무것도 아니에요 !!");
					Sleep(Story);
					Assistant_Text_clear();
					Sleep(1000);
					system_("무사히 빠져나오긴 했지만 아직까지도 전희진 선생님꼐서는 나를 의심하는 듯 하다. ");
					Sleep(Story);
					AQC();
					break;
				}
				else if (rn == 1)
				{
					Assistant_Text_clear();
					gotoxyP(5, 34, "전희진 선생님 : ... ?");
					Sleep(Story);
					gotoxyP(21, 34, "너 일로 와봐");
					Sleep(Story);
					gotoxyP(21, 34, "뭐야 너 뭐하는 놈이야?");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "아뇨, 잘못 왔어요 ... ! ");
					Sleep(Story);
					AQC();
					gotoxyP(5, 34, "전희진 선생님 : 너 이자식, 학번 이름 부르고 가. ");
					Sleep(Story);
					AQC();
					system_("무슨 일인지 내 번호를 받아 가셨다. ");
					Sleep(Story);
					break;
				}			
			}
		}
		else if (n == 2) //선택지 2 선택
		{
			rn = rand() % 2;
			if (rn == 0)
			{
				Assistant_Text_clear();
				gotoxyP(5, 34, "전희진 선생님 : 밖에 누구야 ! 일로 나와 !");
				Sleep(Story);
				AQC();
				system_("전희진 선생님의 말을 무시하고 나오긴 했으나,");
				Sleep(Story);
				AQC();
				system_("뭔가 찝찝한 느낌은 남았다. ");
				Sleep(Story);
				break;
			}
			else
			{
				Assistant_Text_clear();
				system_("무사히 빠져나왔다 ! ");
				Sleep(Story);
				break;
			}
		}
		break;
	case 9: //양희정 선생님 스토리 케이스
		setcolor(32, 7);
		gotoxyP(5, 34, "여기는 양희정 선생님의 연극 데뷔를 위한 공간입니다 ! ");
		PlaySound(TEXT("YangH.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		rn = rand() % 3;
		if (rn == 1)
			system_("이제 막 야자 감독을 끝내신 듯 합니다.");
		else if (rn == 2) {
			system_("연기 연습을 하고 계십니다."); Sleep(Story);
			system_("실력이 굉장히 수준급이십니다. ");
		}
		else
			system_("무언가에 열중하신 모습이 보입니다. ");
		Sleep(Story);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			system_("무엇을 하시겠습니까? ");
			gotoxyP(5, 36, "1. 대화를 걸어본다. ");
			gotoxyP(5, 37, "2. 그냥 지나친다. ");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1) //선택지 1번 선택시
		{
			gotoxyP(5, 34, "자, 선생님이 먼저 인사하겠습니다! ");
			Sleep(Story);
			gotoxyP(5, 35, "자, 선생님이 먼 ↗저↘ 인사하겠습니다! ");
			Sleep(Story);
			Assistant_Text_clear();
			sprintf(chTemp, "%s : 안녕하세요 선생님 ! ",player[turnplayer-1].name);
			gotoxyP(5, 34, chTemp);
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "양희정 선생님 : 어 무슨 일이니? ");
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. 저 배우 해보고 싶어요 ! ");
				gotoxyP(5, 37, "2. 지금 방송 하실 시간 아니에요? ");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1) // 선택지 1
			{
				sprintf(chTemp, "%s : 선생님 저 배우 한번 해보고 싶어요 ! ",player[turnplayer-1].name);
				gotoxyP(5, 34, chTemp);
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "양희정 선생님 : 배우 하고 싶다고? ");
				Sleep(Story);
				gotoxyP(21, 35, "배우라는 직업은 정말로 멋지지 ");
				Sleep(Story);
				rn = rand() % 2;
				if (rn == 0)
					gotoxyP(21, 36, "먼저 피부 관리 ! 피부 관리가 중요하단다. ");
				else
				{
					gotoxyP(21, 36, "티비를 봐야해 , 티비를. ");
					Sleep(Story);
					Assistant_Text_clear();
					gotoxyP(5, 34, "양희정 선생님 : 실제 배우들의 연기를 봐야 하는게 가장 중요하단다.");
				}
				Sleep(Story + 1000);
				Assistant_Text_clear();
				gotoxyP(5, 34, "양희정 선생님 : 또 디미고인이라면 품 ! 세가 달라야해 !");
				Sleep(2500);
				gotoxyP(21, 35, "그래야 멋진 배우를 할 수 있지 ");
				Sleep(2500);
				gotoxyP(21, 36, "알았지? 원래 배우의 길은 힘든 법이란다.");
				Sleep(5000);
				Assistant_Text_clear();
				system_(" ( 그 뒤로 여러 명언들을 남겨주셨다 )");
				Sleep(4000);
				AQC();
				Sleep(2000);
				setcolor(32, 31);
				player_Talk(turnplayer, "좋은 말씀 감사드려요... !");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "양희정 선생님 : 응응!! 그래^^ ");
				Sleep(Story);
				closeness_up(Now_Point, 40, turnplayer);
				Sleep(Story);
				break;
			}
			else // 선택지 2
			{
				gotoxyP(5, 34, "양희정 선생님 : 아차 ! 내 정신 좀 봐");
				Sleep(Story);
				AQC();
				system_("선생님께서는 급하게 어디론가 가셨다..");
				Sleep(Story);
				AQC();
				Sleep(Story / 3);
				system_("잠시후...");
				Sleep(Story);
				AQC();
				setcolor(7, 31);
				gotoxyP(5, 34, "아 .....");
				Sleep(1000);
				gotoxyP(14, 34, "아....  10분 남았다, ");
				gotoxyP(5, 35, "잘 자라");
				Sleep(Story * 2);
				setcolor(32, 31);
				Assistant_Text_clear();
				player_Talk(turnplayer, "나도 이제 슬슬 자야겠다. ");
				Sleep(Story);
				AQC();
				Sleep(Story / 2);
				system_("날이 밝았습니다. ");
				Sleep(Story);
				break;
			}
		}
		else if (n == 2) // 선택지 2번 선택시
		{
			rn = rand() % 3;
			if (rn == 0)
			{
				system_("무사히 빠져나왔다. ");
				Sleep(Story);
				break;
			}
			else if (rn == 1)
			{
				system_("힘겹게 빠져나왔다. ");
				Sleep(Story);
				break;
			}
			else
			{
				system_("급하게 뛰쳐나왔다..... ");
				Sleep(Story);
				break;
			}
		}
		break;
	case 10: //스마트팜 스토리 케이스
		gotoxyP(5, 34, "여기는 스마트팜 ! ");
		Sleep(Story);
		AQC();
		system_("농작물을 키울 수 있습니다.");
		Sleep(Story);
		AQC();
		system_("농작물을 키우시겠습니까?");
		w = 1;
		while (w) 
		{
			gotoxyP(5, 36, "1. 예");
			gotoxyP(5, 37, "2. 아니요");
			gotoxy(5, 39);
			scanf("%d", &n);
			w = Is_it_right_num(n,2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			rn = rand() % 6 + 1; //농작물이 랜덤으로 나옵니다.
			system_("농작물을 키우는 중입니다.......");
			Sleep(Story);
			AQC();
			if (rn == 1)
			{
				system_("토마토가 자랐습니다");
				Sleep(Story);
				AQC();
				system_("남승완 선생님께 칭찬받습니다.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "남승완 선생님 : 토마토가 잘 자랐구먼");
				Sleep(Story);
				AQC();
				closeness_up(13, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 2)
			{
				system_("당근이 자랐습니다");
				Sleep(Story / 2);
				AQC();
				system_("남승완 선생님께 칭찬받습니다.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "남승완 선생님 : 당근이 잘 자랐구먼");
				Sleep(Story / 2);
				AQC();
				closeness_up(13, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 3)
			{
				system_("고구마가 자랐습니다");
				Sleep(Story / 2);
				AQC();
				system_("남승완 선생님께 칭찬받습니다.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "남승완 선생님 : 고구마가 잘 자랐구먼");
				Sleep(Story);
				AQC();
				closeness_up(13, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 4)
			{
				system_("감자가 자랐습니다");
				Sleep(Story / 2);
				AQC();
				system_("남승완 선생님께 칭찬받습니다.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "남승완 선생님 : 감자가 잘 자랐구먼");
				Sleep(Story);
				AQC();
				closeness_up(13, 10, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 5)
			{
				system_("시금치가 자랐습니다");
				Sleep(Story / 2);
				AQC();
				system_("남승완 선생님께 칭찬받습니다.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "남승완 선생님 : 시금치가 잘 자랐구먼");
				Sleep(Story);
				AQC();
				closeness_up(13, 20, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (rn == 6)
			{
				system_("산삼이 자랐습니다");
				Sleep(Story / 2);
				AQC();
				system_("남승완 선생님께 칭찬받습니다.");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "남승완 선생님 : 산삼이 잘 자랐구먼 !!");
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
			system_("스마트팜을 그냥 지나칩니다");
			Sleep(Story);
			AQC();
			break;
		}
		break;
	case 11: //이택주 스토리 케이스
		gotoxyP(5, 34, "여기는 이택주 선생님이 북치고 장구치며 생활하시는 공간입니다 ! ");
		PlaySound(TEXT("LeeT.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 31);
		Assistant_Text_clear();
		gotoxyP(5, 34, "이택주 선생님께서 연주를 하시려고 합니다");
		Sleep(Story);
		AQC();
		system_("노래를 맞춰야만 합니다 !");
		Sleep(Story / 2);
		n = print_Song(); //노래 맞추기 미니 게임 불러오기
		Board_Middle_clear();
		Assistant_Text_clear();
		if (n == 0)
		{
			gotoxyP(5, 34, "이택주 선생님 : 감점이다");
			PlaySound(TEXT("LeeT.wav"), 0, SND_FILENAME | SND_ASYNC);
			Sleep(Story);
			AQC();
			closeness_down(Now_Point, 10, turnplayer);
			Sleep(Story);
			break;
		}
		else
		{
			gotoxyP(5, 34, "이택주 선생님 : 맞았단다 ! ");
			Sleep(Story);
			AQC();
			rn = rand() % 4 + 1;
			closeness_up(Now_Point, rn*10, turnplayer);
			Sleep(Story);
			break;
		}
		////노래맞추기/////////
		break;
	case 12: //최하은 선생님 스토리 케이스
		gotoxyP(5, 34, "여기는 최하은 선생님의 실험 공간입니다. ");
		PlaySound(TEXT("ChoeH.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		setcolor(32, 31);
		AQC();
		setcolor(32, 7);
		if(C12_event++ <1)
			gotoxyP(5, 34, "방금 뭔가 하나 터졌군요!  소리가 꽤나 큽니다");
		else
			gotoxyP(5, 34, "또 뭔가 하나 터졌군요 ! 소리가 아까보다 더 큽니다");
		Sleep(Story);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 선생님께 달려가본다.");
			gotoxyP(5, 37, "2. 화재 싸이렌 종을 누르러 간다.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1)
		{
			system_("선생님, 괜찮으신가요????");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "최하은 선생님 : 폭발하는 소리만 컸지, 아무일도 없었어~");
			Sleep(Story);
			AQC();
			system_("그렇다.");
			Sleep(Story / 3);
			system_("아무일도 없었다.");
			Sleep(Story);
			break;
		}
		if (n == 2)
		{
			system_("싸이렌이 울렸습니다.");
			Sleep(Story);
			system_("자동장치로 인해, 인근 소방서에서 자동신고접수가 되었습니다.");
			Sleep(Story + 1500);
			system_("소리만 컸었지 사실, 디미고에서는 아무일도 일어나지 않았습니다.");
			Sleep(Story + 1500);
			system_("무단 신고죄로 당신은 퇴학처리됩니다");
			Sleep(Story);
			player_Talk(turnplayer, "아니 무슨 말도 안ㄷ.....");
			Sleep(Story);
			system_("억울해하지마세요. 게임입니다.하하");
			Sleep(Story);
			Game_over = 1; // 이 변수를 건드리면 Game_Finished 함수 호출 여부를 결정해줍니다.
			break;
		}
		break;
	case 13: //남승완 선생님 스토리 케이스
		setcolor(32, 31);
		gotoxyP(5, 34, "여기는 남승완 선생님의 미술실입니다.");
		Sleep(Story);
		Assistant_Text_clear();
		if (C13_event++ == 0)
			system_("아 지금은 당구를 치러 나가셨나봅니다 . ");
		else
			system_("아직도 당구를 치고 계신가 봅니다. ");
		Sleep(Story);
		setcolor(32, 31);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			system_("무엇을 하시겠습니까? ");
			Sleep(Story/3);
			gotoxyP(5, 36, "1. 남승완 선생님 책상을 뒤져본다. ");
			gotoxyP(5, 37, "2. 그냥 나간다.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1) //선택지 1
		{
			player_Talk(turnplayer, "미술실 책상을 뒤져봐야겠다. ");
			Sleep(Story);
			Assistant_Text_clear();
			gotoxyP(5, 34, " ( 뒤적 뒤적 ) ");
			Sleep(Story);
			AQC();
			rn = rand() % 3;
			if (rn == 0)
			{
				system_("선생님의 미술 작품이 나왔다.");
				Sleep(Story);
				AQC();
				system_("추상화를 그리신 듯 한 모습이다.");
				Sleep(1000);
				AQC();
				gotoxyP(5, 35, "그림을 보니 아이디어는 굉장히 좋으신 듯하다. ");
				Sleep(1000);
				AQC();
				gotoxyP(5, 36, "정성은 ..... 급하게 그리신듯 하다 .");
				Sleep(Story+1000);
				Assistant_Text_clear();
			}
			else if (rn == 1)
			{
				system_("선생님이 아끼시는 맥북이 나왔다. ");
				Sleep(Story);
				AQC();
				system_("굉장히 비싸 보인다. ");
				Sleep(Story);
				AQC();
				system_("탐나긴 하지만 ... 그냥 나둬야 겠다. ");
				Sleep(Story);
				Assistant_Text_clear();
				Sleep(500);
			}
			else
			{
				system_("학생 지도 일지가 있다. ");
				Sleep(Story);
				AQC();
				// 지도 일지 가운데 표시
			}
			system_("이정도 봤으면 나가야겠다.. ");
			Sleep(Story/3);
			break;
		}
		else // 선택지 2
		{
			system_("무사히 빠져나왔다.");
			Sleep(Story / 2);
			break;
		}
		break;
	case 14: //김재영 선생님 스토리 케이스
		system_(" 여기는 김재영 선생님이 계신 곳입니다. ");
		PlaySound(TEXT("KimJ.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		Assistant_Text_clear();
		system_(" 왠지 이곳에 있으면 정신이 희미해집니다. ");
		Sleep(Story);
		AQC();
		system_(" 저기 앞에 김재영 선생님의 뒷모습이 보입니다. ");
		Sleep(Story);
		AQC();
		w = 1;
		while (w)
		{
			system_(" 무엇을 하시겠습니까? ");
			gotoxyP(5, 36, "1. 말을 걸어본다. ");
			gotoxyP(5, 37, "2. 말을 걸어본다. ");
			gotoxyP(5, 38, "3. 말을 걸어본다. ");
			scanf("%d", &n);
			w = Is_it_right_num(n, 3);
		}
		Assistant_Text_clear();
		if (C14_event++ == 0) {
			gotoxyP(5, 34, "김재영 선생님 : 신코코신.... 코코 신신. ....... ");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "김재영 선생님 : 엉 그래 ~ 무슨 일 이니?");
		}
		else if (C14_event++ == 1) {
			gotoxyP(5, 34, "김재영 선생님 : 뭐야 왜 또 물어보는거야 ~?");
		}
		else if (C14_event++ >= 2) {
			gotoxyP(5, 34, "김재영 선생님 : 뭐야 귀찮게 ~ ");
		}
		Sleep(Story);
		w = 1;
		while (w)
		{
			gotoxyP(5, 36, "1. 지금 뭐하세요?");
			gotoxyP(5, 37, "2. 쌤 저랑 놀아요 !");
			gotoxy(5, 38); scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			gotoxyP(5, 34, "김재영 선생님 : 너네 수학 시험 문제 만들고 있었지 ~");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "김재영 선생님 : 여긴 뭐하러 왔어 ?");
			Sleep(Story);
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. 수학 문제 내주세요 !");
				gotoxyP(5, 37, "2. 선생님 너무 멋있어요 !");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1)
			{
				player_Talk(turnplayer, "저 수학 문제 하나 내주세요 !");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "김재영 선생님 : 무슨 수학 문제는 수학 문제야 .... ~");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "김재영 선생님 : 그럴 시간에 수학 공부좀 해 ~");
				Sleep(500);
				gotoxyP(21, 35, "맨날 공부는 나만 하고");
				Sleep(500);
				gotoxyP(21, 36, "매년 나만 똑똑해져, 나만 ~!!");
				Sleep(Story);
				Assistant_Text_clear();
				player_Talk(turnplayer, "알았어요,, 수학 공부 하러 갈게요. ");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "그래 ~ 좋은 생각이야 ~");
				Sleep(Story);
				AQC();
				rn = rand() % 2 + 1;
				closeness_up(Now_Point, rn*10, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				gotoxyP(5, 34,"김재영 선생님 : 아이 거참 ㅎㅎㅎ");
				Sleep(Story/3);
				gotoxyP(21, 35, "나도 알고 있어 ~");
				Sleep(Story / 2);
				Assistant_Text_clear();
				system_("기분이 굉장히 좋아 보이신다. ");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 50, turnplayer);
				Sleep(Story);
				break;
			}
		}
		else if (n == 2)
		{
			gotoxyP(5, 34, "김재영 선생님 : 놀긴 뭘 놀아 ~");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "김재영 선생님 : 나 지금 바빠 ~ 저기 가서 너 혼자 놀아 !");
			Sleep(Story);
			AQC();
			system_("그래도 기분은 좋아 보이신다.");
			Sleep(Story);
			AQC();
			closeness_up(Now_Point, 50, turnplayer);
			Sleep(Story);
			break;
		}
		break;
	case 15: //전유원 선생님 테스트 케이스
		sprintf(English_T, "안녕 %s ~ !", player[turnplayer - 1].name);
		PlaySound(TEXT("JunY1.wav"), 0, SND_FILENAME | SND_ASYNC);
		gotoxyP(5, 34, English_T);
		Sleep(Story);
		system_("선생님께서 기분이 좋아보이신다.");
		Sleep(Story);
		AQC();
		w = 1;
		while (w)
		{
			Assistant_Text_clear();
			gotoxyP(5, 34, "전유원 선생님 : 무슨 일이니 ~ ?");
			Sleep(Story);
			gotoxyP(5, 36, "1. 영어 단어 책 잃어버렸어요 !");
			gotoxyP(5, 37, "2. 그냥 심심해서 와봤어요 !");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			gotoxyP(5, 34, "전유원 선생님 : 뭐라고 ?! 그걸 왜 잃어 버려 !");
			PlaySound(TEXT("JunY2.wav"), 0, SND_FILENAME | SND_ASYNC);
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "전유원 선생님 : 오늘부터 단어 시험 보면 너는 무조건이야 !!");
			Sleep(Story);
			AQC();
			player_Talk(turnplayer, "에에 ??? 무슨 소리세요 ???");
			Sleep(Story);
			AQC();
			system_("아무래도 굉장히 큰일이 난거같다.. ");
			Sleep(Story);
			break;
		}
		else
		{
			rn = rand() % 2;
			if(rn == 0)
			{
				gotoxyP(5, 34, "전유원 선생님 : 어머, 호호호호");
				Sleep(Story);
				AQC();
				gotoxyP(21, 34, "사탕 하나 줄게 ~ 이거 먹고 가렴 ~");
				Sleep(Story);
				AQC();
				system_("사탕을 하나 받았다 !");
				Sleep(Story);
				Board_Middle_clear();
				AQC();
				player_Talk(turnplayer, "감사합니다 ~~!!");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 40, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				gotoxyP(5, 34, "전유원 선생님 : 어머, 호호호호");
				Sleep(Story);
				gotoxyP(21, 34, "그러면 노트북 하나만 빌려줄수 있겠니?");
				gotoxyP(21, 35, "다음시간에 수업을 들어가야 해서 ~");
				Sleep(Story);
				Assistant_Text_clear();
				system_("노트북을 빌려드렸다.");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "전유원 선생님 : 정말로 고마워 ~~~!!");
				Sleep(Story);
				AQC();
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
		}
		break;
	case 16: // 이재민 선생님 스토리 케이스
		gotoxyP(5, 34, "여기는 이재민 선생님의 축구 교실입니다 !");
		PlaySound(TEXT("LeeJ2.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		gotoxyP(5, 34, "이재민 선생님: 패쓰는~ 이렇게 하는거야~, 이해하셨죠?");
		Sleep(Story + 700);
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 네, 이해했습니다.");
			gotoxyP(5, 37, "2. 이해하지 못했습니다.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		setcolor(32, 31);
		Assistant_Text_clear();
		if (n == 1)
		{
			gotoxyP(5, 36, "이재민 선생님 : 훌륭하군~!");
			Sleep(Story / 2);
			AQC();
			system_("훌륭해서 친밀도가 상승합니다");
			Sleep(Story / 2);
			closeness_up(Now_Point, 15, turnplayer);
			Sleep(Story);
			break;
		}
		else if (n == 2)
		{
			gotoxyP(5, 34, "이재민 선생님 : 이것도 이해하지 못해서 되겠나요??");
			Sleep(Story);
			AQC();
			system_("이해하지 못해서 친밀도가 하락합니다");
			Sleep(Story);
			system_("하지만, 지금 이 순간 선생님께 좋은 패스를 주면 친밀도 하락방어가 가능합니다");
			Sleep(Story);
			w = 1;
			while (w)
			{
				gotoxyP(5, 36, "1. 도전합니다");
				gotoxyP(5, 37, "2. 도전하지 않습니다");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			setcolor(32, 31);
			Assistant_Text_clear();
			if (n == 1)
			{
				system_("플레이어의 도전정신에 감탄하여 친밀도가 상승합니다");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "이재민 선생님 : 크...");
				Sleep(Story / 2);
				AQC();
				closeness_up(Now_Point, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
			if (n == 2)
			{
				system_("도전하지 않으므로 친밀도가 하락합니다");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}
		}
		break;
	case 17: // 하성봉 선생님 테스트 케이스
		gotoxyP(5, 34, "여기는 하성봉 선생님께서 포토샵을 가르치고 계십니다.");
		Sleep(Story);
		AQC();
		gotoxyP(5, 34, "하성봉 선생님 : 니들이 말이다....");
		Sleep(Story);
		AQC();
		gotoxyP(5, 34, "하성봉 선생님 : 니들이......");
		Sleep(Story / 2);
		AQC();
		gotoxyP(5, 34, "하성봉 선생님 : 니들이...............");
		Sleep(Story);
		//여긴 AQC넣지 말기.
		w = 1;
		while (w)
		{
			setcolor(32, 31);
			gotoxyP(5, 36, "1. 하실 말씀을 까먹은듯 하다. 장난기를 발동시킨다.");
			gotoxyP(5, 37, "2. 조용히 기다린다.");
			gotoxy(5, 39);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
			Assistant_Text_clear();
		}
		if (n == 1)
		{
			gotoxyP(5, 35, "하성봉 선생님 : 니들이...............");
			Sleep(Story);
			//AQC넣지말기
			player_Talk(turnplayer, "이삼사오육칠팔구!...");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, ".하성봉 선생님 : .........");
			Sleep(Story / 2);
			AQC();
			Assistant_Text_clear();
			system_("노잼이라고 한다.");
			Sleep(Story);
			AQC();
			system_("갑분싸 상태가 되었습니다.");
			Sleep(Story / 2);
			AQC();
			system_("갑분싸 죄로 퇴학입니다.");
			Sleep(Story);
			AQC();
			player_Talk(turnplayer, "내가 노잼이라서 퇴학이라니~~~~~~.....");
			Sleep(Story);
			Game_over = 1;
			break;
		}
		if (n == 2)
		{
			gotoxyP(5, 34, "하성봉 선생님 : 니들이........ 요즘 복장 불량이 너무 많아.");
			Sleep(Story);
			AQC();
			w = 1;
			while (w)
			{
				system_("당신은 현재 복장불량입니다. 어떻게 하시겠습니까?");
				gotoxyP(5, 36, "1. 빠르게 옷을 갈아입는다.");
				gotoxyP(5, 37, "2. 주위에 친구들도 복장불량상태이므로 갈아입기보단 죄송하다고 한다.");
				gotoxy(5, 39);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1)
			{
				system_("빨리 갈아입는중..");
				Sleep(Story / 2);
				AQC();
				gotoxyP(5, 34, "하성봉 선생님 : 뭐하는 짓이야!!!!");
				Sleep(Story / 2);
				AQC();
				system_("수업시간에는 옷을 갈아입으면 안됩니다.");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 30, turnplayer);
				Sleep(Story);
				break;
			}
			else if (n == 2)
			{
				AQC();
				player_Talk(turnplayer, "죄송합니다 선생님...");
				Sleep(Story);
				AQC();
				gotoxyP(5, 36, "하성봉 선생님 : 죄송하면, 죄송할짓을 하지말았어야지!");
				Sleep(Story);
				Assistant_Text_clear();
				gotoxyP(5, 36, "하성봉 선생님 : 다음부턴 복장을 잘 관리하도록!");
				Sleep(Story);
				AQC();
				closeness_down(Now_Point, 20, turnplayer);
				Sleep(Story);
				AQC();
				break;
			}

		}
		break;
	case 18: // 정동윤 선생님 스토리 케이스
		system_("여기는 교장실, 정동윤 교장 선생님께서 학생들의 이름을 외우고 계십니다.");
		PlaySound(TEXT("JungD.wav"), 0, SND_FILENAME | SND_ASYNC);
		Sleep(Story);
		AQC();
		system_("지금 무언가 열심히 하고 계십니다.");
		Sleep(Story);
		Assistant_Text_clear();
		w = 1;
		while (w)
		{
			system_("무엇을 하시겠습니까?");
			Sleep(Story);
			gotoxyP(5, 36, "1. 아이스크림 쿠폰을 요구해본다.");
			gotoxyP(5, 37, "2. 그냥 간다.");
			gotoxy(5, 38);
			scanf("%d", &n);
			w = Is_it_right_num(n, 2);
		}
		Assistant_Text_clear();
		if (n == 1)
		{
			player_Talk(turnplayer, "선생님 저 아이스크림 사주세요 ! ");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "정동윤 교장 선생님 : 아이스크림 ? 갑자기 무슨 아이스크림 ?" );
			Sleep(Story);
			AQC();
			player_Talk(turnplayer, "선생님 아이스크림 쿠폰 많이 갖고 계시잖아요 ~ ");
			Sleep(Story);
			AQC();
			gotoxyP(5, 34, "정동윤 교장 선생님 : 무슨 소리야 ~ 누가 그래 ");
			gotoxyP(29, 35, "그런거 없어 ~");
			Sleep(Story);
			w = 1;
			Assistant_Text_clear();
			while (w)
			{
				gotoxyP(5, 36, "1. 그러지 말고 저 하나만 주세요");
				gotoxyP(5, 37, "2. 에이 거짓말 ~");
				gotoxy(5, 38);
				scanf("%d", &n);
				w = Is_it_right_num(n, 2);
			}
			Assistant_Text_clear();
			if (n == 1)
			{
				player_Talk(turnplayer, "그러지 말고 저 하나만 주세요 !");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "정동윤 교장 선생님 : 어헛 그런거 없다니까 ~");
				Sleep(Story);
				AQC();
				system_("없다고 그러시면서 주머니에 무언가를 넣어주셨다.");
				Sleep(Story);
				AQC();
				Sleep(500);
				system_("아이스크림 쿠폰을 얻었다 ! ");
				Sleep(Story);
				closeness_up(Now_Point, 20, turnplayer);
				Sleep(Story);
				break;
			}
			else
			{
				player_Talk(turnplayer, "에이 거짓말 ~");
				Sleep(Story);
				AQC();
				gotoxyP(5, 34, "정동윤 교장 선생님 : 허허 거참 ..");
				Sleep(Story);
				AQC();
				system_("없는 것처럼 연기 하시더니 주머니에 무언가를 넣어주셨다.");
				Sleep(Story);
				AQC();
				Sleep(500);
				system_("아이스크림 쿠폰을 얻었다 ! ");
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
				system_("무사히 빠져나왔다 !");
				Sleep(Story);
				break;
			}
			else
			{
				system_("??? : 너 뭐야 !");
				Sleep(Story);
				AQC();
				system_(" 낯선 이에게 잡혀버렸다. ");
				Sleep(Story);
				AQC();
				Sleep(Story / 3);
				system_(" 퇴학 당했다... !");
				Sleep(Story+1000);
				Game_over = 1;
				break;
			}
		}
		break;
	   case 19: // 정희범 선생님 스토리 케이스
		   gotoxyP(5, 34, "여기는 정희범 선생님께서 음료수 박스를 옮기고 계십니다 !");
		   PlaySound(TEXT("JungH.wav"), 0, SND_FILENAME | SND_ASYNC);
		   Sleep(Story);
		   AQC();
		   gotoxyP(5, 34, "핫산 일하자!");
		   Sleep(Story);
		   system_("당신은 정희범선생님의 핫산이 되었습니다.");
		   Sleep(Story);
		   AQC();
		   w = 1;
		   while (w)
		   {
			   gotoxyP(5, 34, "정희범 선생님 : 이번 디미고 음악행사 때 봉사할 핫산을 구한다. 할사람?");
			   gotoxyP(5, 36, "1. 제가 하겠습니다!!");
			   gotoxyP(5, 37, "2. 진행중인 동아리프로젝트가 있어서 다음에 참여하겠습니다.");
			   gotoxy(5, 38);
			   scanf("%d", &n);
			   w = Is_it_right_num(n, 2);
		   }
		   Assistant_Text_clear();
		   if (n == 1)
		   {
			   gotoxyP(5, 34, "정희범 선생님 : 음... 그래. 훌륭하군!");
			   Sleep(Story);
			   AQC();
			   gotoxyP(5, 34, "정희범 선생님 : 강당으로 음료수 박스 좀 옮겨주면 좋겠다.");
			   Sleep(Story);
			   AQC();
			   player_Talk(turnplayer, "네, 알겠습니다!!");
			   Sleep(Story / 2);
			   AQC();
			   closeness_up(Now_Point, 30, turnplayer);
			   Sleep(Story);
			   Assistant_Text_clear();
			   break;
		   }
		   else if (n == 2)
		   {
			   system_("핫산에서 방출당했습니다");
			   Sleep(Story / 2);
			   AQC();
			   player_Talk(turnplayer, "???????");
			   Sleep(Story / 3);
			   AQC();
			   system_("억울해 하지마세요. 게임입니다.하하");
			   Sleep(Story);
			   Assistant_Text_clear();
			   closeness_down(Now_Point, 20, turnplayer);
			   Sleep(Story);
			   break;
		   }
		   break;
   }
}