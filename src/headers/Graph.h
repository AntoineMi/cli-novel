#ifndef CLI_NOVEL_GRAPH_H
#define CLI_NOVEL_GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Graph {
private:
    int m_index;
    std::vector<int> m_history;
    std::vector<std::vector<int> > m_matrix;
    unsigned int m_size;

public:
    // METHODS
    Graph();
    void load(int level);
    void read(unsigned int level, unsigned int node);

    // GETTERS
    const std::vector<std::vector<int> > &getMatrix() const;
    unsigned int getSize() const;
};


#endif //CLI_NOVEL_GRAPH_H
