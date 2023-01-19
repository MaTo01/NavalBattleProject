//2043414 Marco Toffoletto
#ifndef SUPPORTSHIP_HPP
#define SUPPORTSHIP_HPP

#include "SupportShip.h"

/*
The action performed by the support ship is to move and repair the ships present around it in the 
new position in which it is located: This is possible thanks to the "moveShip" function, which is
only called if the position where the support ship has to move is not the same as its current position,
and the "isShipAtPosition" function which checks if a ship is present in the 3*3 repair matrix.
As structured, the action call allows for the start of the repair without moving.
*/
void SupportShip::action(Position pos, DefenseGrid *enemyDefenseGrid) {
    if(this->getCenter() != pos) {
        defenseGrid_->moveShip(this, pos);
    }

    Ship* ship = nullptr;
    for (int i = pos.getX() - 1; i <= pos.getX() + 1; i++) {
        for (int j = pos.getY() - 1; j <= pos.getY() + 1; j++) {
            try {
                ship = defenseGrid_->getShipByPosition(Position(i,j));
                if (ship && ship != this && ship->getArmor() < ship->getSize()) {
                    defenseGrid_->repairShip(Position(i,j));
                }
            } catch(const std::out_of_range& e) {
                //this catch allows me to ignore the part of the matrix that goes out of the grid
                continue;
            }
        }
    }
}

#endif
