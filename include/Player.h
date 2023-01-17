//2032496 Veronica Cisotto
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
protected:
    const int rows_;
    const int cols_;
    const int nBattleships_;
    const int nSupportShips_;
    const int nSubmarines_;
    DefenseGrid *defenseGrid_;
    AttackGrid* attackGrid_;
    DefenseGrid* enemyDefenseGrid_;

public:
    //Constructor
    Player(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines) 
        : attackGrid_{new AttackGrid(rows, cols)}, defenseGrid_{new DefenseGrid(rows, cols)}, 
        rows_{rows}, cols_{cols}, nBattleships_{nBattleships}, nSupportShips_{nSupportShips}, nSubmarines_{nSubmarines} {}
    //Virtual destructor
    virtual ~Player(){}

    //Member functions
    DefenseGrid* getDefenseGrid() const {return defenseGrid_;}
    void setEnemyDefenseGrid(DefenseGrid* enemyDefenseGrid) {enemyDefenseGrid=enemyDefenseGrid;}

    void viewGrids();
    void clearAttackGrid() {attackGrid_->clearGrid();}
    bool isWinner() {return enemyDefenseGrid_->isGridEmpty();}

    //Pure virtual function that represents the action of a 
    //player and will be overridden by the subclasses as needed
    virtual void placeShips() = 0;
    virtual void execute() = 0;
};

#include "Player.hpp"

#endif
