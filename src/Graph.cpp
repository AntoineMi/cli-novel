#include "headers/Graph.h"

Graph::Graph() {
    m_size = 0;
}

void Graph::load(int level) {
    // Convert int to string
    std::string s_level = std::to_string(level);

    // Load level (or game over)
    std::ifstream file("../data/" + s_level);
    if(!file.is_open()) {
        throw std::runtime_error("Level " + s_level + " does not exist");

    }

    // Read the first line to define matrix size
    std::string line;
    std::getline(file, line);
    unsigned int size = 0;
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
            file >> m_matrix[i][j];
        }
    }

    // Save matrix size
    m_size = size;

    // Close file
    file.close();
}

void Graph::read(unsigned int level, unsigned int node) {

    // Convert ints to strings
    std::string s_level = std::to_string(level);
    std::string s_node = std::to_string(node);

    // Load level data
    std::ifstream file("../data/" + s_level + "_txt");
    // Load playthrough
    std::ofstream playthrough("../user/lastPlaythrough.txt", std::ios::out | std::ios::app);

    std::cout << std::endl << std::endl << "__________________________________________" << std::endl << std::endl;

    std::string line;
    bool metNode = false;
    while (std::getline(file, line)) {
        // Go to current node (line)
        if (line.find("&" + s_node, 0) != std::string::npos) {
            metNode = true;
            continue;
        }
        // Exit if ending character is met
        if ((metNode) && (line.find('*', 0) != std::string::npos))
            break;
        else if(metNode) {
            std::cout << line << std::endl;
            playthrough << line << std::endl;
        }
    }

    // Close file
    file.close();
}

// SETTERS & GETTERS

const std::vector<std::vector<int> > &Graph::getMatrix() const {
    return m_matrix;
}

unsigned int Graph::getSize() const {
    return m_size;
}
