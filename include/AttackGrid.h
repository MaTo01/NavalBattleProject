// Ho Van Sang
#ifndef ATTACKGRID_H
#define ATTACKGRID_H

#include "Grid.h"

class AttackGrid : public Grid{
private:

public:
    AttackGrid();
    ~AttackGrid();

    void printGrid(std::ostream& os) override;
};

#include "AttackGrid.hpp"

#endif