#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include "Grid.h"

class AttackGrid : public Grid{
private:

public:
    AttackGrid();
    ~AttackGrid() override = default;
};

#include "AttackGrid.hpp"

#endif