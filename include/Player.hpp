//2032496 Veronica Cisotto
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.h"
#include <iostream>

void Player::viewGrids(){
    std::cout << "\t\t\t\tAttack grid:" << std::endl;
    attackGrid_->printGrid(std::cout);
    std::cout << "\t\t\t\tDefense grid:" << std::endl;
    defenseGrid_->printGrid(std::cout);    
}

#endif
