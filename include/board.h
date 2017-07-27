#ifndef _BOARD_H_
#define _BOARD_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

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
        TurnO
    };

    enum CellSize {
        CellWidth = 128,
        CellHeight = 128
    };

    sf::Vector2i mapCoordsToGreed(const sf::Vector2i &coords);
    void draw(sf::RenderWindow &window);

    void makeMove(const sf::Vector2i &position);

private:
    int m_state[3][3];
    int m_turn;

    sf::Vector2f m_position;

    sf::Sprite m_playerSprite;
};

#endif // _BOARD_H_
