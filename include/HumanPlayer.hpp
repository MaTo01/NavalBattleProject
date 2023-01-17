//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "HumanPlayer.h"
#include <iostream>

void HumanPlayer::placeShips(std::string command){
    for(int i=1; i<=nBattleships_; i++){
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
            std::cerr << e.what() << "Try again" << '\n';
            i--;
        }   
    }
    for(int i=1; i<=nSupportShips_; i++){
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
            std::cerr << e.what() << "Try again" << '\n';
            i--;
        }
    }
    for(int i=1; i<=nSubmarines_; i++){
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
            std::cerr << e.what() << "Try again" << '\n';
            i--;
        }
    }
    defenseGrid_->printGrid(std::cout);
}

void HumanPlayer::execute(std::string command){
    std::string centre;
    std::string target;
    std::cout << "Command XX XX to see the grids; command AA AA to delete preview scans from the attack grid." << std::endl;
    std::cout << "Otherwise select ship by its center and target:" << std::endl;
    std::cin >> centre;
    std::cin.get();
    std::cin >> target;
    if(centre != target){
        try{
            char centerX = centre.at(0);
            int centerY = std::stoi(centre.substr(1));
            char targetX = target.at(0);
            int targetY = std::stoi(target.substr(1));
            Position center(Position::letterToNumber(centerX), centerY-1);
            Position target(Position::letterToNumber(targetX), targetY-1);
            defenseGrid_->getShipByCenter(center)->action(target, enemyDefenseGrid_);
        }
        catch(std::invalid_argument& e){
            std::cerr << e.what() << "Try again" << '\n';
            execute();
        }
    }
    else{
        try{
            if(centre=="AA"){
                clearAttackGridScans();
                execute();
            }
            if(centre=="XX"){
                //viewGrids();
                execute();
            }
            else {throw std::invalid_argument("Invalid command. Try again");}
        }
        catch(std::invalid_argument& e) {execute();}
    }
}

#endif
