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

//Parent class that will be inherited by the other two classes
//that represent the two types of player
class Player {
protected:
    //number of rows and columns for the attack and defense grid
    const int rows_;
    const int cols_;
    //numeber of ship types that every player has
    const int nBattleships_;
    const int nSupportShips_;
    const int nSubmarines_;
    //unique pointers to player's attack and defense grids
    std::unique_ptr<DefenseGrid> defenseGrid_;
    std::unique_ptr<AttackGrid> attackGrid_;
    //pointer to player's enemy's defense grid
    DefenseGrid* enemyDefenseGrid_;
    //output stream which commands and the grids are
    //going to be recorded into
    std::ofstream& fileOut_;

public:
    //Constructor
    Player(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut);
    //Virtual destructor
    ~Player();

    //Member functions
    DefenseGrid* getDefenseGrid() const { return defenseGrid_.get(); }
    void setEnemyDefenseGrid(DefenseGrid* enemyDefenseGrid) { enemyDefenseGrid_ = enemyDefenseGrid; }
    //function to view player's grids
    void viewGrids(std::ostream& os);
    //additional command to delete all the previous scans from the attack grid
    //due to enemy moving his ships in their defense grid
    void clearAttackGridScans() { attackGrid_->clearScans(); }
    /*
    function to know if player is the winner of the match
    (player wins if they destroy every enemy ship, thus empting
    their defense grid)
    */
    bool isWinner() { return enemyDefenseGrid_->isGridEmpty(); }

    //Pure virtual function that represents the action of a 
    //player and will be overridden by the subclasses as needed
    virtual void placeShips(char playerID, std::string command = "") = 0;
    virtual void execute(std::string command = "") = 0;
};

#include "Player.hpp"

#endif
