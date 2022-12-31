//2043414 Marco Toffoletto
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

class Battleship : public Ship{
private:

public:
    //Constructor
    Battleship(): Ship(5,5){}
    //Destructor
    ~Battleship() override = default;
    
    void action(Position pos, vector<Ship*>& enemyShip) override;
};

#include "Battleship.hpp"

#endif