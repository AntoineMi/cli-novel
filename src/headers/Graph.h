#ifndef CLI_NOVEL_GRAPH_H
#define CLI_NOVEL_GRAPH_H

#include <vector>

class Graph {
private:
    int index;
    std::vector<std::vector<int>> matrix;
    std::vector<int> history;
};


#endif //CLI_NOVEL_GRAPH_H
