//2043414 Marco Toffoletto
#ifndef SUPPORTSHIP_HPP
#define SUPPORTSHIP_HPP

#include "SupportShip.h"

/*
The support ship can't fire, but it can move as long as 
it's not to a position that is already occupied (it can't 
go over any other ship, not even partially).
After moving, the support ship repairs the damaged ships 
in a matrix of 3*3 around its center.
*/
void SupportShip::action(Position pos, DefenseGrid *enemyDefenseGrid){
    defenseGrid_->moveShip(this, pos);
    Ship* ship = nullptr;
    for (int i = pos.getX() - 1; i <= pos.getX() + 1; i++) {
        for (int j = pos.getY() - 1; j <= pos.getY() + 1; j++) {
            try {
                ship = defenseGrid_->getShipByPosition(Position(i,j));
                if (ship && ship->getArmor() < ship->getSize()) {
                    defenseGrid_->repairShip(Position(i,j));
                }
            } catch(const std::out_of_range& e) {
                continue;
            }
        }
    }
}

#endif
