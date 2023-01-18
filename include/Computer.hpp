//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Computer.h"

void Computer::placeShips(char playerID, std::string command){
    if(command != ""){
        std::string bowPosStr = command.substr(0, command.find(" "));
        std::string sternPosStr = command.substr(command.find(" ")+1);

        int bowX = Position::letterToNumber(bowPosStr.at(0));
        int bowY = std::stoi(bowPosStr.substr(1));
        int sternX = Position::letterToNumber(sternPosStr.at(0));
        int sternY = std::stoi(sternPosStr.substr(1));

        Position bowPos(bowX, bowY);
        Position sternPos(sternX, sternY);

        if(shipCounter_ < nBattleships_){
            try{
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(bowPos, sternPos, attackGrid_)));
                //fileOut_ << playerID << " " << bowX << bowY << " " << sternX<< sternY << std::endl;
            } catch(const std::invalid_argument& e) {}
        } else if (shipCounter_ >= nBattleships_ && shipCounter_ < nBattleships_ + nSupportShips_){
            try{
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new SupportShip(bowPos, sternPos, defenseGrid_)));
                //fileOut_ << playerID << " " << bowX << bowY << " " << sternX<< sternY << std::endl;
            } catch(const std::invalid_argument& e) {}
        } else if (shipCounter_ >= nBattleships_ + nSupportShips_ && shipCounter_ < nBattleships_ + nSupportShips_ +nSubmarines_) {
            try{
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(bowPos, sternPos, attackGrid_, defenseGrid_)));
                //fileOut_ << playerID << " " << bowX << bowY << " " << sternX<< sternY << std::endl;
            } catch(const std::invalid_argument& e) {}
        }
        shipCounter_++;
    } else {
        int i;
        Position bowPos, sternPos;
        bool isHorizontal;

        for(i = 1; i <= nBattleships_; i++){
            try {
                isHorizontal = rand() % 2;
                if(isHorizontal) {
                    bowPos = Position(rand() % rows_, rand() % (cols_ - BattleshipSize_ - 1));
                    sternPos = Position(bowPos.getX(), bowPos.getY() + BattleshipSize_ - 1);
                } else {
                    bowPos = Position(rand() % (rows_ - BattleshipSize_ - 1), rand() % cols_);
                    sternPos = Position(bowPos.getX() + BattleshipSize_ - 1, bowPos.getY());
                }
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(bowPos, sternPos, attackGrid_)));
                fileOut_ << playerID << " " << Position::numberToLetter(bowPos.getX()) << bowPos.getY() + 1 
                        << " " << Position::numberToLetter(sternPos.getX()) << sternPos.getY() + 1 << std::endl;
            }
            catch(const std::invalid_argument& e) {
                i--;
            }
        }
        
        for(i = 1; i <= nSupportShips_; i++){
            try {
                isHorizontal = rand() % 2;
                if(isHorizontal) {
                    bowPos = Position(rand() % rows_, rand() % (cols_ - SupportShipSize_ - 1));
                    sternPos = Position(bowPos.getX(), bowPos.getY() + SupportShipSize_ - 1);
                } else {
                    bowPos = Position(rand() % (rows_ - SupportShipSize_ - 1), rand() % cols_);
                    sternPos = Position(bowPos.getX() + SupportShipSize_ - 1, bowPos.getY());
                }
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new SupportShip(bowPos, sternPos, defenseGrid_)));
                fileOut_ << playerID << " " << Position::numberToLetter(bowPos.getX()) << bowPos.getY() + 1 
                        << " " << Position::numberToLetter(sternPos.getX()) << sternPos.getY() + 1 << std::endl;
            }
            catch(const std::invalid_argument& e) {
                i--;
            }
        }

        for(i = 1; i <= nSubmarines_; i++){
            try {
                Position pos = rand() % rows_;
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(pos, pos, attackGrid_, defenseGrid_)));
                fileOut_ << playerID << " " << Position::numberToLetter(pos.getX()) << pos.getY() + 1 
                        << " " << Position::numberToLetter(pos.getX()) << pos.getY() + 1 << std::endl;
            }
            catch(const std::invalid_argument& e) {
                i--;
            }
        }
    }
    
}

void Computer::execute(std::string command){
    if(command != ""){
        std::string XYoriginStr = command.substr(0, command.find(" "));
        std::string XYtargetStr = command.substr(command.find(" ")+1);

        int originX = Position::letterToNumber(XYoriginStr.at(0));
        int originY = std::stoi(XYoriginStr.substr(1));
        int targetX = Position::letterToNumber(XYtargetStr.at(0));
        int targetY = std::stoi(XYtargetStr.substr(1));

        Position originXY(originX, originY);
        Position targetXY(targetX, targetY);

        try {
            Ship* ship = defenseGrid_->getShipByCenter(originXY);
            if(ship != nullptr) {
                ship->action(targetXY, enemyDefenseGrid_);
            }else {
                throw std::invalid_argument("No ship with that center. ");
            }
            
        } catch(const std::invalid_argument& e){}
        
    } else {
        bool flag = true;
        do {
            try {
                Ship* ship = defenseGrid_->getShipByIndex(rand() % defenseGrid_->getShipsNumber());
                char centerX = Position::numberToLetter(ship->getCenter().getX());
                int centerY = ship->getCenter().getY();

                int targetX = rand() % rows_;
                int targetY = rand() % cols_;
                ship->action(Position(targetX, targetY), enemyDefenseGrid_);

                fileOut_ << centerX << centerY+1 << " " << Position::numberToLetter(targetX) << targetY+1;
                flag = false;
            } catch(const std::invalid_argument& e){
                flag = true;
                //std::cerr << e.what() << std::endl;
            }
        } while(flag);
    }
}
#endif
