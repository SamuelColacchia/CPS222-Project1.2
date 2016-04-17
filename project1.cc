

#include "gameOfLife.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

static const int activeRows = 18;
static const int activeCols = 50;

int main()
{
  cout << "The Game of Life" << endl;

  char command;

  int x;
  int y;

  cout << "Use D(efault) or C(ustom), for the grid size or Q(uit)." << endl;

  // Modified based on project4.cc originially written by
  // Russell C. Bjork

  do
  {
    cin >> command;
    if (cin.eof())
    {
      command = 'Q';
    }

    switch (command)
    {
    case 'D':
    case 'd':
      x = activeCols;
      y = activeRows;
      cout << "Table made with width:" << x << " and height:" << y << endl;



      break;

    case 'C':
    case 'c':
      cout << "Width:";
      cin >> x;
      cin.ignore(10000, '\n');
      cout << "Height:";
      cin >> y;
      cin.ignore(10000, '\n');

    case 'Q':
    case 'q':
      cout << "Finished" << endl;
      break;

    default:
      while (cin.get() != '\n')
      {
      }

      cout << string( 100, '\n');

      cout << "Valid commands are:" << endl << "D(efault) or C(ustom), for the grid size or Q(uit)." << endl;
    }
  } while (command != 'Q' && command != 'q' && command != 'C' && command != 'c' && command != 'D' && command != 'd');

  cout << "Current Value | Width:" << x << " Height:" << y << endl;

  board theBoard(x,y);

  theBoard.printBoard();


  // cout << "Board empty :" << theBoard << endl;

  // do {
  //   //display board uncluding gen number
  //
  //   //option to quit
  //
  //   //enter cycles
  //
  //
  //   /* code */
  // } while(/* condition */);

  // do {
  //   cin >> command;
  //   if (cin.eof()) command = 'Q';
  //
  //   switch (command) {
  //     case
  //   }



  /* code */
}


// while (command != 'Q' && command != 'q')
// {
// }
// }
