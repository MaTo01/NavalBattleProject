//2043414 Marco Toffoletto
#ifndef SHIP_HPP
#define SHIP_HPP

#include "Ship.h"

Ship::Ship(const int size, Position bow, Position stern, char gridCharacter)
    : size_{size}, armor_{size}, gridCharacter_{gridCharacter} {
    //The only ship that has the same bow and stern positon is the submarine, which
    //does not have an orientation and the center position is the same as bow or stern position
    if(bow == stern) {
        center_ = bow;
        orientation_ = '-';
    //If the x coordinates of bow and stern are the same, initialize the 
    //center of the ship and set the orientation to horizontal
    } else if(bow.getX() == stern.getX()) {
        center_ = Position(bow.getX(), (bow.getY() + stern.getY()) / 2);
        orientation_ = 'H';
    //If the y coordinates of bow and stern are the same, initialize the 
    //center of the ship and set the orientation to vertical
    } else if(bow.getY() == stern.getY()){
        center_ = Position((bow.getX() + stern.getX()) / 2, bow.getY());
        orientation_ = 'V';
    }
}

#endif