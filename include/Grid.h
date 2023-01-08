//2032460 Van Sang Ho
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Position.h"

class Grid {
protected:
    std::vector<std::vector<char>> tiles;

    virtual bool isPosValid(Position p);

public:
    Grid();
    Grid(unsigned int rows, unsigned int cols);
    ~Grid() {}

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