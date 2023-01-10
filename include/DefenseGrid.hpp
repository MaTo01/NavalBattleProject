#ifndef DEFENSEGRID_HPP
#define DEFENSEGRID_HPP

#include "DefenseGrid.h"

bool DefenseGrid::isShipAtPosition(Position pos) {
    if(isPosValid(pos)) {
        return (tiles[pos.getX()][pos.getY()] != ' '); 
    }
}

Ship* DefenseGrid::getShipAtPosition(Position pos) {
    for(auto s : ships) {
        if(s->getCenter() == pos)
            return s;
    }
    return nullptr;
}

std::vector<Position> DefenseGrid::getTilesForPlacement(int size, char orientation, Position pos) {
    int shiftSize = size / 2;
    std::vector<Position> positions;
    Position aux;

    if(orientation == 'H') {
        for(int y = pos.getY() - shiftSize; y < pos.getY() + shiftSize; y++) {
            aux = Position(pos.getX(), y);
            if(!isShipAtPosition(aux)){
                positions.push_back(aux);
            } else {
                return std::vector<Position>();
            }
        }     
    } else {
        for(int x = pos.getX() - shiftSize; x < pos.getX() + shiftSize; x++) {
            aux = Position(x, pos.getY());
            if(!isShipAtPosition(aux)){
                positions.push_back(aux);
            } else {
                return std::vector<Position>();
            }
        }
    }

    return positions;
}

std::vector<Position> DefenseGrid::getTilesForShip(Ship* ship) {
    if(!isShipAtPosition(ship->getCenter()))
        return std::vector<Position>();
    
    int shiftSize = ship->getSize() / 2;
    Position center = ship->getCenter();
    std::vector<Position> positions;

    if(ship->getOrientation() == 'H') {
        for(int y = center.getY() - shiftSize; y < center.getY() + shiftSize; y++) {
            positions.push_back(Position(center.getX(), y));
        }
    } else {
        for(int x = center.getX() - shiftSize; x < center.getX() + shiftSize; x++) {
            positions.push_back(Position(x, center.getY()));
        }
    }

    return positions;
}

void DefenseGrid::placeShip(Ship* ship) {
    std::vector<Position> positions = getTilesForPlacement(ship->getSize(), ship->getOrientation(), ship->getCenter());
    if(positions.size() > 0) {
        for(auto p : positions) {
            tiles[p.getX()][p.getY()] = ship->getGridCharacter();
        }
        ships.push_back(ship);
    } else {
        throw std::invalid_argument("Invalid ship placement.");
    }
}

void DefenseGrid::moveShip(Ship* ship, Position pos) {
    std::vector<Position> positions = getTilesForShip(ship);
    if(positions.size() > 0) {
        for(auto p : positions) {
            tiles[p.getX()][p.getY()] = ' ';
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }

    positions = getTilesForPlacement(ship->getSize(), ship->getOrientation(), pos);
    if(positions.size() > 0) {
        for(auto p : positions) {
            tiles[p.getX()][p.getY()] = ship->getGridCharacter();
        }
        ship->setCenter(pos);
    } else {
        throw std::invalid_argument("Invalid ship placement.");
    }
}

void DefenseGrid::removeShip(Ship* ship) {
    std::vector<Position> positions = getTilesForShip(ship);
    if(positions.size() > 0) {
        for(auto p : positions) {
            tiles[p.getX()][p.getY()] = ' ';
        }
        int i = 0;
        for(std::vector<Ship*>::iterator it = ships.begin(); it != ships.end(); it++, i++) {
            if(ships[i] == ship) {
                ships.erase(it);
                break;
            }
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }
}

void DefenseGrid::markShipAsHit(Position pos) {
    if(!isShipAtPosition(pos)){
        throw std::invalid_argument("No ship in this position.");
    } else {
        tolower(tiles[pos.getX()][pos.getY()]);
    }
}

#endif