#include "mainmenuscreen.h"

#include <SFML/Graphics.hpp>

#include "resourcemanager.h"

MainMenuScreen::MainMenuScreen(void)
    : Screen()
{
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
        }
    }
}

void MainMenuScreen::update(float deltaTime)
{
}

void MainMenuScreen::draw(sf::RenderWindow &window)
{
}
