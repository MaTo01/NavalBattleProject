#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include "AttackGrid.h"
#include "DefenseGrid.h"
#include "Battleship.h"
#include "SupportShip.h"
#include "Submarine.h"

class Player {
private:
    AttackGrid* attackGrid_;
    DefenseGrid* defenseGrid_;
    DefenseGrid* enemyDefenseGrid_;

    static constexpr int rows = 12;
    static constexpr int cols = 12;
    static constexpr int nBattleships = 3;
    static constexpr int nSupportShips = 3;
    static constexpr int nSubmarines = 2;

public:
    Player() : attackGrid_{new AttackGrid(rows, cols)}, defenseGrid_{new DefenseGrid(rows, cols)} {}
    ~Player() = default;
    
    DefenseGrid* getDefenseGrid() const {return defenseGrid_;}
    void placeShips(DefenseGrid* enemeyDefenseGrid);
    void execute();
    void printGrids(){
        attackGrid_->printGrid(std::cout);
        defenseGrid_->printGrid(std::cout);    
    }

};

#include "Player.hpp"

#endif
