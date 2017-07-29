#include "ai.h"

#include <iostream>

Ai::Ai(void)
{
}

Ai::~Ai(void)
{
}

sf::Vector2i Ai::calcBestMove(Board &board)
{
    Move move = minimax(board, Board::TurnO);
    std::cout << move.x << std::endl
              << move.y << std::endl
              << move.points << std::endl;
    return sf::Vector2i(move.x, move.y);
}

Ai::Move Ai::minimax(Board &board, int turn)
{
    Move bestMove;

    int state = board.checkForWin();
    if(state == Board::StateX)
    {
        bestMove.points = 10;
        return bestMove;
    } else if(state == Board::StateO)
    {
        bestMove.points = -10;
        return bestMove;
    } else if(state == Board::StateFree)
    {
        bestMove.points = 0;
        return bestMove;
    }

    if(turn == Board::TurnX)
        bestMove.points = -100000;
    else if(turn == Board::TurnO)
        bestMove.points = 100000;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board.getValue(j, i) == Board::StateFree)
            {
                Move move;
                move.x = j;
                move.y = i;

                if(turn == Board::TurnX)
                {
                    board.setValue(move.x, move.y, Board::StateX);
                    Move currentMove = minimax(board, Board::TurnO);
                    if(currentMove.points > bestMove.points)
                    {
                        bestMove.points = currentMove.points;
                        bestMove.x = move.x;
                        bestMove.y = move.y;
                    }
                } else if(turn == Board::TurnO)
                {
                    board.setValue(move.x, move.y, Board::StateO);
                    Move currentMove = minimax(board, Board::TurnX);
                    if(currentMove.points < bestMove.points)
                    {
                        bestMove.points = currentMove.points;
                        bestMove.x = move.x;
                        bestMove.y = move.y;
                    }
                }
                board.setValue(move.x, move.y, Board::StateFree);
                board.clearCrossLine();
                board.setTurn(turn);
            }
        }
    }

    return bestMove;
}
