

class board
{
public:
    board(int x, int y);
private:
        enum Organism
        {
                NONE, GESTATING, LIVING, DYING, BORDER
        };



private:
        int _generation;
        Organism _board;

};
