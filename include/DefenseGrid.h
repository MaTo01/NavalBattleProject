//2032460 Van Sang Ho
#ifndef DEFENSEGRID_H
#define DEFENSEGRID_H

#include <memory>
#include "Grid.h"

class Ship;

class DefenseGrid : public Grid {
private:
    //Vector of unique_ptrs to the Ships placed in the DefenseGrid
    std::vector<std::unique_ptr<Ship>> ships_;

    //Returns a list of Positions in which to place a Ship of the given parameters
    std::vector<Position> getTilesForPlacement(int size, char orientation, Position pos);
    //Returns a list of the Positions occupied by a given Ship
    std::vector<Position> getTilesByShip(Ship* ship);

public:
    //Constructors
    DefenseGrid() : Grid() {}
    DefenseGrid(unsigned int rows, unsigned int cols) 
        : Grid(rows, cols) {}
    //Destructor
    ~DefenseGrid();

    //Returns (if it exists) a Ship given its center
    Ship* getShipByCenter(Position pos);
    //Returns (if it exists) a Ship given a Position it occupies in the DefenseGrid
    Ship* getShipByPosition(Position pos);
    //Checks if the given Position is occupied by a Ship
    bool isShipAtPosition(Position pos);
    //Returns the pointer of a ship at the n-position in the ships_ vector
    Ship* getShipAt(int n) {return ships_[n].get();}

    //Adds a Ship to the DefenseGrid 
    void placeShip(std::unique_ptr<Ship> ship);
    //Moves an existing Ship to a different Position
    void moveShip(Ship* ship, Position pos);
    //Removes a Ship from the DefenseGrid
    void removeShip(Ship* ship);
    //Marks a Ship as hit (and removes it if it is destroyed)
    void markShipAsHit(Position pos);
    //Fully repairs the Ship at the given Position
    void repairShip(Position pos);
};

#endif
