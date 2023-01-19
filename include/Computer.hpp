//2043414 Marco Toffoletto
#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Computer.h"


//Since this class also manages the replay view of the games, there is the possibility that an argument that identifies the
//command executed during a game is passed to this function.

/*
In this function, a check is first performed to see if a command is passed as the second argument. If so, the string is manipulated
to obtain the ship placement coordinates and the type of ship to be placed is based on the number of ships that have already been
placed (This is only possible thanks to the orderly insertion of ships into the grid during the game).
Otherwise, the ship's orientation is randomly generated and, based on that, the stern and bow positions are randomly generated 
and the ship is placed between those positions. Then the function proceeds to print these positions to a file.
*/
void Computer::placeShips(char playerID, std::string command) {
    //It's running in playReplay of Game
    if(command != "") { 
        //Split the string
        std::string bowPosStr = command.substr(0, command.find(" "));
        std::string sternPosStr = command.substr(command.find(" ")+1);

        //Parse the values from the two strings
        int bowX = Position::letterToNumber(bowPosStr.at(0));
        int bowY = std::stoi(bowPosStr.substr(1)) - 1;
        int sternX = Position::letterToNumber(sternPosStr.at(0));
        int sternY = std::stoi(sternPosStr.substr(1)) - 1;

        //Create the two positions
        Position bowPos(bowX, bowY);
        Position sternPos(sternX, sternY);

        try{
            if(shipCounter_ < nBattleships_) {
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(bowPos, sternPos, attackGrid_.get())));
            } else if (shipCounter_ >= nBattleships_ && shipCounter_ < nBattleships_ + nSupportShips_) {
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new SupportShip(bowPos, sternPos, defenseGrid_.get())));
            } else if (shipCounter_ >= nBattleships_ + nSupportShips_ && shipCounter_ < nBattleships_ + nSupportShips_ +nSubmarines_) {
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(bowPos, sternPos, attackGrid_.get(), defenseGrid_.get())));
            }
        } catch(const std::invalid_argument& e) {}

        shipCounter_++;

    } else {    //It's running in setBattlefield of Game
        int i;
        Position bowPos, sternPos;
        bool isHorizontal;

        for(i = 1; i <= nBattleships_; i++) {
            try {
                isHorizontal = rand() % 2;
                if(isHorizontal) {
                    bowPos = Position(rand() % rows_, rand() % (cols_ - BattleshipSize_ - 1));
                    sternPos = Position(bowPos.getX(), bowPos.getY() + BattleshipSize_ - 1);
                } else {
                    bowPos = Position(rand() % (rows_ - BattleshipSize_ - 1), rand() % cols_);
                    sternPos = Position(bowPos.getX() + BattleshipSize_ - 1, bowPos.getY());
                }
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Battleship(bowPos, sternPos, attackGrid_.get())));
                fileOut_ << playerID << " " << Position::numberToLetter(bowPos.getX()) << bowPos.getY() + 1 
                        << " " << Position::numberToLetter(sternPos.getX()) << sternPos.getY() + 1 << std::endl;
            }
            catch(const std::invalid_argument& e) {
                i--;
            }
        }
        
        for(i = 1; i <= nSupportShips_; i++) {
            try {
                isHorizontal = rand() % 2;
                if(isHorizontal) {
                    bowPos = Position(rand() % rows_, rand() % (cols_ - SupportShipSize_ - 1));
                    sternPos = Position(bowPos.getX(), bowPos.getY() + SupportShipSize_ - 1);
                } else {
                    bowPos = Position(rand() % (rows_ - SupportShipSize_ - 1), rand() % cols_);
                    sternPos = Position(bowPos.getX() + SupportShipSize_ - 1, bowPos.getY());
                }
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new SupportShip(bowPos, sternPos, defenseGrid_.get())));
                fileOut_ << playerID << " " << Position::numberToLetter(bowPos.getX()) << bowPos.getY() + 1 
                        << " " << Position::numberToLetter(sternPos.getX()) << sternPos.getY() + 1 << std::endl;
            }
            catch(const std::invalid_argument& e) {
                i--;
            }
        }

        for(i = 1; i <= nSubmarines_; i++) {
            try {
                Position pos = rand() % rows_;
                defenseGrid_->placeShip(std::unique_ptr<Ship> (new Submarine(pos, pos, attackGrid_.get(), defenseGrid_.get())));
                fileOut_ << playerID << " " << Position::numberToLetter(pos.getX()) << pos.getY() + 1 
                        << " " << Position::numberToLetter(pos.getX()) << pos.getY() + 1 << std::endl;
            }
            catch(const std::invalid_argument& e) {
                i--;
            }
        }
    }
    
}

/*
In this function, a check is first performed to see if a command is passed as the second argument. If so, the string is manipulated
to obtain the command XYorigin and XYtarget and perform the XYorigin's ship action to XYtarget.
Otherwise, A random ship is chosen among those present in the grid, its center is calculated and the action is performed 
at a random position of the grid.
*/
void Computer::execute(std::string command) {
    //It's running in playReplay of Game
    if(command != ""){  
        //Split the string
        std::string XYoriginStr = command.substr(0, command.find(" "));
        std::string XYtargetStr = command.substr(command.find(" ") + 1);

        //Parse the values from the two strings
        int originX = Position::letterToNumber(XYoriginStr.at(0));
        int originY = std::stoi(XYoriginStr.substr(1)) - 1;
        int targetX = Position::letterToNumber(XYtargetStr.at(0));
        int targetY = std::stoi(XYtargetStr.substr(1)) - 1;

        //Create the two positions
        Position originXY(originX, originY);
        Position targetXY(targetX, targetY);

        try {
            Ship* ship = defenseGrid_->getShipByCenter(originXY);
            if(ship != nullptr) {
                ship->action(targetXY, enemyDefenseGrid_);
            } else {
                throw std::invalid_argument("No ship with that center. ");
            }
            
        } catch(const std::invalid_argument& e) {}
        
    } else {    //It's running in setBattlefield of Game
        bool flag = true;   //Flag used to prevent the function from exiting if an invalid command is issued
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
            } catch(const std::invalid_argument& e) {
                //There is no need to display or manage this error, go on.
                flag = true;
            }
        } while(flag);
    }
}
#endif
