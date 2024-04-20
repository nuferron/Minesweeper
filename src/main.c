#include "minesweeper.h"

int get_mode(void)
{
    int     mode = -1;
    char    *read = NULL;

    while (1)
    {
        ft_printf(MENU EASY MEDIUM HARD PERS EXIT);
        read = get_next_line(0);
        mode = ft_atoi(read);
        free(read);
        if (mode > 0 && mode <= 5)
            break ;
        ft_printf(INVALID);
    }
    return(mode);
}

void    init_board(t_board *b, int row, int col, int mines)
{
    b->row = row;
    b->col = col;
    b->mines = mines;
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
            b->row = ft_atoi(values[0]);
            b->col = ft_atoi(values[1]);
            b->mines = ft_atoi(values[2]);
            if (b->row > 1 && b->row <= 40 &&
                b->col > 1 && b->col <= 40 &&
                b->mines > 0 && b->mines < b->row * b->col)
            {
                free(values);
                break ;
            }
        }
        free(values);
        ft_printf(INVALID);
    }
}

void    print_map(t_box **game, t_board *b)
{
    for (int i = 0; i < b->row; i++)
    {
        for (int j = 0; j < b->col; j++) // array de colors, aixi queda mes automatitzat
        {
            if (game[i][j].value == -1)
                ft_printf(COLORRRR[11]);
            else
                ft_printf("%s%d ", COLORRRR[game[i][j].value], game[i][j].value);
            /*if (game[i][j].value == -1)
                ft_printf(BOMB);
            else if (game[i][j].value == 1)
                ft_printf(ONE);
            else if (game[i][j].value == 2)
                ft_printf(TWO);
            else if (game[i][j].value == 3)
                ft_printf(THREE);
            else if (game[i][j].value == 4)
                ft_printf(FOUR);
            else if (game[i][j].value == 5)
                ft_printf(FIVE);
            else if (game[i][j].value == 6)
                ft_printf(SIX);
            else if (game[i][j].value == 7)
                ft_printf(SEVEN);
            else if (game[i][j].value == 8)
                ft_printf(EIGHT);
            else
                ft_printf(ZERO);*/
        }
        ft_printf("\n");
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
    //print_game(game, &b);
    print_map(game, &b);
    ft_free_2p(game, b.row);
    return (0);
}