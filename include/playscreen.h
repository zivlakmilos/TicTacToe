#ifndef _PLAY_SCREEN_H_
#define _PLAY_SCREEN_H_

#include "screen.h"

#include "board.h"

class PlayScreen : public Screen
{
public:
    PlayScreen(void);
    virtual ~PlayScreen(void);

    virtual int handleEvents(sf::RenderWindow &window) override;
    virtual void update(float deltaTime) override;
    virtual void draw(sf::RenderWindow &window) override;

private:
    Board m_board;
};

#endif // _PLAY_SCREEN_H_
