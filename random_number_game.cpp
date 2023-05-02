#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int up_down[10] = {};
int win_lose_stack[100] = {};
int win = 0;
int win_stack = 0;
int lose = 0;
int lose_stack = 0;
int game_attempt = 0;
int last_chance;

void game(int life_num, int rand_num) {
	int user_num[100] = {};
	int attempt=0;
	for(int i=0;i<life_num;i++) {
		last_chance = life_num - 1;
		if(i == last_chance) {
			system("cls");
			for(int i = 0;i<attempt;i++) {
				if(up_down[i] == 1) {
					printf("%d번째 시도 : UP\n당신이 시도한 숫자 : %d\n",i+1,user_num[i]);
				} else if(up_down[i] == 0){
					printf("%d번째 시도 : DOWN\n당신이 시도한 숫자 : %d\n",i+1,user_num[i]);
				}
			}
			printf("=================================\n");
			fflush(stdin);			
			int exit = getchar();
			if(exit == '\n') {
				system("cls");	
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("마지막 순서 입니다.\n 신중하게 선택하세요!!\n");
			printf("숫자를 입력하라... : ");
			scanf("%d", &user_num[i]);
		} else {
			printf("무슨 숫자일까요? : ");
			scanf("%d", &user_num[i]);
		}
		if(user_num[i] >= 1 && user_num[i] <= 100) {
			
			if(user_num[i] == rand_num) {
				printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(2300);
				system("cls");
				printf("축하합니다!!!\n숫자를 맞췄습니다!!");
				win_lose_stack[game_attempt] = 1;
				game_attempt++;
				win++;
				Sleep(2000);
				system("cls");
				return;
			} 
			if(last_chance != i) {
				if (user_num[i] < rand_num) {
					printf("UP\n");
					up_down[i] = 1;
					attempt++;
					Sleep(2000);
					system("cls");
				} else if (user_num[i] > rand_num) {
					printf("Down\n");
					up_down[i] = 0;
					attempt++;
					Sleep(2000);
					system("cls");
				}
			}
			if(last_chance != i) {
				for(int i = 0;i<attempt;i++) {
					if(up_down[i] == 1) {
						printf("%d번째 시도 : UP   당신이 시도한 숫자 : %d\n",i+1,user_num[i]);
					} else if(up_down[i] == 0){
						printf("%d번째 시도 : DOWN\n당신이 시도한 숫자 : %d\n",i+1,user_num[i]);
					}
				}	
				printf("=================================\n");			
			}
		}
		else {
			printf("다시 입력해주세요!!!\n");
			user_num[i] = 0;
			fflush(stdin);
			int exit = getchar();
			if(exit == '\n') {
				system("cls");	
			}
			i--;
		} 
	}
	win_lose_stack[game_attempt] = 0;
	game_attempt++;
	lose++;
	printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(2300);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("아 아쉽군요... 틀렸습니다.\n목숨이 모두 소진되었습니다.\n\n정답은 %d 였습니다!!",rand_num);
	fflush(stdin);
	int exit = getchar();
	if(exit == '\n') {
		system("cls");	
	}
	return;
}
int lifeSelect() {
	int life;
	while(1) {
		printf("목숨의 갯수를 입력해주세요(3~10) : ");
		scanf("%d",&life);
		if(life > 10 || life <3) {
			system("cls");
			printf("정상적인 목숨의 갯수를 선택하여 주세요!!!\n");
			Sleep(2000);
			system("cls");
		} else {
			system("cls");
			return life;
		}
	}

}
void gamelog() {
	fflush(stdin);
	printf("게임을 시도한 횟수 : %d\n",game_attempt);
	printf("승패 : %d승 %d패\n",win,lose);
	for(int i=0;i<game_attempt;i++) {
		if(win_lose_stack[game_attempt] == 1) {
			win_stack++;
			if(win_lose_stack[game_attempt] == 0) {
				win_stack = 0;
			} 
		}
		else if(win_lose_stack[game_attempt] == 0) {
			lose_stack++;
			if(win_lose_stack[game_attempt] == 1) {
				lose_stack = 0;
			} 
		}
	} 
	printf("연승, 연패 현황 : "); 
	if(win_stack > 0) {
		printf("%d연승\n",win_stack);
	} else if(lose_stack > 0) {
		printf("%d연패\n",lose_stack);
	} else {
		printf("없음\n");
	}
	int exit = getchar();
	if(exit == '\n') {
		system("cls");
		return;	
	}
}
void event() { //10연승 일때, 10연패 일때 
	
} 
 
int main() {
	printf("C언어 UP&DOWN GAME\n");
	int life = 3;
	int select;
	int record; 
	int up, down;
	srand(time(NULL));
	int random = (rand() % 100) + 1;
	while(1) {
		printf("선택할 항목을 골라주세요(숫자)\n");
		printf("1. 게임 시작\n");
		printf("2. 목숨 갯수 선택 (현재 목숨 : %d)\n",life);
		printf("3. 기록 보기\n");
		printf("4. 게임 종료 \n");
		printf(">> ");
		scanf("%d",&select);
		switch(select) {
			case 1:
				system("cls");
				game(life,random);				
				break;
			case 2:
				system("cls");
				life = lifeSelect();			
				break;
			case 3:
				system("cls");
				gamelog();
				break; 
			case 4:
				return 0;
			default:
				printf("다시 입력해주세요!!\n");
				fflush(stdin);
				int exit = getchar();
				if(exit == '\n') {
					system("cls");	
				}
		}		

	}
} 
//승패 기능 만들기 
//마지막 시도 일때 쪼는 맛 주기 => 빨간색, 기록 삭제 
//끝나고 답 알려주기 
//초기화 기능 추가 
