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

class Player{
protected:
    static constexpr int rows_ = 12;
    static constexpr int cols_ = 12;
    static constexpr int nBattleships_ = 3;
    static constexpr int nSupportShips_ = 3;
    static constexpr int nSubmarines_ = 2;
    DefenseGrid *defenseGrid_;
    AttackGrid *attackGrid_;
    DefenseGrid* enemyDefenseGrid_;

public:
    //Constructors
    Player() : attackGrid_{new AttackGrid(rows_, cols_)}, defenseGrid_{new DefenseGrid(rows_, cols_)} {}
    //Virtual destructor
    virtual ~Player(){}
    
    //Member functions
    DefenseGrid* getDefenseGrid() const {return defenseGrid_;}
    void setEnemyDefenseGrid(DefenseGrid* enemyDefenseGrid) {enemyDefenseGrid_=enemyDefenseGrid;}
       
    void viewGrids();
    void clearAttackGrid() {attackGrid_->clearGrid();}
    bool isWinner() {return enemyDefenseGrid_->loseMatch();}
    
    //Pure virtual function that represents the action of a 
    //player and will be overridden by the subclasses as needed
    virtual void placeShips() = 0;
    virtual void execute() = 0;
};

#include "Player.hpp"

#endif
