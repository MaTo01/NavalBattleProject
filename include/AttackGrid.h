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

    void markHit(Position p) { tiles[p.getX()][p.getY()] = 'X'; }
    void markMiss(Position p) { tiles[p.getX()][p.getY()] = 'O'; }
    void markScan(Position p) { tiles[p.getX()][p.getY()] = 'Y'; }
};

#endif