#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 15

int board[BOARD_SIZE][BOARD_SIZE] = {0}; 

void drawBoard() {
    system("clear");
    printf("   ");    
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%2d ", col); 
    }
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%2d ", row); // 行号占 2 位
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case 0:  printf("+  "); break; 
                case 1:  printf("●  "); break; 
                case 2:  printf("○  "); break;
            }
        }
        printf("\n");
    }
}

int checkWin(int row, int col, int player) {
    int dirs[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (int d = 0; d < 4; d++) {
        int dx = dirs[d][0], dy = dirs[d][1];
        int count = 1;

        for (int step = 1; step < 5; step++) {
            int r = row + dx * step;
            int c = col + dy * step;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE 
                && board[r][c] == player) {
                count++;
            } else break;
        }

        for (int step = 1; step < 5; step++) {
            int r = row - dx * step;
            int c = col - dy * step;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE 
                && board[r][c] == player) {
                count++;
            } else break;
        }

        if (count >= 5) return 1; 
    }
    return 0;
}

int main() {
    int currentPlayer = 1; 
    int row, col;

    printf("=== 五子棋 - Linux 双人对战版 ===\n");
    printf("规则：黑棋（●）先下，交替落子，先连 5 子者胜！\n");
    printf("输入格式：行号 列号（范围 0~%d）\n", BOARD_SIZE-1);

    while (1) {
        drawBoard();
        printf("当前玩家：%s（%s）\n", 
               currentPlayer == 1 ? "黑棋" : "白棋", 
               currentPlayer == 1 ? "●" : "○");
        printf("请输入落子坐标（行 列）：");

        while (1) {
            if (scanf("%d %d", &row, &col) != 2) { 
                while (getchar() != '\n'); 
                printf("错误：请输入两个整数（如 3 5）！重新输入：");
                continue;
            }
            if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
                printf("错误：坐标超出范围（0~%d）！重新输入：", BOARD_SIZE-1);
                continue;
            }
            if (board[row][col] != 0) {
                printf("错误：该位置已有棋子！重新输入：");
                continue;
            }
            break;
        }

        board[row][col] = currentPlayer;

        if (checkWin(row, col, currentPlayer)) {
            drawBoard();
            printf("恭喜 %s（%s）获胜！游戏结束！\n", 
                   currentPlayer == 1 ? "黑棋" : "白棋", 
                   currentPlayer == 1 ? "●" : "○");
            break;
        }
        currentPlayer = currentPlayer == 1 ? 2 : 1;
    }

    return 0;
}
