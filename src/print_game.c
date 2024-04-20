#include "minesweeper.h"

static char *COLOR[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, FLAG, BOMB, UNKNOWN};

void    print_map(t_box **game, t_board *b)
{
    write(1, "    [00]", 8);
    for (int i = 1; i < b->col; i++)
    {
        if (i < 10)
            ft_printf("[0%d]", i);
        else
            ft_printf("[%d]", i);
    }
    write(1, "\n", 1);
    for (int i = 0; i < b->row; i++)
    {
        if (i < 10)
            ft_printf("[0%d]  ", i);
        else
            ft_printf("[%d]  ", i);
        for (int j = 0; j < b->col; j++)
        {
            if (game[i][j].value == -1)
                write(1, COLOR[10], 15);
            else
                write(1, COLOR[game[i][j].value], ft_strlen(COLOR[game[i][j].value]));
        }
        write(1, "\n", 1);
    }
}

void    print_game(t_box **game, t_board *b)
{
    write(1, "    [00]", 8);
    for (int i = 1; i < b->col; i++)
    {
        if (i < 10)
            ft_printf("[0%d]", i);
        else
            ft_printf("[%d]", i);
    }
    write(1, "\n", 1);
    for (int i = 0; i < b->row; i++)
    {
        if (i < 10)
            ft_printf("[0%d]  ", i);
        else
            ft_printf("[%d]  ", i);
        for (int j = 0; j < b->col; j++)
        {
            if (game[i][j].flag == true)
                write(1, COLOR[9], 15);
            else if (game[i][j].print == false)
                write(1, COLOR[11], 29);
            else
                write(1, COLOR[game[i][j].value], ft_strlen(COLOR[game[i][j].value]));
        }
        write(1, "\n", 1);
    }
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