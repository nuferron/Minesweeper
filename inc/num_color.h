#ifndef NUM_COL_H
# define NUM_COL_H

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"
#define MAGENTA "\x1B[1;38;2;255;0;116m"
#define ORANGE "\x1B[1;38;2;255;116;0m"
#define GREY "\x1B[1;38;2;116;116;116m"
#define D_GREY "\x1B[1;38;2;50;50;50m"

#define ONE BLUE "1   " RESET
#define TWO GREEN "2   " RESET
#define THREE MAGENTA "3   " RESET
#define FOUR PURPLE "4   " RESET
#define FIVE CYAN "5   " RESET
#define SIX WHITE "6   " RESET
#define SEVEN ORANGE "7   " RESET
#define EIGHT YELLOW "8   " RESET
#define FLAG RED "*   " RESET
#define ZERO D_GREY "0   " RESET
#define UNKNOWN GREY "-   " RESET
#define BOMB RED "O   " RESET

#endif