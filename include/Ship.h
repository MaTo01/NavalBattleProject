//2043414 Marco Toffoletto
#ifndef SHIP_H
#define SHIP_H

#include "Position.h"
#include "Grid.h"

//Parent class that will be inherited by the other three classes
//that represent the three types of ship
class Ship{
protected:
    //Two dimensions representing the size of the boat and the remaining armor.
    //At the beginning of the game they will be the same, armor is the only one
    //that can decrease
    const int size_; 
    int armor_; 

    //Three positions to identify the bow, the center and the stern of the ship
    Position bow_;
    Position center_;
    Position stern_;

    //Flag to identify the orientation of the ship
    char orientation_;

    //Character used to represent the ship in the grid
    char gridCharacter;

public:
    //Constructor
    Ship(const int& size, Position bow, Position stern, char gridC);
    //Virtual destructor
    virtual ~Ship(){}

    //Get functions
    int getSize() const {return size_;}
    int getArmor() const {return armor_;}
    Position getBow() const {return bow_;}    
    Position getCenter() const {return center_;}
    Position getStern() const {return stern_;}
    char getOrientation() const{return orientation_;}
    char getGridCharacter() const { return gridCharacter; }

    //Set functions
    void setArmor(int armor) {armor_ = armor;}
    void setBow(Position bow) {bow_ = bow;}
    void setCenter(Position center) {center_ = center;}
    void setStern(Position stern) {stern_ = stern;}
    void setOrientation(char orientation) {orientation_ = orientation;}

    //Pure virtual function that represent the action of a 
    //ship and will be overrided by the subclasses as needed
    virtual void action(Position pos, Grid* enemyDefenseGrid = NULL) = 0;

    //Member function
    bool isSunk() const {return armor_ == 0;}
};

#include "Ship.hpp"

#endif