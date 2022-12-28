#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include "Grid.h"

class DefenseGrid : public Grid{
private:

public:
    DefenseGrid();
    ~DefenseGrid() override = default;
};

#include "DefenseGrid.hpp"

#endif