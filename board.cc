#include "board.h"

board::board(int x, int y)
  : _generation(0), _col(x), _row(y), _board(y, vector<Organism> (x, NONE))
{
}


void board::setStartingOrganism(int x, int y)
{
  _board[x][y] = LIVING;
}


void board::clearScreen()
{
  system("cls");
  system("clear");
}

void board::printBoard()
{
  for (int top = 0; top < _col + 2; top++)
  {
    cout << (char)_hr;
  }
  cout << endl;
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
