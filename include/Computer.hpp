//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Computer.h"

void Computer::placeShips(DefenseGrid* enemyDefenseGrid){
    srand (time(NULL));
    for(int i = 1; i<=nBattleships; i++){
        try{
            Position bowPos, sternPos;
            bool isHorizontal = rand() % 2;
            if(isHorizontal) {
                bowPos = Position(rand() % rows, rand() % (cols - BattleshipSize - 1));
                sternPos = Position(bowPos.getX(), bowPos.getY() + BattleshipSize - 1);
            } else {
                bowPos = Position(rand() % (rows - BattleshipSize - 1), rand() % cols);
                sternPos = Position(bowPos.getX() + BattleshipSize - 1, bowPos.getY());
            }
            defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(bowPos, sternPos, attackGrid_)));
        }
        catch(const std::invalid_argument& e){
            i--;
            std::cerr << e.what() << '\n';
        }
    }
    for(int i = 1; i<=nSupportShips; i++){
        try{
            Position bowPos, sternPos;
            bool isHorizontal = rand() % 2;
            if(isHorizontal) {
                bowPos = Position(rand() % rows, rand() % (cols - SupportShipSize - 1));
                sternPos = Position(bowPos.getX(), bowPos.getY() + SupportShipSize - 1);
            } else {
                bowPos = Position(rand() % (rows - SupportShipSize - 1), rand() % cols);
                sternPos = Position(bowPos.getX() + SupportShipSize - 1, bowPos.getY());
            }
            defenseGrid_->placeShip(std::unique_ptr<Ship> (new SupportShip(bowPos, sternPos, defenseGrid_)));       
        }
        catch(const std::invalid_argument& e){
            i--;
            std::cerr << e.what() << '\n';
        }
    }
    for(int i = 1; i<=nSubmarines; i++){
        try{
            Position pos = rand() % rows;
            defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(pos, pos, attackGrid_, defenseGrid_)));      
        }
        catch(const std::invalid_argument& e){
            i--;
            std::cerr << e.what() << '\n';
        }
    }
    
    defenseGrid_->printGrid(std::cout);

}

void Computer::performAction(){
    //int maxShips = battleshipCounter+supportShipCounter+submarineCounter;
    //int chooseShip = rand()%maxShips;

    //TODO: understand how the fuck should you write a XYOrigin in a log file
    //      without raping the memory with a do while() loop and a random function 

}

#endif
