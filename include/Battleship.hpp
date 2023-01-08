//2043414 Marco Toffoletto
#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "Battleship.h"

/*
The battleship can fire in any position of the grid, 
but it can't move. If the position of the grid where it 
will fire is occupied, the attack grid will be 
marked with a X at that position using "shipHitAt(Position pos)"
Otherwise, the attack grid will be marked with a O at that
position using "shipMissedAt(Position pos)"
*/
void Battleship::action(Position pos, DefenseGrid *enemyDefenseGrid = NULL){
    //TODO: DefenseGrid function to check if there is a ship at that position 
    if(enemyDefenseGrid->isShip(pos)){ 
        //TODO: AttackGrid function to check if the position had been already hit
        if(attackGrid_->isPosHit(pos)){
            break; //Position already marked, stop the action
        }else{
            attackGrid_->markHit(pos);
            Ship *ship = enemyDefenseGrid->getShip(pos); //TODO: DefenseGrid function to get the type of ship at that position 
            ship->setArmor(ship->getArmor()-1);
            if(ship->isSunk()){
                enemyDefenseGrid->eraseShip(); //TODO: DefenseGrid function to erase the ship from the grid if sunk
            }
        }
    }else{
        attackGrid_->markMiss(pos);
    }
}

#endif