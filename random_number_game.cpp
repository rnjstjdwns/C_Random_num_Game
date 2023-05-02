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
					printf("%d��° �õ� : UP\n����� �õ��� ���� : %d\n",i+1,user_num[i]);
				} else if(up_down[i] == 0){
					printf("%d��° �õ� : DOWN\n����� �õ��� ���� : %d\n",i+1,user_num[i]);
				}
			}
			printf("=================================\n");
			fflush(stdin);			
			int exit = getchar();
			if(exit == '\n') {
				system("cls");	
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("������ ���� �Դϴ�.\n �����ϰ� �����ϼ���!!\n");
			printf("���ڸ� �Է��϶�... : ");
			scanf("%d", &user_num[i]);
		} else {
			printf("���� �����ϱ��? : ");
			scanf("%d", &user_num[i]);
		}
		if(user_num[i] >= 1 && user_num[i] <= 100) {
			
			if(user_num[i] == rand_num) {
				printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(2300);
				system("cls");
				printf("�����մϴ�!!!\n���ڸ� ������ϴ�!!");
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
						printf("%d��° �õ� : UP   ����� �õ��� ���� : %d\n",i+1,user_num[i]);
					} else if(up_down[i] == 0){
						printf("%d��° �õ� : DOWN\n����� �õ��� ���� : %d\n",i+1,user_num[i]);
					}
				}	
				printf("=================================\n");			
			}
		}
		else {
			printf("�ٽ� �Է����ּ���!!!\n");
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
	printf("�� �ƽ�����... Ʋ�Ƚ��ϴ�.\n����� ��� �����Ǿ����ϴ�.\n\n������ %d �����ϴ�!!",rand_num);
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
		printf("����� ������ �Է����ּ���(3~10) : ");
		scanf("%d",&life);
		if(life > 10 || life <3) {
			system("cls");
			printf("�������� ����� ������ �����Ͽ� �ּ���!!!\n");
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
	printf("������ �õ��� Ƚ�� : %d\n",game_attempt);
	printf("���� : %d�� %d��\n",win,lose);
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
	printf("����, ���� ��Ȳ : "); 
	if(win_stack > 0) {
		printf("%d����\n",win_stack);
	} else if(lose_stack > 0) {
		printf("%d����\n",lose_stack);
	} else {
		printf("����\n");
	}
	int exit = getchar();
	if(exit == '\n') {
		system("cls");
		return;	
	}
}
void event() { //10���� �϶�, 10���� �϶� 
	
} 
 
int main() {
	printf("C��� UP&DOWN GAME\n");
	int life = 3;
	int select;
	int record; 
	int up, down;
	srand(time(NULL));
	int random = (rand() % 100) + 1;
	while(1) {
		printf("������ �׸��� ����ּ���(����)\n");
		printf("1. ���� ����\n");
		printf("2. ��� ���� ���� (���� ��� : %d)\n",life);
		printf("3. ��� ����\n");
		printf("4. ���� ���� \n");
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
				printf("�ٽ� �Է����ּ���!!\n");
				fflush(stdin);
				int exit = getchar();
				if(exit == '\n') {
					system("cls");	
				}
		}		

	}
} 
//���� ��� ����� 
//������ �õ� �϶� �ɴ� �� �ֱ� => ������, ��� ���� 
//������ �� �˷��ֱ� 
//�ʱ�ȭ ��� �߰� 
