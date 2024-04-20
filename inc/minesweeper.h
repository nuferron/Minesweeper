#ifndef MINESWEEPER_H
# define MINESWEEPER_H

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "messages.h"
#include "num_color.h"
#include <stdbool.h>
#include <time.h>

typedef struct s_board
{
    int col;
    int row;
    int mines;
}  t_board;

typedef struct s_box
{
    bool    print;
    bool    flag;
    int     value;
}   t_box;

t_box   **create_map(t_board *b);
void    ft_free_2p(t_box **ptr, int i);
void    place_mines(t_box **game, t_board *b);

#endif