#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include <iostream>
#include <vector>
#include "Grid.h"

class Ship;

class DefenseGrid : public Grid {
private:
    std::vector<Ship*> ships;

    std::vector<Position> getTilesForPlacement(int size, char orientation, Position pos);
    std::vector<Position> getTilesForShip(Ship* ship);

public:
    DefenseGrid();
    DefenseGrid(unsigned int rows, unsigned int cols) : Grid(rows, cols) {}
    ~DefenseGrid() {}

    void placeShip(Ship* ship);
    void moveShip(Ship* ship, Position pos);
    void markShipAsHit(Position pos);
    void removeShip(Ship* ship);

    Ship* getShipAtPosition(Position pos);
    bool isShipAtPosition(Position pos);
};

#endif