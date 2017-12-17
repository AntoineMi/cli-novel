#ifndef CLI_NOVEL_LEVEL_H
#define CLI_NOVEL_LEVEL_H

#include <fstream>
#include "Graph.h"

class Level {
private:
    unsigned int m_id;
    unsigned int m_line;
    bool m_gameOver;
    Graph m_graph;
    std::vector<unsigned int> m_choices;

public:
    // METHODS
    explicit Level(unsigned int id = 1);
    int playNode(unsigned int id = 0);
    void promptChoices();

    // GETTERS
    unsigned int getId() const;
    bool isGameOver() const;
    Graph &getGraph();
    std::vector<unsigned int> &getChoices();
};

#endif //CLI_NOVEL_LEVEL_H
