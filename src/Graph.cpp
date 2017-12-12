#include "headers/Graph.h"


void Graph::load(int level) {
    // Convert int to string
    std::string s_level = std::to_string(level);

    // Load level (or game over)
    std::ifstream file("../data/" + s_level);
    if(!file.is_open())
        std::cout << "Congrats! You beat the game!" << std::endl;

    // Read the first line to define matrix size
    std::string line;
    std::getline(file, line);
    int size = 0;
    for (int i = 0; line[i]; i++)
        if (line[i] != ' ') size++;

    m_matrix.resize(size);
    for(unsigned int i = 0; i < size;  i++) {
        m_matrix[i].resize(size);
    }

    // Go back to the beginning of the file
    file.clear();
    file.seekg (0, std::ios::beg);

    // Fill Graph matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> this->m_matrix[i][j];
        }
    }

}

// SETTERS & GETTERS

const std::vector<std::vector<int> > &Graph::getMatrix() const {
    return m_matrix;
}

