#include "minesweeper.h"

static char *COLOR[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, FLAG, BOMB, UNKNOWN};

void    print_map(t_box **game, t_board *b)
{
    ft_printf("    [00]");
    for (int i = 1; i < b->col; i++)
    {
        if (i < 10)
            ft_printf("[0%d]", i);
        else
            ft_printf("[%d]", i);
    }
    ft_printf("\n");
    for (int i = 0; i < b->row; i++)
    {
        if (i < 10)
            ft_printf("[0%d]  ", i);
        else
            ft_printf("[%d]  ", i);
        for (int j = 0; j < b->col; j++)
        {
            if (game[i][j].value == -1)
                ft_printf(COLOR[10]);
            else
                ft_printf(COLOR[game[i][j].value]);
        }
        ft_printf("\n");
    }
}

void    print_game(t_box **game, t_board *b)
{
    ft_printf("    [00]");
    for (int i = 1; i < b->col; i++)
    {
        if (i < 10)
            ft_printf("[0%d]", i);
        else
            ft_printf("[%d]", i);
    }
    ft_printf("\n");
    for (int i = 0; i < b->row; i++)
    {
        if (i < 10)
            ft_printf("[0%d]  ", i);
        else
            ft_printf("[%d]  ", i);
        for (int j = 0; j < b->col; j++)
        {
            if (game[i][j].flag == true)
                ft_printf(COLOR[9]);
            else if (game[i][j].print == false)
                ft_printf(COLOR[11]);
            else
                ft_printf(COLOR[game[i][j].value]);
        }
        ft_printf("\n");
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