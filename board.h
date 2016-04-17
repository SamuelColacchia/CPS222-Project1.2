#include <iostream>
#include <string>
#include <vector>

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

public:
        void createBoard();
        void printBoard();


private:
        int _col;
        int _row;
        int _generation;
        vector < vector<Organism> > _board;
};
