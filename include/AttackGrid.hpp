//2032460 Van Sang Ho
#ifndef ATTACKGRID_HPP
#define ATTACKGRID_HPP

#include "AttackGrid.h"

void AttackGrid::markHit(Position p) { 
    if(isPosValid(p)) {
        tiles[p.getX()][p.getY()] = 'X'; 
    }  
}

void AttackGrid::markMiss(Position p) { 
    if(isPosValid(p)) {
        tiles[p.getX()][p.getY()] = 'O'; 
    }  
}

void AttackGrid::markScan(Position p) { 
    if(isPosValid(p)) {
        tiles[p.getX()][p.getY()] = 'Y'; 
    }  
}

bool AttackGrid::isAlreadyMarked(Position p) {
    if(isPosValid(p)) {
        return (tiles[p.getX()][p.getY()] != ' '); 
    }  
}

#endif