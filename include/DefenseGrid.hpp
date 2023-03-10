//2032460 Van Sang Ho
#ifndef DEFENSEGRID_HPP
#define DEFENSEGRID_HPP

#include "DefenseGrid.h"

//Resets all unique_ptrs and empties the ships_ vector
DefenseGrid::~DefenseGrid() {
    for(auto & s : ships_) {
        s.reset();
    }
    ships_.clear();
}


bool DefenseGrid::isShipAtPosition(Position pos) {
    if(isPosValid(pos)) {
        return (tiles_[pos.getX()][pos.getY()] != ' ');
    } else {
        //If pos is invalid, an std::out_of_range exception is thrown which must be handled by the caller
        throw std::out_of_range("Position out of bounds.");
    }
}

/*
If pos matches the center of one of the DefenseGrid's Ships, the function returns a raw pointer to said Ship.
Otherwise if pos is invalid or there is no Ship with that center, the functions returns a nullptr.
*/
Ship* DefenseGrid::getShipByCenter(Position pos) {
    if(isPosValid(pos)) {
        
        for(auto & s : ships_) {
            if(s->getCenter() == pos)
                return s.get();         
        }
    }
    return nullptr;
}

/*  
If there is a Ship at the Position indicated by pos, the function checks the Positions occupied 
by all Ships in the DefenseGrid until it finds the one needed, and returns a raw pointer to it.
If no such Ship exists or at least one of the required Positions is out of bounds, a nullptr is returned.
*/
Ship* DefenseGrid::getShipByPosition(Position pos) {
    try {
        if(isShipAtPosition(pos)) {
            std::vector<Position> positions;
            for(auto & s : ships_) {
                positions = getTilesByShip(s.get());
                for(auto p : positions) {
                    if(p == pos)
                        return s.get();     
                }
            }
        }
    } catch (const std::out_of_range& e) {
        return nullptr;
    } 
    return nullptr;
}

Ship* DefenseGrid::getShipByIndex(int n) {
    if(n < 0 || n > ships_.size())
        return nullptr;
    return ships_[n].get();
}

std::vector<Position> DefenseGrid::getTilesForPlacement(int size, char orientation, Position pos) {
    //number of tiles on each side of the center that the Ship occupies
    int shiftSize = size / 2;
    //vector of Positions that will be "allocated" for a Ship
    std::vector<Position> positions;
    Position aux;

    try {
        switch (orientation) {
            case 'H':
                for(int y = pos.getY() - shiftSize; y <= pos.getY() + shiftSize; y++) {
                    aux = Position(pos.getX(), y);
                    if(!isShipAtPosition(aux)){
                        positions.push_back(aux);
                    } else {
                        throw std::invalid_argument("Invalid ship placement.");
                    }      
                }
                break;
            case 'V': 
                for(int x = pos.getX() - shiftSize; x <= pos.getX() + shiftSize; x++) {
                    aux = Position(x, pos.getY());
                    if(!isShipAtPosition(aux)){
                        positions.push_back(aux);
                    } else {
                        throw std::invalid_argument("Invalid ship placement.");
                    }
                }
                break;
            default:        //a Ship is considered neither vertical nor horizontal if it has size 1
                if(!isShipAtPosition(pos)){
                    positions.push_back(pos);
                } else {
                    throw std::invalid_argument("Invalid ship placement.");
                }
                break;
        }
    } catch(const std::exception& e) {
        //If any one of the required Positions is not valid (out of bounds or already occupied),
        //the function returns an empty vector
        return std::vector<Position>();
    }

    return positions;
}

std::vector<Position> DefenseGrid::getTilesByShip(Ship* ship) {  
    //number of tiles on each side of the center that the Ship occupies
    int shiftSize = ship->getSize() / 2;
    Position center = ship->getCenter();
    //vector of Positions occupied by the Ship
    std::vector<Position> positions;

    //The positions vector is filled based on the Ship's orientation
    switch (ship->getOrientation()) {
        case 'H': 
            for(int y = center.getY() - shiftSize; y <= center.getY() + shiftSize; y++) {
                positions.push_back(Position(center.getX(), y));
            }
            break;
        case 'V': 
            for(int x = center.getX() - shiftSize; x <= center.getX() + shiftSize; x++) {
                positions.push_back(Position(x, center.getY()));
            }
            break;
        default:    
            //a Ship is considered neither vertical nor horizontal if it has size 1, 
            //hence the only position it occupies is its own center
            positions.push_back(center);
            break;
    }

    return positions;
}

void DefenseGrid::placeShip(std::unique_ptr<Ship> ship) {
    //"Allocates" the Positions required to add the Ship to the DefenseGrid
    //If positions is not empty, the Ship can be added
    std::vector<Position> positions = getTilesForPlacement(ship->getSize(), ship->getOrientation(), ship->getCenter());
    if(positions.size() > 0) {
        //"Logically" adds the Ship by updating the DefenseGrid's tiles
        for(auto p : positions) {
            tiles_[p.getX()][p.getY()] = ship->getGridCharacter();
        }
        //"Physically" adds the Ship to the list of the DefenseGrid's Ships
        //and transfers ownership of the unique_ptr to the DefenseGrid via std::move
        ships_.push_back(std::move(ship));
    } else {
        throw std::invalid_argument("Invalid ship placement.");
    }
}

void DefenseGrid::moveShip(Ship* ship, Position pos) {
    if(ship) {
        //Fetches the Positions occupied by the Ship
        //If oldPositions is empty, the Ship does not exist within the DefenseGrid
        std::vector<Position> oldPositions = getTilesByShip(ship);
        //This vector is used to store whether the Ship has been hit on each of its Positions
        std::vector<bool> arePositionsHit;

        if(oldPositions.size() > 0) {
            //Checks if the Ship has been hit on any of the tiles it occupies before moving
            for(auto p : oldPositions) {
                if(islower(tiles_[p.getX()][p.getY()])) {
                    arePositionsHit.push_back(true);
                } else {
                    arePositionsHit.push_back(false);
                }
            }
            //"Logically" removes the Ship from the DefenseGrid by clearing its old Positions
            for(auto p : oldPositions) {
                tiles_[p.getX()][p.getY()] = ' ';
            }
        } else {
            throw std::invalid_argument("No ship in this position.");
        }

        //"Allocates" a new set of Positions to move the Ship in
        std::vector<Position> newPositions = getTilesForPlacement(ship->getSize(), ship->getOrientation(), pos);
        Position p;
        if(newPositions.size() > 0) {           
            //"Logically" adds the Ship back to the DefenseGrid and updates its center
            for(int i = 0; i < newPositions.size(); i++) {
                p = newPositions[i];
                tiles_[p.getX()][p.getY()] = ship->getGridCharacter();
                //If the ship was hit on any of its tiles, the hits are marked again on the new Positions
                if(arePositionsHit[i]) {
                    tiles_[p.getX()][p.getY()] = tolower(tiles_[p.getX()][p.getY()]);
                }
            }
            ship->setCenter(pos);
        } else {
            //If the Ship cannot be moved (due to any of the newPositions being occupied or invalid),
            //it is restored to its old Positions
            for(int i = 0; i < oldPositions.size(); i++) {
                p = oldPositions[i];
                tiles_[p.getX()][p.getY()] = ship->getGridCharacter();
                //The hits it received are also restored
                if(arePositionsHit[i]) {
                    tiles_[p.getX()][p.getY()] = tolower(tiles_[p.getX()][p.getY()]);
                }
            }
            throw std::invalid_argument("Invalid ship placement.");
        }
    } else {
        throw std::invalid_argument("Ship must exist.");
    }
}

void DefenseGrid::removeShip(Ship* ship) {
    //Fetches the Positions occupied by the Ship
    //If positions is empty, the Ship does not exist within the DefenseGrid
    std::vector<Position> positions = getTilesByShip(ship);
    if(positions.size() > 0) {
        //"Logically" removes the Ship from the DefenseGrid by clearing its old Positions
        for(auto p : positions) {
            tiles_[p.getX()][p.getY()] = ' ';
        }
        //"Physically" removes the Ship by resetting its unique_ptr and erasing it from the vector
        int i = 0;
        for(auto & s : ships_) {
            if(s.get() == ship) {
                ships_[i].reset();
                ships_.erase(ships_.begin() + i);
                break;
            } else {
                i++;
            }
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }
}

void DefenseGrid::markShipAsHit(Position pos) {
    //If a Ship exists at the given Position and it hasn't already received a hit there, 
    //the DefenseGrid is updated to mark a hit, the Ship's armor value is updated and, if it's sunk, 
    //the Ship is removed from the DefenseGrid
    if(Ship* ship = getShipByPosition(pos)){
        if(!islower(tiles_[pos.getX()][pos.getY()])) {
            tiles_[pos.getX()][pos.getY()] = tolower(tiles_[pos.getX()][pos.getY()]);
            ship->setArmor(ship->getArmor() - 1);
            if(ship->isSunk()) {
                removeShip(ship);
            }
        }
    } else {
        throw std::invalid_argument("No ship in this position.");
    }
}

void DefenseGrid::repairShip(Position pos) {
    //If a Ship exists at the given Position, all hits it has received are reverted
    //and its armor value is restored to full
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