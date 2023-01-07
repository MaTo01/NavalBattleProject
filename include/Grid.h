//2032460 Van Sang Ho
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Position.h"
#include "Ship.h"

class Grid {
protected:
    std::vector<std::vector<char>> tiles;

public:
    Grid();
    Grid(unsigned int rows, unsigned int cols);
    ~Grid() {}

    char getTile(unsigned int x, unsigned int y) const { return tiles[x][y]; }
    void setTile(unsigned int x, unsigned int y, char c) { tiles[x][y] = c; }

    void printGrid(std::ostream& os);
};

//Constants indicating extended ASCII characters used to display the grid
static constexpr char cornerLU = 218;   // ┌
static constexpr char cornerLD = 192;   // └
static constexpr char cornerRU = 191;   // ┐
static constexpr char cornerRD = 217;   // ┘
static constexpr char lineH = 196;      // ─
static constexpr char lineV = 179;      // │
static constexpr char connectL = 180;   // ┤
static constexpr char connectR = 195;   // ├
static constexpr char connectU = 193;   // ┴
static constexpr char connectD = 194;   // ┬
static constexpr char connectLR = 197;  // ┼

#include "Grid.hpp"

#endif