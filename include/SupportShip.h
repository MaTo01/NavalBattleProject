//2043414 Marco Toffoletto
#ifndef SUPPORTSHIP_H
#define SUPPORTSHIP_H

#include "Ship.h"

//Ship's subclass
class SupportShip : public Ship {
private:
    //Pointer to the player's defense grid, used to move the support ship
    DefenseGrid *defenseGrid_;
public:
    //Constructor
    SupportShip(Position bow, Position stern, DefenseGrid *defenseGrid)
        : Ship(3, bow, stern, 'S'), defenseGrid_{defenseGrid} {}
    //Destructor override
    ~SupportShip() override = default;

    //Ship's virtual function override
    void action(Position pos, DefenseGrid * enemyDefenseGrid = nullptr) override; 
};

#include "SupportShip.hpp"

#endif
