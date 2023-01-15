//2043414 Marco Toffoletto
#ifndef COMPUTER_H
#define COMPUTER_H

#include "Battleship.h"
#include "SupportShip.h"
#include "Submarine.h"
#include "DefenseGrid.h"
#include "AttackGrid.h"
#include <random>
#include <memory>
#include <fstream>

class Computer {
private:
    static constexpr int rows = 12;
    static constexpr int cols = 12;
    static constexpr int nBattleships = 3;
    static constexpr int nSupportShips = 3;
    static constexpr int nSubmarines = 2;
    static constexpr int BattleshipSize = 5;
    static constexpr int SupportShipSize = 3;
    static constexpr int SubmarineSize = 1;
    DefenseGrid *defenseGrid_;
    AttackGrid *attackGrid_;
    std::ofstream logFile;
    
public:
    //Constructor
    Computer() : attackGrid_{new AttackGrid(rows, cols)}, defenseGrid_{new DefenseGrid(rows, cols)} {}
    //Destructor
    ~Computer() {
        logFile.close();
    }
    
    //Member functions
    void placeShips(DefenseGrid* enemyDefenseGrid);
    void performAction();
    DefenseGrid* getDefenseGrid() const {return defenseGrid_;}
};

#include "Computer.hpp"

#endif
