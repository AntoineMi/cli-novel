#include <iostream>
#include "headers/Graph.h"
#include "headers/Game.h"

int main() {

    try {
        Game g;
        g.newGame();
        return 0;
    }
    catch (std::runtime_error const &e) {
        std::cerr << "Error! " << e.what() << std::endl;
    }

}