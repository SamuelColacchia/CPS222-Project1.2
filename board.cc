#include "board.h"

/**
 * Board constructor
 *
 * @param int x : the x distance for the board
 * @param int y : the y distance for the board
 *
 * _generation : a varialbe to keep track of the generations
 * _col : a varialbe to record the distance in the x direction
 * _row : a variable to record the distance in the y direction
 * _board : the board object that contains the organisms
 *
 */

board::board(int x, int y)
  : _generation(0), _col(x), _row(y), _board(y, vector<Organism> (x, NONE))
{
}


//TODO add @description

/**
 * Set the starting organisms
 *
 * @param int x : the x position for a starting organisms
 * @param int y : the y position for a starting organisms
 *
 */
void board::setStartingOrganism(int x, int y)
{
  _board[x][y] = LIVING;
}


//TODO add @description

/**
 *  Attempt to clear the screen
 */
void board::clearScreen()
{
  system("CLEAR");
}

void board::createBoarder()
{
  int posX = 0;
  int posY = 0;

  vector<vector<Organism> >::iterator x;
  vector<Organism>::iterator y;
  for (x = _board.begin(); x != _board.end(); ++x)
  {
    for (y = x->begin(); y != x->end(); ++y)
    {
      if (x == _board.begin())
      {
        *y = BORDER;
      }
      if (x == _board.end() - 1)
      {
        *y = BORDER;
      }
      if ( y == x->begin())
      {
        *y = BORDER;
      }
      if ( y == x->end() - 1)
      {
        *y = BORDER;
      }
    }
  }

}


//TODO add @description

/**
 * Print the Board
 *
 * Takes the _board and loops through it printing based on organsim's status
 */
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


//TODO add @description

/**
 * Complete one cycle through the board
 *
 * Based on the rules of game of life evaluates the board.
 *
 */
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
      if ((*y == NONE) && (countOrganisms(posX, posY) == 3))
      {
        *y = GESTATING;
      }
      else if ((*y == LIVING) && (countOrganisms(posX, posY) < 2))
      {
        *y = DYING;
      }
      else if ((*y == LIVING) && (countOrganisms(posX, posY) >= 4))
      {
        *y = DYING;
      }
    }
    cout << endl;
  }
  _generation++;
}


//TODO add @description

/**
 * Cleanup the board based on a cycle
 *
 * Cleans up the dying and gestistating organisms setting them to there final status before we
 * end this generation
 */
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


/**
 * Count neighbot organsisms
 *
 * @param int cRow : the current x position of the organisms to count around
 * @param int cCol : the current y position of the orgnaism to count around
 *
 * @description : given a organisms positions counts the living organisms around it.
 * Counts a square 1 block around the current block, while not counting the current
 * organisms.
 */
int board::countOrganisms(int cRow, int cCol)
{
  int neighborcount = 0;

  for (int x = -1; x < 2; x++)
  {
    for (int y = -1; y < 2; y++)
    {
      if ((_board[cRow + x][cCol + y] == LIVING) || (_board[cRow + x][cCol + y] == DYING))
      {
        if ((x == 0) && (y == 0))
        {
          continue;
        }
        neighborcount++;
      }
    }
  }
  return neighborcount;
}
