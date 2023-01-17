//2032496 Veronica Cisotto
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.h"
#include <iostream>

void Player::viewGrids(){
        std::cout << "Attack grid:" << std::endl;
        attackGrid_->printGrid(std::cout);
        std::cout << "Defense grid:" << std::endl;
        defenseGrid_->printGrid(std::cout);    
}

#endif
