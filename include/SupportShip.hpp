#ifndef SUPPORTSHIP_HPP
#define SUPPORTSHIP_HPP

#include "SupportShip.h"

/*
The support ship can't fire, but it can move towards
the same direction to which it is oriented, the only 
limitation is that it can't go in a position that is 
already occupied (it can't go over any other ship).
After moving, the support ship repairs the damaged ships 
in a matrix of 3*3 around it.
*/
void SupportShip::action(Position pos){
    if(grid_->isShipAt(pos)){
        break; //can't move there
    }else{
        //TODO: grid member function to update ship position
        for (int i = pos.getX() - 1; i <= pos.getX() + 1; i++) {
            for (int j = pos.getY() - 1; j <= pos.getY() + 1; j++) {
                Ship *ship = grid_->getShipAt(pos);
                if (ship && ship->getArmor() < ship->getSize()) {
                    ship->setArmor(ship->getArmor()+1);
                }
            }
        }
    }
}
#endif