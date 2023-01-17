//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Computer.h"

void Computer::placeShips(){
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
        }
        catch(const std::invalid_argument& e){
            i--;
            std::cerr << e.what() << '\n';
        }
    }
    
    defenseGrid_->printGrid(std::cout);

}

void Computer::execute(){
    Ship* ship = defenseGrid_->getShipByIndex(rand() % nTotalShips_);
    char centerX = Position::numberToLetter(ship->getCenter().getX());
    int centerY = ship->getCenter().getY();
    std::cout << centerX << centerY+1 << " ";
    try{
        int targetX = rand() % rows_;
        int targetY = rand() % cols_;
        ship->action(Position(targetX, targetY), enemyDefenseGrid_);
        std::cout << Position::numberToLetter(targetX) << targetY+1 << std::endl;
    }
    catch(const std::invalid_argument& e){
        std::cerr << e.what() << '\n';
        execute();
    }
}

#endif
