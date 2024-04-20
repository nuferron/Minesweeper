#include "minesweeper.h"

t_box   **create_map(t_board *b)
{
    t_box   **game = NULL;

    game = (t_box **)ft_calloc(b->row, sizeof(t_box *));
    if (!game)
        return (ft_dprintf(2, MEM), NULL);
    for (int i = 0; i < b->row; i++)
    {
        game[i] = (t_box *)ft_calloc(b->col, sizeof(t_box));
        if (!game[i])
            return (free_box(game, i), NULL);
    }
    return (game);
}

void    set_values(t_box **game, t_board *b, int rr, int rc)
{
    if (rr - 1 >= 0)
    {
        if (rc - 1 >= 0 && game[rr - 1][rc - 1].value != -1)
            game[rr - 1][rc - 1].value++;
        if (game[rr - 1][rc].value != -1)
            game[rr - 1][rc].value++;
        if (rc + 1 < b->col && game[rr - 1][rc + 1].value != -1)
            game[rr - 1][rc + 1].value++;
    }
    if (rr + 1 < b->row)
    {
        if (rc - 1 >= 0 && game[rr + 1][rc - 1].value != -1)
            game[rr + 1][rc - 1].value++;
        if (game[rr + 1][rc].value != -1)
            game[rr + 1][rc].value++;
        if (rc + 1 < b->col && game[rr + 1][rc + 1].value != -1)
            game[rr + 1][rc + 1].value++;
    }
    if (rc - 1 >= 0 && game[rr][rc - 1].value != -1)
        game[rr][rc - 1].value++;
    if (rc + 1 < b->col && game[rr][rc + 1].value != -1)
        game[rr][rc + 1].value++;
}

void    place_mines(t_box **game, t_board *b)
{
    int i = 0;
    int rr;
    int rc;

    srand(time(0));
    while (i < b->mines)
    {
        rr = rand() % (b->row);
        rc = rand() % (b->col);
        if (game[rr][rc].value != -1)
        {
            game[rr][rc].value = -1;
            i++;
        }
        set_values(game, b, rr, rc);
    }
}