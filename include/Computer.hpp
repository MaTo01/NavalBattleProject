//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

void Computer::placeShips(){
    while(battleshipCounter < 3 || supportShipCounter < 3 || submarineCounter < 2 ){
        int shipType = rand() % 3;
        switch (shipType){
        case 0:
            if(battleshipCounter < 3){
                Position bowPos = Position(rand()%12, rand()%12);
                Position sternPos;
                bool isHorizontal = rand()%2;
                if(isHorizontal){
                    sternPos = Position(bowPos.getX(), bowPos.getY()+4);
                }else{
                    sternPos = Position(bowPos.getX()+4, bowPos.getY());
                }
                defenseGrid_->placeShip(new Battleship(bowPos,sternPos,attackGrid_));
                battleshipCounter++;
                logFile << bowPos.getX() << bowPos.getY() << " " << sternPos.getX() << sternPos.getY() << std::endl;
            }
            break;

        case 1:
            if(supportShipCounter < 3){
                Position bowPos = Position(rand()%11, rand()%11);
                Position sternPos;
                bool isHorizontal = rand()%2;
                if(isHorizontal){
                    sternPos = Position(bowPos.getX(), bowPos.getY()+4);
                }else{
                    sternPos = Position(bowPos.getX()+4, bowPos.getY());
                }
                defenseGrid_->placeShip(new SupportShip(bowPos,sternPos,defenseGrid_));
                supportShipCounter++;
                logFile << bowPos.getX() << bowPos.getY() << " " << sternPos.getX() << sternPos.getY() << std::endl;
            }
            break;

        case 2:
            if(submarineCounter < 2){
                Position bowPos = Position(rand()%11, rand()%11);
                defenseGrid_->placeShip(new Submarine(bowPos,bowPos,attackGrid_, defenseGrid_));
                submarineCounter++;
                logFile << bowPos.getX() << bowPos.getY() << " " << bowPos.getX() << bowPos.getY() << std::endl;
            }
            break;

        default:
            break;
        }
    }
}

void Computer::performAction(){
    //int maxShips = battleshipCounter+supportShipCounter+submarineCounter;
    //int chooseShip = rand()%maxShips;

    //TODO: understand how the fuck should you write a XYOrigin in a log file
    //      without raping the memory with a do while() loop and a random function 

}

#endif