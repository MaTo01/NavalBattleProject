//2043414 Marco Toffoletto
#ifndef SUPPORTSHIP_H
#define SUPPORTSHIP_H

#include "Ship.h"

class SupportShip : public Ship{
private:
    DefenseGrid *defenseGrid_;
public:
    //Constructor
    SupportShip(Position bow, Position stern, AttackGrid *attackGrid, DefenseGrid *defenseGrid)
        : Ship(3, 3, bow, stern), attackGrid_{attackGrid}, defenseGrid_{defenseGrid}{}
    //Destructor
    ~SupportShip() override = default;

    //Override of the virtual function of Ship
    void action(Position pos, DefenseGrid *enemyDefenseGrid = NULL) override;
};

#include "SupportShip.hpp"

#endif
