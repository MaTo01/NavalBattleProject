//2032496 Veronica Cisotto
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.h"
#include <iostream>

void Player::placeShips(){
    for(int i=1; i<=nBattleships; i++){
        try{
          std::cout << "Insert coordinates for battleship n. " << i << ":" << std::endl;
        char bowX;
        int bowY;
        char sternX;
        int sternY;
        std::cin >> bowX >> bowY >> sternX >> sternY;
        Position bowPos(Position::letterToNumber(bowX), bowY-1);
        Position sternPos(Position::letterToNumber(sternX), sternY-1);
        defenseGrid_->placeShip(std::unique_ptr<Ship>(new Battleship(bowPos, sternPos, attackGrid_)));  
        }
        catch(const std::invalid_argument& e){
            std::cerr << e.what() << "Invalid coordinates. Try again" << '\n';
            i--;
        }
        
        
    }
    for(int i=1; i<=nSupportShips; i++){
        try{
            std::cout << "Insert coordinates for support ship n. " << i << ":" << std::endl;
            char bowX;
            int bowY;
            char sternX;
            int sternY;
            std::cin >> bowX >> bowY >> sternX >> sternY;
            Position bowPos(Position::letterToNumber(bowX), bowY-1);
            Position sternPos(Position::letterToNumber(sternX), sternY-1);
            defenseGrid_->placeShip(std::unique_ptr<Ship>(new SupportShip(bowPos, sternPos, defenseGrid_)));
        }
        catch(const std::invalid_argument& e){
            std::cerr << e.what() << "Invalid coordinates. Try again" << '\n';
            i--;
        }
    }
    for(int i=1; i<=nSubmarines; i++){
        try{
        std::cout << "Insert coordinates for submarine n. " << i << ":" << std::endl;
        char bowX;
        int bowY;
        char sternX;
        int sternY;
        std::cin >> bowX >> bowY >> sternX >> sternY;
        Position bowPos(Position::letterToNumber(bowX), bowY-1);
        Position sternPos(Position::letterToNumber(sternX), sternY-1);
        defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(bowPos, sternPos, attackGrid_, defenseGrid_)));
        }
        catch(const std::invalid_argument& e){
            std::cerr << e.what() << "Invalid coordinates. Try again" << '\n';
            i--;
        }
    }
    defenseGrid_->printGrid(std::cout);
}

void Player::execute(){
    char centerX;
    int centerY;
    char targetX;
    int targetY;
    std::cout << "Select ship by its center and target:" << std::endl;
    try{
        std::cin >> centerX >> centerY >> targetX >> targetY;
        Position center(Position::letterToNumber(centerX), centerY-1);
        Position target(Position::letterToNumber(targetX), targetY-1);
        defenseGrid_->getShipByCenter(center)->action(target, enemyDefenseGrid_);
    }
    catch(std::invalid_argument& e){
        std::cerr << e.what() << "Invalid coordinates. Try again" << '\n';
        execute();
    }
}

void Player::viewGrids(){
        std::cout << "Attack grid:" << std::endl;
        attackGrid_->printGrid(std::cout);
        std::cout << "Defense grid:" << std::endl;
        defenseGrid_->printGrid(std::cout);    
}

#endif
