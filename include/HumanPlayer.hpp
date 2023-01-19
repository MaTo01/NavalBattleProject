//2032496 Veronica Cisotto
#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "HumanPlayer.h"
#include <iostream>


void HumanPlayer::placeShips(char playerID, std::string command){
    /*
    At the beginning of every game match HumanPlayer choooses the coordinates of bow
    and stern for every ship (which will be written into a .txt log file), thus creating 
    a new ship and placing it in their defense grid
    */
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
    /*
    Command to choose a ship by its center and a target to perform its
    action on. Thus battleships will fire the enemy on their defense grid
    and support ships and submarines will move to said target.
    Once the action is executed it will be the opponent's turn.
    */
    std::string input;
    char centerX = ' ', targetX;
    int centerY, targetY;
    
    bool flag = true;
    do {
        try {
            std::cout << "Command XX XX to see the grids; command AA AA to delete preview scans from the attack grid." << std::endl;
            std::cout << "Otherwise select ship by its center and target:" << std::endl;     
            std::getline(std::cin, input);
            /*
            HumanPlayer can also perform additional fuctions to see their grids or
            to delete all the scans from their attack grid (these functions do not
            condition player's turn)
            */
	    
	    std::string inputToUpper(input.size(), ' ');
            for (int i = 0; i < input.size(); i++) {
	    	inputToUpper[i] = toupper(input[i]);
	    }

            std::regex pattern("([A-Z][A-Z] [A-Z][A-Z]|[A-Z]\\d{1,2} [A-Z]\\d{1,2})");

            if (!std::regex_match(inputToUpper, pattern)) {
                throw std::invalid_argument("Invalid command.");
            }
	    
            if(inputToUpper == "AA AA") {
                clearAttackGridScans();
            } else if(inputToUpper == "XX XX") {
                viewGrids(std::cout);
            } else {
                try {
                    centerX = inputToUpper.at(0);
                    centerY = std::stoi(inputToUpper.substr(1, inputToUpper.find(" ")));
                    targetX = inputToUpper.at(inputToUpper.find(" ") + 1);
                    targetY = std::stoi(inputToUpper.substr(inputToUpper.find(" ") + 2));
                } catch(const std::invalid_argument& e) {
                    throw std::invalid_argument("Invalid command.");
                }

                Position center(Position::letterToNumber(centerX), centerY-1);
                Position target(Position::letterToNumber(targetX), targetY-1);
                Ship* ship = defenseGrid_->getShipByCenter(center);
                if(ship != nullptr) {
                    ship->action(target, enemyDefenseGrid_);
                    flag = false;
                } else {
                    throw std::invalid_argument("No ship with that center.");
                }
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what() << " Try again.\n";
        } catch (const std::out_of_range& e) {
            std::cerr << e.what() << " Try again.\n";
        }
    } while (flag);
    if(centerX != ' ') {
        fileOut_ << centerX << centerY << " " << targetX << targetY;
    }    
}

#endif
