//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "HumanPlayer.h"
#include <iostream>

void HumanPlayer::placeShips(char playerID, std::string command){
    if(command==""){
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
                if(bowPos==sternPos) 
                    throw std::invalid_argument("Invalid coordinates for Battleship. ");
                defenseGrid_->placeShip(std::unique_ptr<Ship>(new Battleship(bowPos, sternPos, attackGrid_)));
                fileOut_ << playerID << " " << bowX << bowY << " " << sternX << sternY << std::endl;
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
                if(bowPos==sternPos) 
                    throw std::invalid_argument("Invalid coordinates for SupportShip. ");
                defenseGrid_->placeShip(std::unique_ptr<Ship>(new SupportShip(bowPos, sternPos, defenseGrid_)));
                fileOut_ << playerID << " " << bowX << bowY << " " << sternX << sternY << std::endl;
            }
            catch(const std::invalid_argument& e){
                std::cerr << e.what() << " Try again" << '\n';
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
                if(bowPos!=sternPos) 
                    throw std::invalid_argument("Invalid coordinates for Submarine. ");
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(bowPos, sternPos, attackGrid_, defenseGrid_)));
                fileOut_ << playerID << " " << bowX << bowY << " " << sternX << sternY << std::endl;
            }
            catch(const std::invalid_argument& e){
                std::cerr << e.what() << " Try again" << '\n';
                i--;
            }
        }
    }
    else{
        std::string XYorigin = command.substr(0, command.find(" "));
        std::string XYtarget = command.substr(command.find(" ")+1);
        int bowX = Position::letterToNumber(XYorigin.at(0));
        int bowY = std::stoi(XYorigin.substr(1));
        int sternX = Position::letterToNumber(XYtarget.at(0));
        int sternY = std::stoi(XYtarget.substr(1));
        defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(Position(bowX, bowY-1), Position(sternX, sternY-1), attackGrid_)));
    }
}

void HumanPlayer::execute(std::string command){
    std::string centre;
    std::string target;
    std::cout << "Command XX XX to see the grids; command AA AA to delete preview scans from the attack grid." << std::endl;
    std::cout << "Otherwise select ship by its center and target:" << std::endl;
    bool flag = true;
    do {
        try {
            std::cin >> centre;
            std::cin.get();
            std::cin >> target;

            if(centre != target){
                char centerX = centre.at(0);
                int centerY = std::stoi(centre.substr(1));
                char targetX = target.at(0);
                int targetY = std::stoi(target.substr(1));
                Position center(Position::letterToNumber(centerX), centerY-1);
                Position target(Position::letterToNumber(targetX), targetY-1);
                
                Ship* ship = defenseGrid_->getShipByCenter(center);
                if(ship != nullptr) {
                    ship->action(target, enemyDefenseGrid_);
                    fileOut_ << centerX << centerY << " " << targetX << targetY << std::endl;
                    flag = false;
                } else {
                    throw std::invalid_argument("No ship with that center. ");
                }          
            } else {
                if(centre=="AA"){
                    clearAttackGridScans();
                    execute();
                }
                if(centre=="XX"){
                    viewGrids(std::cout);
                    execute();
                }
                else {
                    throw std::invalid_argument("Invalid command. ");
                }
            }    
        } catch(std::invalid_argument& e){
            std::cerr << e.what() << " Try again." << '\n';
        }
    } while (flag);
}

#endif