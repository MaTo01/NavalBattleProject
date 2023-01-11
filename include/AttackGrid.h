//2032460 Van Sang Ho
#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include <iostream>
#include <vector>
#include "Grid.h"

class AttackGrid : public Grid {
public:
    //Constructors
    AttackGrid() : Grid() {}
    AttackGrid(unsigned int rows, unsigned int cols) : Grid(rows, cols) {}
    //Destructor
    ~AttackGrid() {}

    //Marks a Position in the grid as a hit
    void markHit(Position p);
    //Marks a Position in the grid as a miss
    void markMiss(Position p);
    //Marks a Position in the grid as scanned 
    void markScan(Position p);
    //Checks if the cell at the given Position has already been marked as a hit/miss;
    //Scanned cells are not considered marked for this purpose
    bool isAlreadyMarked(Position p);
};

#include "AttackGrid.hpp"

#endif