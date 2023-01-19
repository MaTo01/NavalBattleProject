//2043414 Marco Toffoletto
#ifndef SHIP_H
#define SHIP_H

#include "Position.h"
#include "DefenseGrid.h"

//Base class that will be inherited by the other three classes
//that represent the three types of ships
class Ship {
protected:
    //Two dimensions representing the size of the ship and its remaining armor.
    //At the beginning of the game they will be the same, the armor will decrease if the ship is hit
    const int size_;
    int armor_; 

    //A position to identify the center of the ship
    Position center_;

    //Flag to identify the orientation of the ship
    char orientation_;

    //Char used to represent the ship in the defense grid
    char gridCharacter_;

public:
    //Constructor
    Ship(const int size, Position bow, Position stern, char gridCharacter);
    //Virtual destructor
    virtual ~Ship(){}

    //Get functions
    int getSize() const { return size_; }
    int getArmor() const { return armor_; }
    Position getCenter() const { return center_; }
    char getOrientation() const{ return orientation_; }
    char getGridCharacter() const { return gridCharacter_; }

    //Set functions
    void setArmor(int armor) { armor_ = armor; }
    void setCenter(Position center) { center_ = center; }
    void setOrientation(char orientation) { orientation_ = orientation; }

    //Pure virtual function that represents the action of a 
    //ship and will be overridden by the subclasses as needed.
    /*
    Two arguments are passed: a position, which is the one on 
    which the action will be performed, and a pointer to 
    the enemy's defense grid, necessary for actions that modify or exploit it.
    The pointer to the enemy's defense grid will not be used by all 
    the types of ships, so it's initialized to "nullptr" and action
    can also be called without the second argument
    */
    virtual void action(Position pos, DefenseGrid *enemyDefenseGrid = nullptr) = 0;

    //Member function
    bool isSunk() const { return armor_ == 0; }
};

#include "Ship.hpp"
#include "DefenseGrid.hpp"

#endif
