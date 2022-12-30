// Ho Van Sang
#ifndef GRID_H
#define GRID_H

#include <iostream>

class Grid{
private:

public:
    Grid(); 
    ~Grid();

    virtual void printGrid(std::ostream& os) = 0;
};

#endif