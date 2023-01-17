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

    //Returns (if it exists) the pointer to one of the DefenseGrid's Ships given its center
    Ship* getShipByCenter(Position pos);
    //Returns (if it exists) the pointer to one of the DefenseGrid's Ships given a Position it occupies in the DefenseGrid
    Ship* getShipByPosition(Position pos);
    //Returns a pointer to the n-th Ship of the vector
    Ship* getShipByIndex(int n);
    //Checks if the given Position is occupied by a Ship
    bool isShipAtPosition(Position pos);
    
    bool loseMatch() {return ships_.size()==0;}

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
