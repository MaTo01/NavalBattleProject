//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include "Player.h"

class HumanPlayer : public Player{
public:
    HumanPlayer() : Player() {}
    ~HumanPlayer() override = default;
    
    void placeShips() override;
    void execute() override;   

};

#include "HumanPlayer.hpp"

#endif
