#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>


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
        const static unsigned _topBottom = 95;
        const static unsigned _corner = 35;

        // const static unsigned _hrbottom = 95;
        // const static unsigned _hrtop = 238;

        // const static unsigned _ltopcorner = 218;
        // const static unsigned _rtopcorner = 191;

        // const static unsigned _lbottomcorner = 192;
        // const static unsigned _rbottomcorner = 217;
        // static char _fCirlce = "\u25CF";
        // static char _lCell = "\u25A0";

public:
        void printBoard();
        void setStartingOrganism(int x, int y);
        void clearScreen();
        void cycle();
        int countOrganisms(int cRow, int cCol);
        void cleanup();

private:
        int _col;
        int _row;
        int _generation;

        vector < vector<Organism> > _board;
};
