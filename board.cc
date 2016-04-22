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
  cout << "Current Generation:" << _generation << endl;
  cout << endl;
  cout << (char)_corner;
  for (int top = 0; top < _col; top++)
  {
    cout << (char)_topBottom;
  }
  cout << (char)_corner;
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
  cout << (char)_corner;
  for (int top = 0; top < _col; top++)
  {
    cout << (char)_topBottom;
  }
  cout << (char)_corner;
  cout << endl;
}


void board::cycle()
{
  vector < vector <Organism> >::iterator x;
  vector <Organism>::iterator y;
  for (x = _board.begin(); x != _board.end(); ++x)
  {
    for (y = x->begin(); y != x->end(); ++y)
    {
      cout << *y;
    }
    cout << endl;
  }
}


int board::countOrganisms(int cRow, int cCol)
{
  int neighborcount = 0;

  for (int x = -1; x < 2; x++)
  {
    for (int y = -1; y < 2; y++)
    {
      if ((_board[cRow + x][cCol + y] == LIVING) || (_board[cRow + x][cCol + y] == DYING))
      {
        neighborcount++;
      }
    }
  }
  return neighborcount;
}
