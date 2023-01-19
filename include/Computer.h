//2043414 Marco Toffoletto
#ifndef COMPUTER_H
#define COMPUTER_H

#include <random>
#include "Player.h"

//Player's subclass
//It's also used to run the replay of a game
class Computer : public Player {
private:
    //Constants used to identify the size of different types of ships.
    static constexpr int BattleshipSize_ = 5;
    static constexpr int SupportShipSize_ = 3;
    static constexpr int SubmarineSize_ = 1;

    //Flag to check the number of units placed into the grid 
    int shipCounter_ = 0;

public:
    //Constructor
    Computer(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut) 
        : Player(rows, cols, nBattleships, nSupportShips, nSubmarines, fileOut) { srand(time(NULL)); }
    //Destructor
    ~Computer() = default;

    //Player's virtual functions override
    void placeShips(char playerID, std::string command = "") override;
    void execute(std::string command = "") override;

};

#include "Computer.hpp"

#endif
