//2043414 Marco Toffoletto
#ifndef SHIP_HPP
#define SHIP_HPP

#include "Ship.h"

//Constructor definition
Ship::Ship(const int size, Position bow, Position stern, char gridCharacter)
    : size_{size}, armor_{size}, gridCharacter_{gridCharacter} {
    //The only ship that has equivalent stern and bow positions is the submarine,
    //which has no orientation and whose center is equivalent to any of its stern or bow positions.
    if(bow == stern && size_ == 1) {
        center_ = bow;
        orientation_ = '-';
    
    } 
    //If the stern and bow positions do not match, then the center of the ship is calculated based
    //on the coordinates of the two positions, and the orientation of the ship is set accordingly.
    //I also check the insertion of the two positions, in such a way as to be able to throw an error
    //if two positions are passed that would create a non-conforming ship size.
    else if(bow.getX() == stern.getX() && abs(bow.getY() - stern.getY()) == size_ - 1) {
        center_ = Position(bow.getX(), (bow.getY() + stern.getY()) / 2);
        orientation_ = 'H'; //H = horizontal
    } else if(bow.getY() == stern.getY() && abs(bow.getX() - stern.getX()) == size_ - 1) {
        center_ = Position((bow.getX() + stern.getX()) / 2, bow.getY());
        orientation_ = 'V'; //V = vertical
    } else throw std::invalid_argument("Invalid bow and stern positions.");
}

#endif