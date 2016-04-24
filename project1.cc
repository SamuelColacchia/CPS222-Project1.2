#include "board.h"

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

  int startingOrganisms;

  cout << "Use D(efault) or C(ustom), for the grid size or Q(uit)." << endl;

  // Modified based on project4.cc originially written by
  // Russell C. Bjork

/*
 * Set board parameter loop
 *
 * Command
 *
 * D : Load default paramters for width and height as specified by project 1
 *
 * C : Set custom width and height for the game board
 *
 * Q : Quit the program and return to the prompt
 */
  do
  {
    cin >> command;
    while (cin.get() != '\n')
    {
    }
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
      break;

    case 'Q':
    case 'q':
      cout << "Finished" << endl;
      break;

    default:
      while (cin.get() != '\n')
      {
      }
      cout << "Valid commands are:" << endl << "D(efault) or C(ustom), for the grid size or Q(uit)." << endl;
    }
  } while (command != 'Q' && command != 'q' && command != 'C' && command != 'c' && command != 'D' && command != 'd');

  board theBoard(x, y);


  /*
   * Set initial organisms on the board
   *
   * Command
   *
   * S : given a number for the start organisms and set there x:y positions
   *
   * B : begin the simulation and allow the program to start looping
   *
   * Q : Quit the program and return to the prompt
   *
   * P : print the current board
   */

  cout << "S(et) number of starting living organism or Q(uit) or B(egin) simulation." << endl;

  do
  {
    cin >> command;
    while (cin.get() != '\n')
    {
    }
    if (cin.eof())
    {
      command = 'Q';
    }
    switch (command)
    {
    case 'Q':
    case 'q':
      cout << "Finished" << endl;
      break;

    case 'S':
    case 's':
      theBoard.clearScreen();
      cout << "Number of Organisms:" << endl;
      cin >> startingOrganisms;
      while (cin.get() != '\n')
      {
      }
      for (int i = 0; i < startingOrganisms; i++)
      {
        cout << "Organism left to set:" << startingOrganisms - i << endl;
        cout << "(X Y)" << endl;
        cin >> x;
        cin >> y;

        cout << "x:" << x << " y:" << y << endl;
        theBoard.setStartingOrganism(x, y);
        cout << "" << endl;
      }
      cout << "B(egin) simulation, S(et) more organisms, P(rint) the current board, Q(uit) program." << endl;
      break;

    case 'B':
    case 'b':
      cout << "Simulation starting." << endl;
      break;

    case 'P':
    case 'p':
      theBoard.clearScreen();
      theBoard.printBoard();
      break;

    default:
      cout << "Valid commands: B(egin) simulation, S(et) the starting organisms, P(rint) the current board, Q(uit) program." << endl;
      break;
    }
  } while (command != 'Q' && command != 'q' && command != 'B' && command != 'b');

  /*
   * Main loop call
   *
   * ENTER : Clear the screen cycle the board, then show the board
   *
   * Q : Quit the program and return to the prompt
   */


  if ((command == 'b') || (command == 'B'))
  {
    theBoard.printBoard();
    cout << "ENTER to increase generations, Q(uit)." << endl;
    do
    {
      command = cin.get();
      switch (command)
      {
      case '\n':
        theBoard.clearScreen();
        theBoard.cycle();
        theBoard.cleanup();
        theBoard.printBoard();
        break;

      case 'Q':
      case 'q':
        cout << "Program quitting." << endl;
        break;

      default:
        cout << "Valid Commands: Q(uit), ENTER to increase generations" << endl;
        break;
      }
    } while (command != 'Q' && command != 'q');
  }
}
