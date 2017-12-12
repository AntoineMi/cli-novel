#include "headers/Level.h"

Level::Level(int id) {
    m_id = id;
}

int Level::getId() const {
    return m_id;
}

const Graph &Level::getGraph() const {
    return m_graph;
}