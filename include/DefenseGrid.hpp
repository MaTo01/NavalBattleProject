//2032460 Van Sang Ho
#ifndef DEFENSEGRID_HPP
#define DEFENSEGRID_HPP

#include "DefenseGrid.h"

DefenseGrid::~DefenseGrid() {
    for(auto s : ships_) {
        delete s;
    }
    ships_.clear();
}

bool DefenseGrid::isShipAtPosition(Position pos) {
    if(isPosValid(pos)) {
        return (tiles_[pos.getX()][pos.getY()] != ' '); 
    }
    return false;
}

Ship* DefenseGrid::getShipByCenter(Position pos) {
    if(isPosValid(pos)) {
        for(auto s : ships_) {
            if(s->getCenter() == pos)
                return s;
        }
    }
    return nullptr;
}

Ship* DefenseGrid::getShipByPosition(Position pos) {
    if(isShipAtPosition(pos)) {
        std::vector<Position> positions;
        for(auto s : ships_) {
            positions = getTilesByShip(s);
            for(auto p : positions) {
                if(p == pos)
                    return s;
            }
        }
    }
    return nullptr;
}

std::vector<Position> DefenseGrid::getTilesForPlacement(int size, char orientation, Position pos) {
    int shiftSize = size / 2;
    std::vector<Position> positions;
    Position aux;

    if(orientation == 'H') {
        for(int y = pos.getY() - shiftSize; y <= pos.getY() + shiftSize; y++) {
            aux = Position(pos.getX(), y);
            if(!isShipAtPosition(aux)){
                positions.push_back(aux);
            } else {
                return std::vector<Position>();
            }
        }
    } else {
        for(int x = pos.getX() - shiftSize; x <= pos.getX() + shiftSize; x++) {
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

std::vector<Position> DefenseGrid::getTilesByShip(Ship* ship) {
    if(!isShipAtPosition(ship->getCenter()))
        return std::vector<Position>();
    
    int shiftSize = ship->getSize() / 2;
    Position center = ship->getCenter();
    std::vector<Position> positions;

    if(ship->getOrientation() == 'H') {
        for(int y = center.getY() - shiftSize; y <= center.getY() + shiftSize; y++) {
            positions.push_back(Position(center.getX(), y));
        }
    } else {
        for(int x = center.getX() - shiftSize; x <= center.getX() + shiftSize; x++) {
            positions.push_back(Position(x, center.getY()));
        }
    }

    return positions;
}

void DefenseGrid::placeShip(Ship* ship) {
    std::vector<Position> positions = getTilesForPlacement(ship->getSize(), ship->getOrientation(), ship->getCenter());
    if(positions.size() > 0) {
        for(auto p : positions) {
            tiles_[p.getX()][p.getY()] = ship->getGridCharacter();
        }
        ships_.push_back(ship);
    } else {
        throw std::invalid_argument("Invalid ship placement.");
    }
}

void DefenseGrid::moveShip(Ship* ship, Position pos) {
    std::vector<Position> oldPositions = getTilesByShip(ship);
    if(oldPositions.size() > 0) {
        for(auto p : oldPositions) {
            tiles_[p.getX()][p.getY()] = ' ';
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }

    std::vector<Position> newPositions = getTilesForPlacement(ship->getSize(), ship->getOrientation(), pos);
    if(newPositions.size() > 0) {
        for(auto p : newPositions) {
            tiles_[p.getX()][p.getY()] = ship->getGridCharacter();
        }
        ship->setCenter(pos);
    } else {
        for(auto p : oldPositions) {
            tiles_[p.getX()][p.getY()] = ship->getGridCharacter();
        }
        throw std::invalid_argument("Invalid ship placement.");
    }
}

void DefenseGrid::removeShip(Ship* ship) {
    std::vector<Position> positions = getTilesByShip(ship);
    if(positions.size() > 0) {
        for(auto p : positions) {
            tiles_[p.getX()][p.getY()] = ' ';
        }
        int i = 0;
        for(std::vector<Ship*>::iterator it = ships_.begin(); it != ships_.end(); it++, i++) {
            if(ships_[i] == ship) {
                delete ships_[i];
                ships_.erase(it);
                break;
            }
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }
}

void DefenseGrid::markShipAsHit(Position pos) {
    if(Ship* ship = getShipByPosition(pos)){
        tiles_[pos.getX()][pos.getY()] = tolower(tiles_[pos.getX()][pos.getY()]);
        ship->setArmor(ship->getArmor() - 1);
        if(ship->isSunk()) {
            removeShip(ship);
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }
}

void DefenseGrid::repairShip(Position pos) {
    if(Ship* ship = getShipByPosition(pos)){
        std::vector<Position> positions = getTilesByShip(ship);
        for(auto p : positions) {
            tiles_[p.getX()][p.getY()] = toupper(tiles_[p.getX()][p.getY()]);
        }
        ship->setArmor(ship->getSize());
    } else {
        throw std::invalid_argument("No ship in this position.");
    }
}

#endif