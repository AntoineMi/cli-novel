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

public:
    // METHODS
    void load(int level);

    // GETTERS
    const std::vector<std::vector<int> > &getMatrix() const;
};


#endif //CLI_NOVEL_GRAPH_H
