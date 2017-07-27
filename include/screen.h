#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SFML/Graphics/RenderWindow.hpp>

class Screen
{
public:
    Screen(void) {}
    virtual ~Screen(void) {}

    virtual void handleEvents(void) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

private:
};

#endif // _SCREEN_H_
