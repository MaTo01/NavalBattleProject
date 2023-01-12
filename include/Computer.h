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
    const int maxBattleships_;
    const int maxSupportShips_;
    const int maxSubmarines_;
    DefenseGrid *defenseGrid_;
    AttackGrid *attackGrid_;
    std::ofstream logFile;
    
public:
    //Constructor
    Computer(const int bNum, const int ssNum, const int sNum, DefenseGrid *defenseGrid, AttackGrid *attackGrid):
        maxBattleships_{bNum}, maxSupportShips_{ssNum}, maxSubmarines_{sNum}, defenseGrid_{defenseGrid}, attackGrid_{attackGrid}{
            logFile.open("log.txt");
            srand ( time(NULL) );
        }
    //Destructor
    ~Computer() {
        logFile.close();
    }

    //Member functions
    void placeShips();
    void performAction();
};

#include "Computer.hpp"

#endif