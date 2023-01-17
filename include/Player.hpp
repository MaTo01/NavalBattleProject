//2032496 Veronica Cisotto
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.h"
#include <iostream>

void Player::viewGrids(std::ostream& os){
    os << "\t\t\t    Attack grid:" << std::endl;
    attackGrid_->printGrid(os);
    os << "\t\t\t    Defense grid:" << std::endl;
    defenseGrid_->printGrid(os);    
}

#endif
