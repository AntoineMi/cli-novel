#ifndef CLI_NOVEL_GAME_H
#define CLI_NOVEL_GAME_H

#include "Level.h"

class Game {
private:
    Level m_currentLevel;

public:
    // METHODS
    Game();
    void over() const;

    void startLevel(unsigned int id = 1);

    // GETTERS
    Level getCurrentLevel() const;
};


#endif //CLI_NOVEL_GAME_H
