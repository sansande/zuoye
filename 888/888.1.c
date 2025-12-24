#include <stdio.h>
#include <stdio.h>
#define ROWS 10
#define COLS 10
#define FILENAME "seats.dat"
int seats[ROWS][COLS] = {0};
void load_seats() {
	FILE *file = fopen(FILENAME,"rb");
	if (file != NULL) {
		fread(seats, sizeof(int), ROWS * COLS, file);
		fclose(file);
	}else {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				seats[i][j] = 0;
			}
		}
	}
}
void save_seats() {
	FILE *file = fopen(FILENAME,"wb");
	if (file != NULL) {
		fwrite(seats, sizeof(int), ROWS * COLS,file);
		fclose(file);
	} else {
		printf("无法保存座位状态！\n");
	}
}
void show_seats() {
	printf("当前座位状态 (□:空座，■:已售):\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (seats[i][j] == 0) {
				printf("□");
			} else {
				printf("■");
			}
		}
		printf("\n");
	}
}
void select_seats() {
	int row, col;
	printf("请输入要选的座位 (行 列):");
	scanf("%d %d", &row, &col);
	row--;
	col--;
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
		printf("输入无效！行列范围为 1-%d和 1-%d\n",ROWS,COLS);
		return;
	}
	if (seats[row][col] == 0) {
		seats[row][col] == 1;
		printf("选座成功！票价为 50 元\n");
		save_seats();
	} else {
		printf("该座位已售，请重新选座");
	}
}
int main() {
	load_seats();
	int choice;
	do {
		printf("\n===电影院选座系统===\n");
		printf("1.展示座位\n");
		printf("2.选座购票\n");
		printf("3.退出\n");
		printf("请输入序号：");
		scanf("%d",&choice);

		switch (choice) {
			case 1:
				show_seats();
				break;
			case 2:
				select_seats();
				break;
			case 3:
			       printf("退出系统，保存座位状态\n");
				save_seats();
				break;
			default:
				printf("无效操作，请重新输入\n");
		}
	} while (choice != 3);
	return 0 ;
}	
