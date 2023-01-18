//2032496 Veronica Cisotto
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.h"
#include <iostream>

Player::Player(const int rows, const int cols, const int nBattleships, const int nSupportShips, const int nSubmarines, std::ofstream& fileOut) 
    : rows_{rows}, cols_{cols}, nBattleships_ {nBattleships}, nSupportShips_{nSupportShips}, nSubmarines_{nSubmarines}, fileOut_{fileOut} {
    attackGrid_ = std::unique_ptr<AttackGrid>(new AttackGrid(rows_, cols_));
    defenseGrid_ = std::unique_ptr<DefenseGrid>(new DefenseGrid(rows_, cols_));
}

Player::~Player() {
    attackGrid_.reset();
    defenseGrid_.reset();
    enemyDefenseGrid_ = nullptr;
}

void Player::viewGrids(std::ostream& os){
    os << "\t\t\t    Attack grid:" << std::endl;
    attackGrid_->printGrid(os);
    os << "\t\t\t    Defense grid:" << std::endl;
    defenseGrid_->printGrid(os);   
}

#endif
