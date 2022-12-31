//2043414 Marco Toffoletto
#ifndef SHIP_H
#define SHIP_H

#include "Position.h"
#include "Grid.h"

//Parent class that will be inherited by the other three classes
//that represent the three types of ship
class Ship{
protected:
    //Two protected variables that represent the dimension and the
    //remaining armor of the ship.
    //At the beginning of the game, those variables have the same value
    const int size_;
    int armor_;

    //A variable that represent the center of the ship into the grid
    //and a variable to represent the orientation of the ship (Horizontal, Vertical)
    Position center_;
    char orientation_;

    //A bool variable to identify if the ship is sunk or not
    bool sunk_;

public:
    //Constructor
    Ship(const int& size, int armor): size_{size}, armor_{armor}, sunk_{false}{}

    //Destructor
    virtual ~Ship() = 0;

    //Get functions for the variables size_ and armor_
    int getSize() const {return size_;}
    int getArmor() const {return armor_;}
    Position getCenter() const {return center_;}
    char getOrientation() const{return orientation_;}
    bool isSunk() const {return sunk_;}

    //Set functions for the variables size_ and armor_
    void setArmor(int armor) {
        armor_ = armor;
        if(armor_ <= 0) {sunk_ = true;}
    }
    void setCenter(Position center) {center_ = center;}
    void setOrientation(char orientation) {orientation_ = orientation;}

    //Pure virtual function that will be overrided by the subclasses
    virtual void action() = 0;
};

Ship::~Ship(){}

#endif
