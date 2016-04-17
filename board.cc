#include "board.h"

board::board(int x, int y): _generation(0)
{
  Organism _board[x][y] = {NONE};
}
