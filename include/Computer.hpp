//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Computer.h"

void Computer::placeShips(std::string command){
    if(command != ""){
        std::string XYorigin = command.substr(0, command.find(" "));
        std::string XYtarget = command.substr(command.find(" ")+1);

        int bowX = Position::letterToNumber(XYorigin.at(0));
        int bowY = std::stoi(XYorigin.substr(1));
        int sternX = Position::letterToNumber(XYtarget.at(0));
        int sternY = std::stoi(XYtarget.substr(1));

    } else {
        for(int i=0; i<nBattleships_; i++){
            try{
                Position bowPos, sternPos;
                bool isHorizontal = rand() % 2;
                if(isHorizontal) {
                    bowPos = Position(rand() % rows_, rand() % (cols_ - BattleshipSize_ - 1));
                    sternPos = Position(bowPos.getX(), bowPos.getY() + BattleshipSize_ - 1);
                } else {
                    bowPos = Position(rand() % (rows_ - BattleshipSize_ - 1), rand() % cols_);
                    sternPos = Position(bowPos.getX() + BattleshipSize_ - 1, bowPos.getY());
                }
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(bowPos, sternPos, attackGrid_)));
                fileOut_ << Position::numberToLetter(bowPos.getX()) << bowPos.getY()+1 
                         << " " << Position::numberToLetter(sternPos.getX()) << sternPos.getY()+1 << std::endl;
            }
            catch(const std::invalid_argument& e){
                i--;
                std::cerr << e.what() << '\n';
            }
        }
        for(int i=0; i<nSupportShips_; i++){
            try{
                Position bowPos, sternPos;
                bool isHorizontal = rand() % 2;
                if(isHorizontal) {
                    bowPos = Position(rand() % rows_, rand() % (cols_ - SupportShipSize_ - 1));
                    sternPos = Position(bowPos.getX(), bowPos.getY() + SupportShipSize_ - 1);
                } else {
                    bowPos = Position(rand() % (rows_ - SupportShipSize_ - 1), rand() % cols_);
                    sternPos = Position(bowPos.getX() + SupportShipSize_ - 1, bowPos.getY());
                }
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new SupportShip(bowPos, sternPos, defenseGrid_)));
                fileOut_ << Position::numberToLetter(bowPos.getX()) << bowPos.getY()+1 
                         << " " << Position::numberToLetter(sternPos.getX()) << sternPos.getY()+1 << std::endl;
            }
            catch(const std::invalid_argument& e){
                i--;
                std::cerr << e.what() << '\n';
            }
        }
        for(int i=0; i<nSubmarines_; i++){
            try{
                Position pos = rand() % rows_;
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(pos, pos, attackGrid_, defenseGrid_)));
                fileOut_ << Position::numberToLetter(pos.getX()) << pos.getY()+1 
                         << " " << Position::numberToLetter(pos.getX()) << pos.getY()+1 << std::endl;
            }
            catch(const std::invalid_argument& e){
                i--;
                std::cerr << e.what() << '\n';
            }
        }
    }
    
}

void Computer::execute(std::string command){
    if(command != ""){
        //TODO: gestire input con LogFileIn
    } else {
        std::cout << "sono entrato in execute di Player" << std::endl;
        try{
            std::cout << "inizio il try" << std::endl;
            Ship* ship = defenseGrid_->getShipByIndex(rand() % defenseGrid_->getShipsNumber());
            char centerX = Position::numberToLetter(ship->getCenter().getX());
            int centerY = ship->getCenter().getY();
            std::cout << "trovo XYorigin" << std::endl;
            //std::cout << centerX << centerY+1 << " ";
            int targetX = rand() % rows_;
            int targetY = rand() % cols_;
            std::cout << "trovo xy target" << std::endl;
            ship->action(Position(targetX, targetY), enemyDefenseGrid_);
            //std::cout << Position::numberToLetter(targetX) << targetY+1 << std::endl;
            fileOut_ << centerX << centerY+1 << " " << Position::numberToLetter(targetX) << targetY+1 << std::endl;
            std::cout << "Ho fatto l'azione" << std::endl;
        }
        catch(const std::invalid_argument& e){
            std::cout << "Ho trovato un errore" << std::endl;
            execute();
        }
        std::cout << "esco dall'execute di Player" << std::endl;
    }
}
#endif
