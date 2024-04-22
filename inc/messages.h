#ifndef MESSAGES_H
# define MESSAGES_H

#define WELCOME "Welcome to Minesweeper! 💣🚩\n"
#define MENU    "Please, enter your game mode:\n"
#define EASY    "\t(1) Beginner: 8×8 10 mines\n"
#define MEDIUM  "\t(2) Intermediate: 16×16 40 mines\n"
#define HARD    "\t(3) Expert: 16×30 99 mines\n"
#define PERS    "\t(4) Personalized\n"
#define EXIT    "\t(5) Exit\n"
#define INVALID "\nINVALID INPUT\n"
#define BYE     "See you soon!\n"
#define REQBOX  "Both rows and columns must have a minimum of 2 boxes and a maximum of 30.\n"
#define REQMINE "The number of mines must be greater than 0 and less than the number of boxes.\n"
#define FORMAT  "Please, enter your preferences in this format:\n\trow col mines\n"
#define MEM     "Error: Memory problems\n"
#define PUTFLAG "To place a flag, introduce: f <row> <col>\n"
#define UNCOVER "To uncover a tile, introduce: <row> <col>\n"
#define LOST    "Oh, no! You've exploded! Better luck next time 💀\n"
#define WIN     "Yayyy! You won! Awesome! 🥳\n"

#endif
