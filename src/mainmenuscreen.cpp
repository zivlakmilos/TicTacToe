#include "mainmenuscreen.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "resourcemanager.h"
#include "game.h"

MainMenuScreen::MainMenuScreen(void)
    : Screen(),
      m_menuOptionSelected(MenuOptionPlay)
{
    m_menuOptions[MenuOptionPlay].setString("Play");
    m_menuOptions[MenuOptionQuit].setString("Quit");
}

MainMenuScreen::~MainMenuScreen(void)
{
}

int MainMenuScreen::handleEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                return -1;
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Down:
                        if(++m_menuOptionSelected >= MenuOptionCount)
                            m_menuOptionSelected = 0;
                        break;
                    case sf::Keyboard::Up:
                        if(--m_menuOptionSelected < 0)
                            m_menuOptionSelected = MenuOptionCount - 1;
                        break;
                    case sf::Keyboard::Return:
                        if(m_menuOptionSelected == MenuOptionQuit)
                            return -1;
                        else if(m_menuOptionSelected == MenuOptionPlay)
                            return Game::GameStatePlaying;
                        break;
                }
                break;
        }
    }

    return Game::GameStateMainMenu;
}

void MainMenuScreen::update(float deltaTime)
{
}

void MainMenuScreen::draw(sf::RenderWindow &window)
{
    try {
        std::shared_ptr<sf::Font> font
            = ResourceManager::getResourceManager().getFont("menu");

        for(int i = 0; i < MenuOptionCount; i++)
        {
            m_menuOptions[i].setPosition(window.getSize().x / 2.0f - m_menuOptions[i].getLocalBounds().width / 2.0f,
                                         window.getSize().y / 2.0f + i * 50.0f - 100.0f);
            m_menuOptions[i].setFont(*font);
            m_menuOptions[i].setColor(i == m_menuOptionSelected ? sf::Color::Red : sf::Color::White);
            window.draw(m_menuOptions[i]);
        }
    } catch(const std::string &ex) {
        std::cout << ex << std::endl;
    }
}
