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

int findWinningMove(int player, int *row, int *col) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == 0) {        
                board[r][c] = player;      
                if (checkWin(r, c, player)) { 
                    board[r][c] = 0;       
                    *row = r; *col = c;    
                    return 1;             
                }
                board[r][c] = 0;           
            }
        }
    }
    return 0;
}

void aiMove(int player, int *row, int *col) {
    if (findWinningMove(player, row, col)) {
        return;
    }

    int enemy = 3 - player;
    if (findWinningMove(enemy, row, col)) {
        return;
    }

    int mid = BOARD_SIZE / 2;
    for (int dr = -2; dr <= 2; dr++) {
        for (int dc = -2; dc <= 2; dc++) {
            int r = mid + dr;
            int c = mid + dc;
            if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE 
                && board[r][c] == 0) {
                *row = r; *col = c;
                return;
            }
        }
    }

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == 0) {
                *row = r; *col = c;
                return;
            }
        }
    }
}

int main() {
    int currentPlayer = 1; 
    int row, col;

    printf("=== 五子棋 - 人机对战版（Linux） ===\n");
    printf("规则：您执黑棋先下，AI 执白棋后下，先连 5 子者胜！\n");
    printf("输入格式：行号 列号（范围 0~14）\n");

    while (1) {
        drawBoard(); 

        if (currentPlayer == 1) {
            printf("您的回合（黑棋 ●）：\n");
            while (1) {
                if (scanf("%d %d", &row, &col) != 2) { 
                    while (getchar() != '\n'); 
                    printf("错误：请输入两个整数（如 3 5）！重新输入：");
                    continue;
                }
                if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
                    printf("错误：坐标超出范围（0~14）！重新输入：");
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
                printf("恭喜您获胜！游戏结束！\n");
                break;
            }

        } else {
            printf("AI 思考中...\n");
            int aiRow, aiCol;
            aiMove(currentPlayer, &aiRow, &aiCol); 
            board[aiRow][aiCol] = currentPlayer;  
            printf("AI 落子：%d %d\n", aiRow, aiCol);

            if (checkWin(aiRow, aiCol, currentPlayer)) {
                drawBoard();
                printf("AI 获胜！游戏结束！\n");
                break;
            }
        }

        currentPlayer = 3 - currentPlayer; 
    }

    return 0;
}
