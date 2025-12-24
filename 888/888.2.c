#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 15

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
int food_x, food_y;
int score = 0;
int game_over = 0;
char direction = 'd';

char map[HEIGHT][WIDTH];

void init_terminal() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void restore_terminal() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void init_map() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = ' ';
            }
        }
    }
}

void generate_food() {
    do {
        food_x = rand() % (WIDTH - 2) + 1;
        food_y = rand() % (HEIGHT - 2) + 1;
    } while (map[food_y][food_x] != ' ');
    map[food_y][food_x] = '*';
}

void init_snake() {
    head = (Node*)malloc(sizeof(Node));
    head->x = WIDTH / 2;
    head->y = HEIGHT / 2;
    head->next = NULL;
    tail = head;
    map[head->y][head->x] = 'O';
}

void draw() {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
    printf("Use w/a/s/d to move, q to quit\n");
}

void move_snake() {
    int new_x = head->x;
    int new_y = head->y;

    switch (direction) {
        case 'w': new_y--; break;
        case 's': new_y++; break;
        case 'a': new_x--; break;
        case 'd': new_x++; break;
    }

    if (new_x < 0 || new_x >= WIDTH || new_y < 0 || new_y >= HEIGHT) {
        game_over = 1;
        return;
    }

    char target = map[new_y][new_x];
    if (target == '#') {
        game_over = 1;
        return;
    }

    if (target == 'O') {
        game_over = 1;
        return;
    }

    Node* new_head = (Node*)malloc(sizeof(Node));
    new_head->x = new_x;
    new_head->y = new_y;
    new_head->next = head;
    head = new_head;
    map[new_y][new_x] = 'O';

    if (target == '*') {
        score++;
        generate_food();
    } else {
        map[tail->y][tail->x] = ' ';
        Node* temp = tail;
        Node* prev = NULL;
        Node* current = head;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }
        tail = prev;
        tail->next = NULL;
        free(temp);
    }
}

int main() {
    srand(time(NULL));
    init_terminal();
    init_map();
    init_snake();
    generate_food();
    draw();

    while (!game_over) {
        char ch = getchar();
        
        if (ch == 'q') break;
        
        if ((ch == 'w' && direction != 's') ||
            (ch == 's' && direction != 'w') ||
            (ch == 'a' && direction != 'd') ||
            (ch == 'd' && direction != 'a')) {
            direction = ch;
            move_snake();
            draw();
        }
    }

    restore_terminal();
    system("clear");
    printf("Game Over! Final Score: %d\n", score);
    
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

