//2043414 Marco Toffoletto
#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <random>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

class Computer : public Player {
private:
    static constexpr int BattleshipSize_ = 5;
    static constexpr int SupportShipSize_ = 3;
    static constexpr int SubmarineSize_ = 1;
    int shipCounter_ = 0;

public:
    //Constructor
    Computer(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut) 
        : Player(rows, cols, nBattleships, nSupportShips, nSubmarines, fileOut) { srand(time(NULL)); }
    //Destructor
    ~Computer() override = default;

    void placeShips(char playerID, std::string command = "") override;
    void execute(std::string command = "") override;

};

#include "Computer.hpp"

#endif
