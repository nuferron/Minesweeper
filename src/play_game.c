#include "minesweeper.h"

static int *check_coord(t_board *b, char **coord, int *id)
{
    if (!coord || !coord[1] || (coord[2] && coord[2][0] != '\n'))
        return (NULL);
    for (int i = 0; i < 2; i++)
    {
        id[i] = ft_atoi(coord[i]);
        if (coord[i][0] != '0' && !id[i])
            return (NULL);
    }
    if (id[0] >= b->row || id[0] < 0 || id[1] >= b->col || id[1] < 0)
        return (NULL);
    return (id);
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
    if (!check_coord(b, &input[i], id))
        return (free_mat(input), ft_printf(INVALID));
    free_mat(input);
    if ((game[id[0]][id[1]].flag && !i) || game[id[0]][id[1]].print)
        return (0);
    if (i)
        game[id[0]][id[1]].flag = !game[id[0]][id[1]].flag;
    else if (game[id[0]][id[1]].value == -1)
        return (-1);
    else if (game[id[0]][id[1]].value == 0)
        print_zero(game, id[0], id[1], b);
    else
    {
        game[id[0]][id[1]].print = true;
        b->tiles--;
    }
    return (0);
}

void    play_game(t_box **game, t_board *b)
{
    char    *read;

    while (1)
    {
        print_game(game, b);
        ft_printf(PUTFLAG UNCOVER);
        read = get_next_line(0);
        if (!read)
            exit(ft_dprintf(2, MEM));
        if (get_move(game, read, b) == -1)
        {
            ft_printf(YELLOW LOST RESET);
            print_map(game, b, 0);
            return ;
        }
        if (!b->tiles && ft_printf(YELLOW WIN RESET))
        {
            print_map(game, b, 1);
            return ;
        }
    }
}