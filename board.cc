#include "board.h"

board::board(int x, int y)
  : _generation(0), _col(x), _row(y), _board(y, vector<Organism> (x,NONE))
{
}


void board::createBoard()
{
}


void board::printBoard()
{
  for (int row = 0; row < _row; row++)
  {
    cout << "|";
    for (int col = 0; col < _col; col++)
    {
      if (_board[row][col] == NONE)
      {
        cout << " ";
      }
      else if (_board[row][col] == LIVING)
      {
        cout << "#";
      }
      else if (_board[row][col] == BORDER)
      {
        cout << "@";
      }
    }
    cout << "|" << endl;
  }
}
