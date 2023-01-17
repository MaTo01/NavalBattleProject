//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include "Player.h"

class HumanPlayer : public Player{
public:
    HumanPlayer(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines) 
        : Player(rows, cols, nBattleships, nSupportShips, nSubmarines) {}
    ~HumanPlayer() override = default;

    void placeShips() override;
    void execute() override;

};

#include "HumanPlayer.hpp"

#endif
