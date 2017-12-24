#include "headers/Game.h"

Game::Game() {
    Level l;
    m_currentLevel = l;
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

    std::cout << "Thank you for playing! I hope you enjoyed the story and had a pleasing game experience." << std::endl;
    std::cout << "Don't hesitate to play again, take different steps and make different choices based on your previous"
            " run. Maybe you'll find another ending... :)" << std::endl;
}

// GETTERS

Level Game::getCurrentLevel() const {
    return m_currentLevel;
}


