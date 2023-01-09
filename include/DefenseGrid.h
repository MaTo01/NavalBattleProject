#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include <iostream>
#include <vector>
#include "Grid.h"

class Ship;

class DefenseGrid : public Grid {
private:
    std::vector<Ship*> ships;

    std::vector<Position> getShipTiles(Ship* s, Position p);

public:
    DefenseGrid();
    DefenseGrid(unsigned int rows, unsigned int cols) : Grid(rows, cols) {}
    ~DefenseGrid() {}

    //placeholders
    void placeShip(Ship* s, Position p);
    void moveShip(Ship* s, Position p);
    void markShipAsHit(Position p);
    void removeShip(Ship* s);

    Ship* getShipAtPosition(Position p);
    bool isShipAtPosition(Position p);
};

#endif