//2032460 Van Sang Ho
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Position.h"

class Grid {
protected:
    //2D vector representing the content of the grid's tiles
    std::vector<std::vector<char>> tiles_;

    //Tests if a given Position is valid within the grid
    bool isPosValid(Position pos);

public:
    //Constructors
    Grid();
    Grid(unsigned int rows, unsigned int cols);
    //Destructor
    ~Grid() {}

    //Prints the Grid and its contents on the desired output stream (e.g. std::cout, std::ofstream, etc.)
    void printGrid(std::ostream& os);
};

//Constants indicating extended ASCII characters used to display the Grid
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