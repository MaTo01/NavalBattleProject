//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <regex>
#include "Player.h"

/*
Real life player (someone who writes from the command line every instruction)
*/
class HumanPlayer : public Player{
public:
    //Constructor
    HumanPlayer(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut) 
        : Player(rows, cols, nBattleships, nSupportShips, nSubmarines, fileOut) {}
    //Default destructor
    ~HumanPlayer() = default;

    void placeShips(char playerID, std::string command = "") override;
    void execute(std::string command = "") override;

};

#include "HumanPlayer.hpp"

#endif
