#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include <iostream>
#include <vector>
#include "Grid.h"

class AttackGrid : public Grid {
public:
    AttackGrid();
    AttackGrid(unsigned int rows, unsigned int cols) : Grid(rows, cols) {}
    ~AttackGrid() {}

    void markHit(Position p);
    void markMiss(Position p);
    void markScan(Position p);
};

#include "AttackGrid.hpp"

#endif