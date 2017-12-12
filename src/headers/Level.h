#ifndef CLI_NOVEL_LEVEL_H
#define CLI_NOVEL_LEVEL_H

#include "Graph.h"

class Level {
private:
    int m_id;
    Graph m_graph;

public:
    // METHODS
    explicit Level(int id = 1);

    // GETTERS
    int getId() const;
    const Graph &getGraph() const;
};

#endif //CLI_NOVEL_LEVEL_H
