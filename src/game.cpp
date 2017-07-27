#include "game.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "resourcemanager.h"
#include "mainmenuscreen.h"

Game::Game(void)
    : m_window(sf::VideoMode(500, 500), L"TicTacToe \xA9 Milos Zivlak 2017"),
      m_gameState(GameStateMainMenu)
{
    loadResources();

    m_window.setFramerateLimit(60);

    m_screens[GameStateMainMenu] = std::make_shared<MainMenuScreen>();
}

Game::~Game(void)
{
}

void Game::loadResources(void)
{
    try {
        ResourceManager &resourceManager = ResourceManager::getResourceManager();

        resourceManager.loadTexture("player", "res/textures/player.png");
        resourceManager.loadFont("menu", "res/fonts/kaushan.otf");
    } catch(const std::string &ex) {
        std::cerr << ex << std::endl;
    }
}

void Game::gameLoop(void)
{
    sf::Clock clock;

    while(m_window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        std::shared_ptr<Screen> screen = m_screens[m_gameState];

        int gameStatus = screen->handleEvents(m_window);
        if(gameStatus < 0)
            m_window.close();
        else if(gameStatus < GameStateCount)
            m_gameState = gameStatus;

        screen->update(deltaTime.asSeconds());

        m_window.clear();
        screen->draw(m_window);
        m_window.display();
    }
}
