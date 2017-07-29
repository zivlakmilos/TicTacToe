#ifndef _BOARD_H_
#define _BOARD_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class Board
{
public:
    Board(void);
    ~Board(void);

    enum State {
        StateFree = 0,
        StateX,
        StateO
    };

    enum Turn {
        TurnX = 0,
        TurnO,
        TurnGameOver
    };

    enum CellSize {
        CellWidth = 128,
        CellHeight = 128
    };

    inline int getValue(int x, int y) { return m_state[y][x]; }
    inline void setValue(int x, int y, int value) { m_state[y][x] = value; m_lastMove = sf::Vector2i(x, y); }

    inline void setTurn(int turn) { m_turn = turn; }

    inline void clearCrossLine(void) { m_crossLine.clear(); }

    sf::Vector2i mapCoordsToGreed(const sf::Vector2i &coords);
    void draw(sf::RenderWindow &window);

    void makeMove(const sf::Vector2i &position);
    void makeMoveAi(const sf::Vector2i &position);
    int checkForWin(void);

private:
    int m_state[3][3];
    int m_turn;
    sf::Vector2i m_lastMove;

    sf::Vector2f m_position;

    sf::Sprite m_playerSprite;
    sf::VertexArray m_crossLine;
};

#endif // _BOARD_H_
