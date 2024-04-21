#include "minesweeper.h"

int get_mode(void)
{
    int     mode = -1;
    char    *read = NULL;
    char    **input = NULL;

    while (1)
    {
        ft_printf(MENU EASY MEDIUM HARD PERS EXIT);
        read = get_next_line(0);
        if (!read)
            exit(ft_printf(MEM));
        input = ft_split(read, ' ');
        free(read);
        if (!input)
            exit(ft_printf(MEM));
        if (!input[1])
        {
            mode = ft_atoi(input[0]);
            free_mat(input);
            if (mode > 0 && mode <= 5)
                break ;
        }
        ft_printf(INVALID);
    }
    return(mode);
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
    char    **values = NULL;
    char    *read = NULL;

    while (1)
    {
        ft_printf(REQBOX REQMINE FORMAT);
        read = get_next_line(0);
        values = ft_split(read, ' ');
        free(read);
        if (values && values[1] && values[2])
        {
            init_board(b, ft_atoi(values[0]), ft_atoi(values[1]), ft_atoi(values[2]));
            free_mat(values);
            if (b->row > 1 && b->row <= 30 &&
                b->col > 1 && b->col <= 30 &&
                b->mines > 0 && b->mines < b->row * b->col)
                break ;
        }
        ft_printf(INVALID);
    }
}



int main(void)
{
    t_board b;
    t_box   **game;
    int     mode = 0;

    ft_printf(WELCOME);
    mode = get_mode();
    if (mode == 1)
        init_board(&b, 8, 8, 10);
    else if (mode == 2)
        init_board(&b, 16, 16, 40);
    else if (mode == 3)
        init_board(&b, 16, 30, 99);
    else if (mode == 4)
        pers_mode(&b);
    else
        return (ft_printf(BYE), 0);
    game = create_map(&b);
    place_mines(game, &b);
    play_game(game, &b);
    free_box(game, b.row);
    return (0);
}