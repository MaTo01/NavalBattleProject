//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Computer.h"

void Computer::placeShips(){
    Position bowPos, sternPos;
    int shipSize;
    int battleshipCounter = 0, supportShipCounter = 0, submarineCounter = 0;

    while(battleshipCounter < maxBattleships_ || supportShipCounter < maxSupportShips_ || submarineCounter < maxSubmarines_){
        int shipType = rand() % 3;
        switch (shipType) {
            case 0:
                shipSize = 5;
                break;
            case 1: 
                shipSize = 3;
                break;
            case 2:
                shipSize = 1;
                break;
        }

        bool isHorizontal = rand() % 2;
        if(isHorizontal) {
            bowPos = Position(rand() % defenseGrid_->getRows(), rand() % (defenseGrid_->getColumns() - shipSize - 1));
            sternPos = Position(bowPos.getX(), bowPos.getY() + shipSize - 1);
        } else {
            bowPos = Position(rand() % (defenseGrid_->getRows() - shipSize - 1), rand() % defenseGrid_->getColumns());
            sternPos = Position(bowPos.getX() + shipSize - 1, bowPos.getY());
        }

        switch (shipType) {
            case 0:
                if(battleshipCounter < 3){
                    defenseGrid_->placeShip(new Battleship(bowPos, sternPos, attackGrid_));
                    battleshipCounter++;
                    logFile << bowPos.getX() << bowPos.getY() << " " << sternPos.getX() << sternPos.getY() << std::endl;
                }
                break;
            case 1:
                if(supportShipCounter < 3){
                    defenseGrid_->placeShip(new SupportShip(bowPos, sternPos, defenseGrid_));
                    supportShipCounter++;
                    logFile << bowPos.getX() << bowPos.getY() << " " << sternPos.getX() << sternPos.getY() << std::endl;
                }
                break;
            case 2:
                if(submarineCounter < 2){
                    defenseGrid_->placeShip(new Submarine(bowPos, bowPos, attackGrid_, defenseGrid_));
                    submarineCounter++;
                    logFile << bowPos.getX() << bowPos.getY() << " " << bowPos.getX() << bowPos.getY() << std::endl;
                }
                break;
            default:
                break;
        }
        defenseGrid_->printGrid(std::cout);
    }
}

void Computer::performAction(){
    //int maxShips = battleshipCounter+supportShipCounter+submarineCounter;
    //int chooseShip = rand()%maxShips;

    //TODO: understand how the fuck should you write a XYOrigin in a log file
    //      without raping the memory with a do while() loop and a random function 

}

#endif
