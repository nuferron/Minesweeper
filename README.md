# Minesweeper

Minesweeper is a logic puzzle video game that consists of a grid with hidden mines. The goal is to clear the board without detonating any of those mines, with help from clues about the number of neighboring mines in each field.

This project proposes a version of minesweeper programmed in C that can be played from the terminal.

To compile the project you can simply execute `make` and then you can either use `make run` or `./minesweeper`.

In this version, you are asked to choose a game mode:
  1. Beginner (8x8 board, 10 mines)
  2. Intermediate (16x16 board, 40 mines)
  3. Expert (16x30 board, 99 mines)
  4. Personalized ([2-30]x[2-30] board, at least one mine and less mines than tiles)

Once the grid appears, you can either uncover a tile by typing its coordinates (\<row\> \<column\>), or you can place/remove a flag (f \<row\> \<column\>), which will prevent you from/allow you to uncover that tile. The game finishes when all non-mine tiles have been uncovered (you win) or when a mine is uncovered (you lose).

Have fun! 🥳
