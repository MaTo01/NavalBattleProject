#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include <iostream>
#include <vector>
#include <memory>
#include "Grid.h"

class DefenseGrid : public Grid {
public:
    DefenseGrid();
    DefenseGrid(unsigned int rows, unsigned int cols) : Grid(rows, cols) {}
    ~DefenseGrid() {}

    //placeholders
    bool placeShip(std::unique_ptr<Ship> s, Position p);
    bool moveShip(Ship& s, Position p);
};

#include "DefenseGrid.hpp"

#endif