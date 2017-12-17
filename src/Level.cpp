#include "headers/Level.h"

Level::Level(unsigned int id) {
    m_id = id;
    m_gameOver = false;
}


int Level::playNode(unsigned int id) {
    m_line = id;
    unsigned int graphSize = m_graph.getSize();

    // Read node content
    m_graph.read(m_id, id);

    // Is game is over or last node is reached, exit level
    if (m_gameOver || id >= graphSize - 1)
        return 1;

    // Clear available choices
    m_choices.clear();
    for (unsigned int i = 0; i < graphSize; i++) {
        // Get available choices
        if (getGraph().getMatrix()[id][i]) {
            m_choices.push_back(i);
        }
    }

    // prompt
    promptChoices();
}

void Level::promptChoices() {
    unsigned int input = 0;
    while (input < 1 || input > m_choices.size()) {
        std::cout << ">";
        std::cin >> input;
    }

    if (getGraph().getMatrix()[m_line][m_choices[input - 1]] == 2)
        m_gameOver = true;

    playNode(m_choices[input - 1]);
}

// SETTERS & GETTERS

unsigned int Level::getId() const {
    return m_id;
}

Graph &Level::getGraph() {
    return m_graph;
}

bool Level::isGameOver() const {
    return m_gameOver;
}

std::vector<unsigned int> &Level::getChoices() {
    return m_choices;
}