//2043414 Marco Toffoletto
#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <random>
#include <memory>
#include <iostream>
#include <fstream>

class Computer : public Player {
private:
    static constexpr int BattleshipSize_ = 5;
    static constexpr int SupportShipSize_ = 3;
    static constexpr int SubmarineSize_ = 1;

public:
    //Constructor
    Computer(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines) 
        : Player(rows, cols, nBattleships, nSupportShips, nSubmarines) { srand(time(NULL)); }
    //Destructor
    ~Computer() override = default;

    void placeShips() override;
    void execute() override;

};

#include "Computer.hpp"

#endif
