#ifndef _MAIN_MENU_SCREEN_H_
#define _MAIN_MENU_SCREEN_H_

#include "screen.h"

class MainMenuScreen : public Screen
{
public:
    MainMenuScreen(void);
    virtual ~MainMenuScreen(void);

    virtual int handleEvents(sf::RenderWindow &window) override;
    virtual void update(float deltaTime) override;
    virtual void draw(sf::RenderWindow &window) override;

private:
};

#endif // _MAIN_MENU_SCREEN_H_
