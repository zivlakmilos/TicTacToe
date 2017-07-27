#ifndef _MAIN_MENU_SCREEN_H_
#define _MAIN_MENU_SCREEN_H_

#include "screen.h"

#include <SFML/Graphics/Text.hpp>

class MainMenuScreen : public Screen
{
public:
    MainMenuScreen(void);
    virtual ~MainMenuScreen(void);

    enum MenuOption {
        MenuOptionPlay = 0,
        MenuOptionQuit,
        MenuOptionCount
    };

    virtual int handleEvents(sf::RenderWindow &window) override;
    virtual void update(float deltaTime) override;
    virtual void draw(sf::RenderWindow &window) override;

private:
    sf::Text m_menuOptions[MenuOptionCount];
    int m_menuOptionSelected;
};

#endif // _MAIN_MENU_SCREEN_H_
