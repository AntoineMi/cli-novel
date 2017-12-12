#include "headers/Game.h"

Game::Game() {
    Level l;
    m_currentLevel = l;
}

void Game::startLevel(int id) {
    Level m_currentLevel(id);
    Graph g = m_currentLevel.getGraph();
    g.load(id);
}

Level Game::getCurrentLevel() const {
    return m_currentLevel;
}


