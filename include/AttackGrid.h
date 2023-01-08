#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include <iostream>
#include <vector>
#include "Grid.h"

class AttackGrid : public Grid {
private:
    bool isPosValid(Position p) override;
    
public:
    AttackGrid();
    AttackGrid(unsigned int rows, unsigned int cols) : Grid(rows, cols) {}
    ~AttackGrid() {}

    void markHit(Position p);
    void markMiss(Position p);
    void markScan(Position p);
    bool isAlreadyMarked(Position p);
};

#include "AttackGrid.hpp"

#endif