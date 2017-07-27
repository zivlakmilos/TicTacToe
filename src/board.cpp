#include "board.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "resourcemanager.h"

Board::Board(void)
    : m_turn(TurnX)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            m_state[i][j] = StateFree;
}

Board::~Board(void)
{
}

sf::Vector2i Board::mapCoordsToGreed(const sf::Vector2i &coords)
{
    if(coords.x < m_position.x || coords.x > m_position.x + 3 * CellWidth ||
        coords.y < m_position.y || coords.y > m_position.y + 3 * CellHeight)
        return sf::Vector2i(-1, -1);

    int x = (m_position.x + coords.x) / CellWidth - 1;
    int y = (m_position.y + coords.y) / CellHeight - 1;

    return sf::Vector2i(x, y);
}

void Board::draw(sf::RenderWindow &window)
{
    m_position.x = window.getSize().x / 2.0f - CellWidth * 3.0f / 2.0f;
    m_position.y = window.getSize().y / 2.0f - CellHeight * 3.0f / 2.0f;

    for(int i = 0; i < 2; i++)
    {
        sf::VertexArray vertices;

        sf::Vertex vertexVS(sf::Vector2f(m_position.x + i* CellWidth + CellWidth,
                                         m_position.y));
        sf::Vertex vertexVE(sf::Vector2f(m_position.x + i * CellWidth + CellWidth,
                                         m_position.y + 3 * CellHeight));
        sf::Vertex vertexHS(sf::Vector2f(m_position.x,
                                         m_position.y + i * CellHeight + CellHeight));
        sf::Vertex vertexHE(sf::Vector2f(m_position.x + 3 * CellWidth,
                                         m_position.y + i * CellHeight + CellHeight));

        vertices.append(vertexVS);
        vertices.append(vertexVE);
        vertices.append(vertexHS);
        vertices.append(vertexHE);
        window.draw(&vertices[0], vertices.getVertexCount(), sf::Lines);
    }

    m_state[0][0] = StateO;
    m_state[1][1] = StateX;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(m_state[i][j] == StateFree)
                continue;

            try {
                std::shared_ptr<sf::Texture> texture
                    = ResourceManager::getResourceManager().getTexture("player");
                m_playerSprite.setTexture(*texture);
                m_playerSprite.setPosition(m_position.x + j * CellWidth,
                                           m_position.y + i * CellHeight);

                sf::IntRect textureRect(0, 0, 128, 128);
                if(m_state[i][j] == StateX)
                    textureRect.left += textureRect.width;
                m_playerSprite.setTextureRect(textureRect);
                m_playerSprite.setColor(sf::Color::White);

                window.draw(m_playerSprite);
            } catch(const std::string &ex) {
                std::cout << ex << std::endl;
            }
        }
    }

    sf::Vector2i mouse = mapCoordsToGreed(sf::Mouse::getPosition(window));
    if(mouse.x < 0 && mouse.y < 0 ||
        m_state[mouse.y][mouse.x] != StateFree)
        return;

    try {
        std::shared_ptr<sf::Texture> texture
            = ResourceManager::getResourceManager().getTexture("player");
        m_playerSprite.setTexture(*texture);
        m_playerSprite.setPosition(m_position.x + mouse.x * CellWidth,
                                   m_position.y + mouse.y * CellHeight);
        sf::IntRect textureRect(0, 0, 128, 128);
        if(m_turn == TurnX)
            textureRect.left += textureRect.width;
        m_playerSprite.setTextureRect(textureRect);
        m_playerSprite.setColor(sf::Color(255, 255, 255, 128));

        window.draw(m_playerSprite);
    } catch(const std::string &ex) {
        std::cout << ex << std::endl;
    }
}

void Board::makeMove(const sf::Vector2i &position)
{
    sf::Vector2i mouse = mapCoordsToGreed(position);

    if(m_turn == TurnX)
    {
        m_state[mouse.y][mouse.x] = StateX;
        m_turn = TurnO;
    } else if(m_turn == TurnO)
    {
        m_state[mouse.y][mouse.x] = StateO;
        m_turn = TurnX;
    }
}
