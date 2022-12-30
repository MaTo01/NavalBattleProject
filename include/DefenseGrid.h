// Ho Van Sang
#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include "Grid.h"

class DefenseGrid : public Grid{
private:

public:
    DefenseGrid();
    ~DefenseGrid();

    void printGrid(std::ostream& os) override;
};

#include "DefenseGrid.hpp"

#endif