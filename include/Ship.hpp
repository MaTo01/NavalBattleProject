//2043414 Marco Toffoletto
#ifndef SHIP_HPP
#define SHIP_HPP

#include "Ship.h"

Ship::Ship(const int& size, int armor, Position bow, Position stern)
    : size_{size}, armor_{armor}, bow_{bow}, stern_{stern}{
        //If the x coordinates of bow and stern are the same, initialize the 
        //center of the ship and set the orientation to horizontal
        if(bow_.getX() == stern_.getX()) {
            center_ = Position(bow_.getX(),(bow_.getY()+stern_.getY())/2);
            orientation_ = 'H';
        //If the y coordinates of bow and stern are the same, initialize the 
        //center of the ship and set the orientation to vertical
        }else if(bow_.getY() == stern_.getY()){
            center_ = Position((bow_.getX()+stern_.getX())/2, bow_.getY());
            orientation_ = 'V';
        }
    }

#endif