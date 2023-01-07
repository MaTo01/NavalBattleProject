#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include "Grid.h"
#include "Ship.h"
#include "Battleship.h"
#include "SupportShip.h"
#include "Submarine.h"

class Player {
private:
    Grid attackGrid;
    Grid defenseGrid;
    std::vector<std::unique_ptr<Ship>> ships;

public:
    Player();
    ~Player() = default;

};

#include "Player.hpp"

#endif