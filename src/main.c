#include "minesweeper.h"

int get_mode(void)
{
    int     mode = 0;

    printw(MENU EASY MEDIUM HARD PERS EXIT);
    refresh();
    mode = getch();
    while (mode < '1' || mode > '5')
    {
        printw(INVALID "Read: %c\n", (char)mode);
        refresh();
        mode = getch();
    }
    return(mode - '0');
}

void    init_board(t_board *b, int row, int col, int mines)
{
    b->row = row;
    b->col = col;
    b->mines = mines;
    b->tiles = row * col - mines;
}

void    pers_mode(t_board *b)
{
    char    str[3];

    printw(REQBOX REQMINE FORMAT);
    refresh();
    printw("Please, enter the number of rows (min 2, max 30):");
    getstr(str);
    b->row = atoi(str);
    printw("Please, enter the number of columns (min 2, max 30):");
    getstr(str);
    b->col = atoi(str);
    printw("Please, enter the number of mines (min 1):");
    getstr(str);
    b->mines = atoi(str);
    if ((b->row < 2 && b->row > 30) || (b->col < 2 && b->col > 30)
        || (b->mines < 1 && b->mines > b->row * b->col))
    {
        printw(INVALID);
        refresh();
    }
    return ;
}



int main(void)
{
    t_board b;
    t_box   **game;

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();

    printw(WELCOME);
    refresh();
    switch (get_mode())
    {
        case 1:
        {
            init_board(&b, 8, 8, 10);
            break ;
        }
        case 2:
        {
            init_board(&b, 16, 16, 40);
            break ;
        }
        case 3:
        {
            init_board(&b, 16, 30, 99);
            break ;
        }
        case 4:
        {
            pers_mode(&b);
            break ;
        }
        default:
            return (printw(BYE), refresh(), endwin(), 0);
    }
    game = create_map(&b);
    place_mines(game, &b);
    print_map(game, &b, 1);
    while (1)
    {
        if ((char)getch() == 'q')
            return (endwin(), 0);
    }
    endwin();
    return (0);
    play_game(game, &b);
    free_box(game, b.row);
    endwin();
    return (0);
}