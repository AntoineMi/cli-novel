#include "headers/Game.h"

Game::Game() {
    Level l;
    m_currentLevel = l;
}

void Game::startLevel(unsigned int id) {
    std::string s_id = std::to_string(id);
    std::ifstream file("../data/" + s_id);

    // If the player reached a "game over" or if they completed the final level, the game ends.
    if(!file.is_open() || m_currentLevel.isGameOver()) {
        over();
    }
    else {
        Level m_currentLevel(id);
        Graph &g = m_currentLevel.getGraph();
        g.load(id);
        m_currentLevel.playNode();
        startLevel(id + 1);
    }
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


