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
  system("CLEAR");
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
  int posX = 0;
  int posY = 0;

  vector<vector<Organism> >::iterator x;
  vector<Organism>::iterator y;
  for (x = _board.begin() + 1; x != _board.end() - 1; ++x)
  {
    posX = (x - _board.begin());
    for (y = x->begin() + 1; y != x->end() - 1; ++y)
    {
      posY = (y - x->begin());
      //cout << countOrganisms(posX, posY) << ":";
      if ((*y == NONE) && (countOrganisms(posX, posY) == 3))
      {
        //set to grow
        //cout << "grow at X:" << posX << " Y:" << posY << endl;
        *y = GESTATING;
      }
      else if ((*y == LIVING) && (countOrganisms(posX, posY) < 2))
      {
        //set to dieing
        //cout << "die due to lonely at X:" << posX << " Y:" << posY << endl;
        *y = DYING;
      }
      else if ((*y == LIVING) && (countOrganisms(posX, posY) >= 4))
      {
        //set to dieing
        //cout << "die due to crowding at X:" << posX << " Y:" << posY << endl;
        *y = DYING;
      }
    }
    cout << endl;
  }
  _generation++;
}


void board::cleanup()
{
  vector<vector<Organism> >::iterator x;
  vector<Organism>::iterator y;
  for (x = _board.begin() + 1; x != _board.end() - 1; ++x)
  {
    for (y = x->begin() + 1; y != x->end() - 1; ++y)
    {
      if (*y == GESTATING)
      {
        *y = LIVING;
      }
      else if (*y == DYING)
      {
        *y = NONE;
      }
    }
  }
}


int board::countOrganisms(int cRow, int cCol)
{
  int neighborcount = 0;

  for (int x = -1; x < 2; x++)
  {
    for (int y = -1; y < 2; y++)
    {
      // cout << "x:" << x << " y:" << y << endl;
      if ((_board[cRow + x][cCol + y] == LIVING) || (_board[cRow + x][cCol + y] == DYING))
      {
        if (x == 0 && y == 0)
        {
          continue;
        }
        neighborcount++;
      }
    }
  }
  return neighborcount;
}
