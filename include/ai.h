#ifndef _AI_H_
#define _AI_H_

#include "board.h"

class Ai
{
public:
    Ai(void);
    ~Ai(void);

    struct Move
    {
        int x;
        int y;
        int points;
        int turn;
    };

    sf::Vector2i calcBestMove(Board &board);

private:
    Move minimax(Board &board, int turn);
};

#endif // _AI_H_
