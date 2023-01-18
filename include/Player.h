//2032496 Veronica Cisotto
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <memory>
#include <fstream>
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
    std::ofstream& fileOut_;

public:
    //Constructor
    Player(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut) 
        : rows_{rows}, cols_{cols}, nBattleships_{nBattleships}, nSupportShips_{nSupportShips}, nSubmarines_{nSubmarines}, 
        fileOut_{fileOut}, attackGrid_{new AttackGrid(rows_, cols_)}, defenseGrid_{new DefenseGrid(rows_, cols_)} {}
    //Virtual destructor
    virtual ~Player(){}

    //Member functions
    DefenseGrid* getDefenseGrid() const { return defenseGrid_; }
    void setEnemyDefenseGrid(DefenseGrid* enemyDefenseGrid) { enemyDefenseGrid_ = enemyDefenseGrid; }

    void viewGrids(std::ostream& os);
    void clearAttackGridScans() { attackGrid_->clearScans(); }
    bool isWinner() { return enemyDefenseGrid_->isGridEmpty(); }

    //Pure virtual function that represents the action of a 
    //player and will be overridden by the subclasses as needed
    virtual void placeShips(std::string command = "") = 0;
    virtual void execute(std::string command = "") = 0;
};

#include "Player.hpp"

#endif
