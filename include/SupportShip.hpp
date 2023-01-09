//2043414 Marco Toffoletto
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
void SupportShip::action(Position pos, DefenseGrid *enemyDefenseGrid){
    //TODO: DefenseGrid function to check if there is a ship at that position 
    if(defenseGrid_->isShipAtPosition(pos)){
        throw std::invalid_argument("Cell position already occupied!");
    }else{
        Ship *ship = defenseGrid_->getShipAtPosition(pos);
        defenseGrid_->moveShip(ship, pos); //TODO: grid member function to update ship position
        for (int i = pos.getX() - 1; i <= pos.getX() + 1; i++) {
            for (int j = pos.getY() - 1; j <= pos.getY() + 1; j++) {
                if (ship && ship->getArmor() < ship->getSize()) {
                    ship->setArmor(ship->getSize());
                }
            }
        }
    }
}

#endif
