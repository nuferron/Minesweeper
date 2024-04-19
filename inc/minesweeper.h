#ifndef MINESWEEPER_H
# define MINESWEEPER_H

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include "messages.h"

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

#endif