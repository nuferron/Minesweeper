#include "minesweeper.h"

static char *COLOR[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, FLAG, BOMB, UNKNOWN};

static void    print_col_id(int max)
{
    write(1, "    [00]", 8);
    for (int i = 1; i < max; i++)
    {
        write(1, "[", 1);
        if (i < 10)
            write(1, "0", 1);
        ft_printf("%d", i);
        write(1, "]", 1);
    }
    write(1, "\n", 1);
}

void    print_map(t_box **game, t_board *b, int win)
{
    print_col_id(b->col);
    for (int i = 0; i < b->row; i++)
    {
        write(1, "[", 1);
        if (i < 10)
            write(1, "0", 1);
        ft_printf("%d", i);
        write(1, "]  ", 3);
        for (int j = 0; j < b->col; j++)
        {
            if (!win && game[i][j].value == -1)
                write(1, COLOR[10], 15);
            else if (win && game[i][j].value == -1)
                write(1, COLOR[9], 15);
            else
                write(1, COLOR[game[i][j].value], ft_strlen(COLOR[game[i][j].value]));
        }
        write(1, "[", 1);
        if (i < 10)
            write(1, "0", 1);
        ft_printf("%d", i);
        write(1, "]\n", 2);
    }
    print_col_id(b->col);
}

void    print_game(t_box **game, t_board *b)
{
    print_col_id(b->col);
    for (int i = 0; i < b->row; i++)
    {
        write(1, "[", 1);
        if (i < 10)
            write(1, "0", 1);
        ft_printf("%d", i);
        write(1, "]  ", 3);
        for (int j = 0; j < b->col; j++)
        {
            if (game[i][j].flag == true)
                write(1, COLOR[9], 15);
            else if (game[i][j].print == false)
                write(1, COLOR[11], 15);
            else
                write(1, COLOR[game[i][j].value], ft_strlen(COLOR[game[i][j].value]));
        }
        write(1, "[", 1);
        if (i < 10)
            write(1, "0", 1);
        ft_printf("%d", i);
        write(1, "]\n", 2);
    }
    print_col_id(b->col);
}

void    print_zero(t_box **game, int rr, int rc, t_board *b)
{
    if (game[rr][rc].print == false)
        b->tiles--;
    if (game[rr][rc].value)
        game[rr][rc].print = true;
    if (game[rr][rc].print == true)
        return ;
    game[rr][rc].print = true;
    if (rr - 1 >= 0)
    {
        if (rc - 1 >= 0)
            print_zero(game, rr - 1, rc - 1, b);
        print_zero(game, rr - 1, rc, b);
        if (rc + 1 < b->col)
            print_zero(game, rr - 1, rc + 1, b);
    }
    if (rr + 1 < b->row)
    {
        if (rc - 1 >= 0)
            print_zero(game, rr + 1, rc - 1, b);
        print_zero(game, rr + 1, rc, b);
        if (rc + 1 < b->col)
            print_zero(game, rr + 1, rc + 1, b);
    }
    if (rc - 1 >= 0)
        print_zero(game, rr, rc - 1, b);
    if (rc + 1 < b->col)
        print_zero(game, rr, rc + 1, b);
}
