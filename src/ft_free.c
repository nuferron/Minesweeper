#include "minesweeper.h"

void    free_box(t_box **ptr, int i)
{
    for (int j = 0; j <= i; j++)
        free(ptr[j]);
    free(ptr);
}

void    free_mat(char **ptr)
{
    for (int i = 0; ptr[i]; i++)
        free(ptr[i]);
    free(ptr);
}