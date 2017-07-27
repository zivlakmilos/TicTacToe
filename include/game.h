#ifndef _GAME_H_
#define _GAME_H_

#include "screen.h"
#include <memory>

class Game
{
public:
    Game(void);
    ~Game(void);

    enum GameState
    {
        GameStateMainMenu = 0,
        GameStatePlaying,
        GameStateCount
    };

    inline void start(void) { gameLoop(); }

private:
    void loadResources(void);
    void gameLoop(void);

    sf::RenderWindow m_window;
    std::shared_ptr<Screen> m_screens[GameStateCount];
    int m_gameState;
};

#endif // _GAME_H_
