//2032496 Veronica Cisotto
#ifndef GAME_HPP
#define GAME_HPP

#include "Game.h"

Game::Game(char mode, std::string logNameIn, std::string logNameOut) : mode_{mode} {
    //Compuetr vs computer and Computer vs Human player matches record their ship
    //placements and commands into a .txt log file
    if(mode == 'c' || mode == 'p') {
        logNameOut = "log-";
        logNameOut += mode;
        logNameOut += "c.txt";
    }
    switch (mode_) {
        case 'c': //Computer vs computer
            player1 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            logFileOut_.open(logNameOut, std::ios::out);
            break;
        case 'p': //Player vs Computer
            player1 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new HumanPlayer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            logFileOut_.open(logNameOut, std::ios::out);
            break;
        case 'f': //Replay of a match (taken from a log file) will be written into a .txt file
            logFileOut_.open(logNameOut, std::ios::out);
        case 'v': //Replay of a match (taken from a log file) will be printed on screen
            player1 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));    
            logFileIn_.open(logNameIn, std::ios::in);
            if(!logFileIn_.is_open()) {
                throw std::invalid_argument("Error opening log file.");
            }
            break;
        default:
            break;
    }
    //Players have now access to their opponent's defense grid
    player1->setEnemyDefenseGrid(player2->getDefenseGrid());
    player2->setEnemyDefenseGrid(player1->getDefenseGrid());
}

Game::~Game() {
    if(logFileIn_.is_open()){
        logFileIn_.close();
    } 
    if(logFileOut_.is_open())
        logFileOut_.close();
    player1.reset();
    player2.reset();
}

void Game::setBattlefield() {
    switch (mode_) {
        case 'c':
        case 'p':
            //Players will place their ships following their specific class function
            player1->placeShips('1');
            player2->placeShips('2');
            break;
        case 'v':
        case 'f':
            //ship placements will be taken line by line from the log file
            std::string input;
            int i = 1;
            do {                
                getline(logFileIn_, input);
                if(input[0] == '1') {
                    player1->placeShips('1', input.substr(2));
                } else {
                    player2->placeShips('2', input.substr(2));
                }
                i++;
            } while(i <= 2 * (nBattleships_ + nSupportShips_ + nSubmarines_));
            break;
    }
}

void Game::start() {
    if(mode_ == 'p') {
        std::cin.ignore();
        int starter = rand() % 2;
        if(starter == 0) {          //player1 (compuer) will start 
            do {
                logFileOut_ << "1 ";
                player1->execute();
                logFileOut_ << std::endl;
                logFileOut_ << "2 ";
                player2->execute();
                if(++turnCounter_ < maxTurns_)
                    logFileOut_ << std::endl;
            } while(turnCounter_ < maxTurns_ && !player1->isWinner() && !player2->isWinner());
        }
        else if(starter==1) {     //player2 (human player) will start
            do {
                logFileOut_ << "2 ";
                player2->execute();
                logFileOut_ << std::endl;
                logFileOut_ << "1 ";
                player1->execute();
                if(++turnCounter_ < maxTurns_)
                    logFileOut_ << std::endl;
            } while(turnCounter_ < maxTurns_ && !player1->isWinner() && !player2->isWinner());
        }
    }
    else if(mode_ == 'c') {
        do {
            logFileOut_ << "1 ";
            player1->execute();
            logFileOut_ << std::endl;
            logFileOut_ << "2 ";
            player2->execute();
            if(++turnCounter_ < maxTurns_)
                logFileOut_ << std::endl;
        } while(turnCounter_ < maxTurns_ && !player1->isWinner() && !player2->isWinner());
    } else {
        throw std::invalid_argument("Wrong arguments.");
    }
}

void Game::playReplay() {
    //commands will be taken line by line from the log file
    std::string input;
    if(mode_ == 'v') {
       std::cout << "\t\t\t      PLAYER 1\n";
        player1->viewGrids(std::cout);
        sleep_function(time_multiplier * 1000);
        std::cout << "\n";

        std::cout << "\t\t\t      PLAYER 2\n";
        player2->viewGrids(std::cout);
        sleep_function(time_multiplier * 1000);
        std::cout << "\n";
        
        do {
            getline(logFileIn_, input);
            if(input[0] == '1') {
                player1->execute(input.substr(2));
                std::cout << "\nPlayer 1 command:   ";
                std::cout << input.substr(2) << "\n\n";
                player1->viewGrids(std::cout);
            } else {
                player2->execute(input.substr(2));
                std::cout << "\nPlayer 2 command:   ";
                std::cout << input.substr(2) << "\n\n";
                player2->viewGrids(std::cout);        
            }
            sleep_function(time_multiplier * 1000);
        } while(!logFileIn_.eof());
        turnCounter_ = maxTurns_;
        showWinner();
    } else if(mode_ == 'f') {
        do {
            getline(logFileIn_, input);
            if(input[0] == '1') {
                player1->execute(input.substr(2));
                logFileOut_ << "\t\t\t    PLAYER 1\n";
                player1->viewGrids(logFileOut_);
            } else {
                player2->execute(input.substr(2));
                logFileOut_ << "\t\t\t    PLAYER 2\n";
                player2->viewGrids(logFileOut_);
            }
            logFileOut_ << "\n\n";
        } while(!logFileIn_.eof());
    } else {
        throw std::invalid_argument("Wrong arguments.");
    }
}

void Game::showWinner() {
    if(turnCounter_ >= maxTurns_) 
        std::cout << "MATCH ENDED IN TIE" << std::endl;
    else{
        if(player1->isWinner()) 
            std::cout << "WINNER: PLAYER 1";
        else  
            std::cout << "WINNER: PLAYER 2";
    }
}

#endif
