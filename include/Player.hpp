#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Player.h"
#include <iostream>

void Player::placeShips(DefenseGrid* enemyDefenseGrid){
    enemyDefenseGrid_ = enemyDefenseGrid;
    for(int i=1; i<=nBattleships; i++){
        try{
          std::cout << "Inserire coordinate per la corazzata n. " << i << ":" << std::endl;
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
            std::cerr << e.what() << "Coordinate non valide.Riprovare" << '\n';
            i--;
        }
        
        
    }
    for(int i=1; i<=nSupportShips; i++){
        try{
            std::cout << "Inserire coordinate per la nave di supporto n. " << i << ":" << std::endl;
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
            std::cerr << e.what() << "Coordinate non valide.Riprovare" << '\n';
            i--;
        }
    }
    for(int i=1; i<=nSubmarines; i++){
        try{
        std::cout << "Inserire coordinate per il sottomarino n. " << i << ":" << std::endl;
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
            std::cerr << e.what() << "Coordinate non valide.Riprovare" << '\n';
            i--;
        }
    }
    defenseGrid_->printGrid(std::cout);
}

void Player::execute(){
    char centerX;
    int centerY;
    char targetX;
    int tragetY;
    std::cout << "Selezionare nave e obiettivo:" << std::endl;
    std::cin >> centerX >> centerY >> targetX >> tragetY;
    Position center(Position::letterToNumber(centerX), centerY-1);
    Position target(Position::letterToNumber(targetX), tragetY-1);
    defenseGrid_->getShipByCenter(center)->action(target, enemyDefenseGrid_);
}

#endif
