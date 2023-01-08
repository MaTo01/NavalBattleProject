#ifndef DEFENSEGRID_HPP
#define DEFENSEGRID_HPP

#include "DefenseGrid.h"

bool DefenseGrid::isPosValid(Position p) {
    return Grid::isPosValid(p);
}

bool DefenseGrid::isShipAtPosition(Position p) {
    if(isPosValid(p)) {
        return (tiles[p.getX()][p.getY()] != ' '); 
    }
}

Ship* DefenseGrid::getShipAtPosition(Position p) {
    for(auto & ship : ships) {
        if(ship->getCenter() == p)
            return ship;
    }
    return nullptr;
}

void DefenseGrid::placeShip(Ship* s, Position p) {
    int shiftSize = s->getSize() / 2;
    if(s->getOrientation() == 'H') {
        for(int y=p.getY()-shiftSize; y<p.getY()+shiftSize; y++)
            if(!isPosValid(Position(p.getX(), y)))
                std::cout<<"dioboia";
        
        for(int y=p.getY()-shiftSize; y<p.getY()+shiftSize; y++)
            tiles[p.getX()][y] = s->getGridCharacter();
        ships.push_back(s);
    } else {
        for(int x=p.getX()-shiftSize; x<p.getX()+shiftSize; x++)
            if(!isPosValid(Position(x, p.getY())))
                std::cout<<"dioboia";

        for(int x=p.getX()-shiftSize; x<p.getX()+shiftSize; x++) 
            tiles[x][p.getY()] = s->getGridCharacter();
        ships.push_back(s);
    }
}

void DefenseGrid::moveShip(Ship* s, Position p) {
    
}

void DefenseGrid::removeShip(Ship* s) {
    
}

#endif