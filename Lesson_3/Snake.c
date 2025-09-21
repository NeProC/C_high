/* Игра змейка */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <inttypes.h>
#include <unistd.h>

#define MIN_Y 2
#define DELAY ((double)0.1)
enum
{
    LEFT = 1,
    UP,
    RIGHT,
    DOWN,
    STOP_GAME = KEY_F(10)
};
enum
{
    MAX_TAIL_SIZE = 100,
    START_TAIL_SIZE = 3,
    MAX_FOOD_SIZE = 20,
    FOOD_EXPIRE_SECONDS = 10
};

/* Структура кодов управления змейкой*/
typedef struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

/* Хвост змеи */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

/* Голова змеи */
typedef struct snake_t
{
    int x;
    int y;                           /*  x y координаты змеи */
    int direction;                   /* направление */
    size_t tsize;                    /* размер хвоста */
    tail_t *tail;                    /* указатель на структуру хвоста */
    struct control_buttons controls; /* Управляющие клавиши */

} snake_t;

void initTail(tail_t[], size_t);                                /* функция инициализация хвоста */
void initHead(snake_t *, int, int);                             /* функция инициализации головы */
void initSnake(snake_t *head, size_t size, int x, int y);       /* функция инициализации змеи */
void go(struct snake_t *head);                                  /* движение головы с учетом текущего направления движения*/
void changeDirection(struct snake_t *snake, const int32_t key); /* изменение направления */
void goTail(struct snake_t *head);                              /* движение хвоста с учетом движения головы */

int main(int argc, char const *argv[])
{
    snake_t *snake = (snake_t *)malloc(sizeof(snake_t)); /* выделяем память под змейку */
    if (snake == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    initSnake(snake, START_TAIL_SIZE, 10, 10);
    initscr();            /* настраиваем терминал */
    keypad(stdscr, TRUE); /* включаем обработку клавиш */
    raw();                /* отключаем буфер */
    noecho();             /* отключаем echo */
    curs_set(FALSE);      /* отключаем курсор */
    mvprintw(0, 0, "Use control. Press F10 for exit");
    timeout(0); /* отключаем таймауты после нажатия клавишь */
    clock_t begin;
    int key_pressed = 0;
    while (key_pressed != STOP_GAME)
    {
        key_pressed = getch(); /* считываем клавишу */
        go(snake);
        goTail(snake);
        // timeout(100); /* таймаут отрисовки */
        begin = clock();
        // while ((double)(clock() - begin) / CLOCKS_PER_SEC < DELAY)
        while (((double)(clock() - begin) / CLOCKS_PER_SEC) < DELAY) /* Работает, но с timeout лучше*/
        {
        }

        changeDirection(snake, key_pressed);
    }
    free(snake->tail);
    free(snake);
    endwin();

    return 0;
}

void initTail(tail_t t[], size_t size)
{
    tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; i++)
    {
        t[i] = init_t;
    }
}

void initHead(snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = UP;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t *tail = (tail_t *)malloc(MAX_TAIL_SIZE * sizeof(tail_t *));
    if (tail == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail;
    head->tsize = size + 1;
    head->controls = default_controls;
}

void go(struct snake_t *head)
{
    char ch = '$';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);  // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
    case LEFT:
        if (head->x <= 0)
        { // Циклическое движение, чтобы не
          // уходить за пределы экрана
            head->x = max_x;
        }
        mvprintw(head->y, --(head->x), "%c", ch);
        break;
    case RIGHT:
        if (head->x >= max_x)
        {
            head->x = 0;
        }
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        if (head->y <= 1)
        {
            head->y = max_y;
        }
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        if (head->y >= max_y)
        {
            head->y = 0;
        }
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
    refresh();
}

void changeDirection(struct snake_t *snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");
    for (size_t i = head->tsize - 1; i > 0; i--)
    {
        head->tail[i] = head->tail[i - 1];
        if (head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}