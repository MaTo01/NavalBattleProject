//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include "Player.h"

class HumanPlayer : public Player{
public:
    HumanPlayer(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut) 
        : Player(rows, cols, nBattleships, nSupportShips, nSubmarines, fileOut) {}
    ~HumanPlayer() override = default;

    void placeShips(std::string command = "") override;
    void execute(std::string command = "") override;

};

#include "HumanPlayer.hpp"

#endif
