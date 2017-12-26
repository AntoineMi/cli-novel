#include "headers/Game.h"

Game::Game() {
    Level l;
    m_currentLevel = l;
}

void Game::newGame() {
    // Clear last playthrough
    std::ofstream playthrough("../user/lastPlaythrough.txt", std::ofstream::out | std::ofstream::trunc);
    playthrough.close();

    startLevel();
}

void Game::startLevel(unsigned int id) {
    Level m_currentLevel(id);
    Graph &g = m_currentLevel.getGraph();
    g.load(id);
    m_currentLevel.playNode();

    // If the player reached "game over"
    if(m_currentLevel.isGameOver())
        over();

    else startLevel(id + 1);
}

void Game::over() const {
    std::cout << std::endl;
    std::cout << "####### #     # #######    ####### #     # ######" << std::endl;
    std::cout << "   #    #     # #          #       ##    # #     #" << std::endl;
    std::cout << "   #    #     # #          #       # #   # #     #" << std::endl;
    std::cout << "   #    ####### #####      #####   #  #  # #     #" << std::endl;
    std::cout << "   #    #     # #          #       #   # # #     #" << std::endl;
    std::cout << "   #    #     # #          #       #    ## #     #" << std::endl;
    std::cout << "   #    #     # #######    ####### #     # ######" << std::endl << std::endl;

    std::cout << "Don't hesitate to play again, take different steps and make different choices based on your previous"
            " run. Maybe you'll find another ending..." << std::endl;
}

// GETTERS

Level Game::getCurrentLevel() const {
    return m_currentLevel;
}


