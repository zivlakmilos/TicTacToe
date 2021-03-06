#include "playscreen.h"

#include <SFML/Graphics.hpp>

#include "game.h"

PlayScreen::PlayScreen(void)
    : Screen()
{
}

PlayScreen::~PlayScreen(void)
{
}

int PlayScreen::handleEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                return -1;
                break;
            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    m_board.makeMove(sf::Mouse::getPosition(window));
                    if(m_board.checkForWin() < 0)
                    {
                        sf::Vector2i position = m_ai.calcBestMove(m_board);
                        m_board.makeMoveAi(position);
                        m_board.checkForWin();
                    }
                }
                break;
        }
    }

    return Game::GameStatePlaying;
}

void PlayScreen::update(float deltaTime)
{
}

void PlayScreen::draw(sf::RenderWindow &window)
{
    m_board.draw(window);
}
