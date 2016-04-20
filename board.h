#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;
using std::vector;

class board
{
public:
        board(int x, int y);


private:
        enum Organism
        {
                NONE,
                GESTATING,
                LIVING,
                DYING,
                BORDER
        };
        const static int _hr = 95;
        // static char _fCirlce = "\u25CF";
        // static char _lCell = "\u25A0";

public:
        void printBoard();
        void setStartingOrganism(int x, int y);
        void clearScreen();

private:
        int _col;
        int _row;
        int _generation;
        vector < vector<Organism> > _board;
};
