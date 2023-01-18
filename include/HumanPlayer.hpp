//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "HumanPlayer.h"
#include <iostream>

void HumanPlayer::placeShips(char playerID, std::string command){
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
            defenseGrid_->placeShip(std::unique_ptr<Ship>(new Battleship(bowPos, sternPos, attackGrid_.get())));
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
            defenseGrid_->placeShip(std::unique_ptr<Ship>(new SupportShip(bowPos, sternPos, defenseGrid_.get())));
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
            defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(bowPos, sternPos, attackGrid_.get(), defenseGrid_.get())));
            fileOut_ << playerID << " " << bowX << bowY << " " << sternX << sternY << std::endl;
        }
        catch(const std::invalid_argument& e){
            std::cerr << e.what() << " Try again" << '\n';
            i--;
        }
    }
}

void HumanPlayer::execute(std::string command){
    std::string input;
    
    bool flag = true;
    do {
        try {
            std::cout << "Command XX XX to see the grids; command AA AA to delete preview scans from the attack grid." << std::endl;
            std::cout << "Otherwise select ship by its center and target:" << std::endl;     
            std::getline(std::cin, input);

            if(input == "AA AA") {
                clearAttackGridScans();
            } else if(input == "XX XX") {
                viewGrids(std::cout);
            } else {
                char centerX, targetX;
                int centerY, targetY;
                try {
                    centerX = input.at(0);
                    centerY = std::stoi(input.substr(1, input.find(" ")));
                    targetX = input.at(input.find(" ") + 1);
                    targetY = std::stoi(input.substr(input.find(" ") + 2));
                } catch(const std::invalid_argument& e) {
                    throw std::invalid_argument("Invalid command.");
                }

                Position center(Position::letterToNumber(centerX), centerY-1);
                Position target(Position::letterToNumber(targetX), targetY-1);
                Ship* ship = defenseGrid_->getShipByCenter(center);
                if(ship != nullptr) {
                    ship->action(target, enemyDefenseGrid_);
                    fileOut_ << centerX << centerY << " " << targetX << targetY;
                    flag = false;
                } else {
                    throw std::invalid_argument("No ship with that center.");
                }
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << " Try again.\n";
        }
    } while (flag);
}

#endif