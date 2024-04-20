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

static int *check_coord(char **coord, int *id)
{
    if (!coord || !coord[1])
        return (NULL);
    for (int i = 0; i < 2; i++)
    {
        id[i] = ft_atoi(coord[i]);
        if (coord[i][0] != '0' && !id)
            return (NULL);
    }
    return (id);
}

void    print_zero(t_box **game, int rr, int rc, t_board *b)
{
    if (game[rr][rc].value)
        game[rr][rc].print = true;
    if (game[rr][rc].print == true)
        return ;
    game[rr][rc].print = true;
    ft_printf("print_zero: rr %d rc %d\n", rr, rc);
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

static int  get_move(t_box **game, char *move, t_board *b)
{
    char    **input = NULL;
    int     i = 0;
    int     id[2];

    input = ft_split(move, ' ');
    free(move);
    if (!input)
        exit(ft_dprintf(2, MEM));
    if (!ft_strncmp(input[0], "f", 2))
        i = 1;
    if (!check_coord(&input[i], id))
        return (ft_printf(INVALID));
    free(input);
    if (i)
        game[id[0]][id[1]].flag = !game[id[0]][id[1]].flag;
    else if (game[id[0]][id[1]].value == -1)
        return (-1);
    else if (game[id[0]][id[1]].value == 0)
        print_zero(game, id[0], id[1], b);
    else
        game[id[0]][id[1]].print = true;
    return (0);
}

void    play_game(t_box **game, t_board *b)
{
    char    *read;

    print_game(game, b);
    while (1)
    {
        ft_printf("To place a flag, introduce: f <row> <col>\n");
        ft_printf("To uncover a tile, introduce: <row> <col>\n");
        read = get_next_line(0);
        if (!read)
            exit(ft_dprintf(2, MEM));
        if (get_move(game, read, b) == -1)
        {
            ft_printf("You exploded!\n");
            print_map(game, b);
            exit(0);
        }
        print_game(game, b);
    }
}