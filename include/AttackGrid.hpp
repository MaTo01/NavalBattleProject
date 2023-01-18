//2032460 Van Sang Ho
#ifndef ATTACKGRID_HPP
#define ATTACKGRID_HPP

#include "AttackGrid.h"

void AttackGrid::markHit(Position p) { 
    if(isPosValid(p)) {
        tiles_[p.getX()][p.getY()] = 'X'; 
    } else {
        throw std::invalid_argument("Invalid position.");
    }
}

void AttackGrid::markMiss(Position p) { 
    if(isPosValid(p)) {
        tiles_[p.getX()][p.getY()] = 'O'; 
    } else {
        throw std::invalid_argument("Invalid position.");
    }
}

void AttackGrid::markScan(Position p) { 
    if(isPosValid(p) && tiles_[p.getX()][p.getY()] == ' ') {
        tiles_[p.getX()][p.getY()] = 'Y'; 
    } else {
        throw std::invalid_argument("Invalid position.");
    }
}

bool AttackGrid::isAlreadyMarked(Position p) {
    if(isPosValid(p)) {
        return (tiles_[p.getX()][p.getY()] != ' ' && tiles_[p.getX()][p.getY()] != 'Y'); 
    } else {
        throw std::invalid_argument("Invalid position.");
    }
}

void AttackGrid::clearScans(){
    for(int i=0; i<tiles_.size(); i++){
        for(int j=0; j<tiles_[0].size(); j++){
            if(tiles_[i][j] == 'Y') 
                tiles_[i][j] = ' ';
        }
    }
}

#endif
