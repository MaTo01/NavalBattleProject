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
    int battleshipCounter, supportShipCounter, submarineCounter;
    DefenseGrid *defenseGrid_;
    AttackGrid *attackGrid_;
    std::ofstream logFile;
    
public:
    //Constructor
    Computer(DefenseGrid *defenseGrid, AttackGrid *attackGrid):
        battleshipCounter{0}, supportShipCounter{0}, submarineCounter{0}, defenseGrid_{defenseGrid}, attackGrid_{attackGrid}{
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