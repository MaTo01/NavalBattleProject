#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include "AttackGrid.h"
#include "DefenseGrid.h"
#include "Ship.h"
#include "Battleship.h"
#include "SupportShip.h"
#include "Submarine.h"

class Player {
private:
    AttackGrid attackGrid;
    DefenseGrid defenseGrid;

public:
    Player();
    ~Player() = default;

};

#include "Player.hpp"

#endif