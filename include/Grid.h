// Ho Van Sang
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "Position.h"

class Grid{
private:
    char tiles[12][12];

public:
    Grid();
    ~Grid();

    char getTile(unsigned int x, unsigned int y) const { return tiles[x][y]; }
    char setTile(unsigned int x, unsigned int y, char c) { tiles[x][y] = c; }

    std::ostream& printGrid(std::ostream& os);
};

#include "Grid.hpp"

#endif