//2032496 Veronica Cisotto
#ifndef GAME_HPP
#define GAME_HPP

#include "Game.h"
#include <iostream>

Game::Game(char mode, std::string logNameIn, std::string logNameOut) : mode_{mode} {
    switch (mode_) {
        case 'c':
            player1 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            logFileOut_.open("log.txt", std::ios::out);
            break;
        case 'p':
            player1 = std::unique_ptr<Player>(new Computer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new HumanPlayer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            logFileOut_.open("log.txt", std::ios::out);
            break;
        case 'v':
            player1 = std::unique_ptr<Player>(new HumanPlayer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new HumanPlayer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));    
            logFileIn_.open(logNameIn, std::ios::in);
            break;
        case 'f':
            player1 = std::unique_ptr<Player>(new HumanPlayer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));
            player2 = std::unique_ptr<Player>(new HumanPlayer(rows_, cols_, nBattleships_, nSupportShips_, nSubmarines_, logFileOut_));      
            logFileIn_.open(logNameIn, std::ios::in);
            logFileOut_.open(logNameOut, std::ios::out);
            break;
        default:
            break;
    }
}

Game::~Game() {
    if(logFileIn_.is_open())
        logFileIn_.close();
    if(logFileOut_.is_open())
        logFileOut_.close();
    player1.reset();
    player2.reset();
}

void Game::setBattlefield() {
    switch (mode_) {
        case 'c':
            player1->placeShips();
            player2->placeShips();
            break;
        case 'p':
            player1->placeShips();
            //HumanPlayer input (lettura stringa)
            break;
        case 'v':
        case 'f':
            std::string input;
            int i = 1;
            do {
                logFileIn_ >> input;
                if(input[0] == '1') {
                    player1->placeShips(input.substr(2));
                } else {
                    //sistemare placeShips per piazzamento singolo
                    player2->placeShips(input.substr(2));
                }
                i++;
            } while(i <= 2 * (nBattleships_ + nSupportShips_ + nSubmarines_));
            break;
    }
    player1->setEnemyDefenseGrid(player2->getDefenseGrid());
    player2->setEnemyDefenseGrid(player1->getDefenseGrid());
}

void Game::start() {
    if(mode_ == 'p') {
        int starter = rand() % 2;
        if(starter == 0) {  //player2 = giocatore umano 
            do {
                logFileOut_ << "1 ";
                player1->execute();
                //passare a player2 stringa da console? oppure lasciare execute così
                logFileOut_ << "2 ";
                player2->execute();
                //TODO: scrittura dell'operazione su logFileOut fatta da execute
                counter_++;
            } while(counter_ < maxTurns_ && !player1->isWinner() && !player2->isWinner());
        }
        else if(starter==1) {
            do {
                //passare a player2 stringa da console?
                logFileOut_ << "2 ";
                player2->execute();
                logFileOut_ << "1 ";
                player1->execute();
                counter_++;
            } while(counter_ < maxTurns_ && !player1->isWinner() && !player2->isWinner());
        }
    }
    else if(mode_ == 'c') {
        do {
            std::cout << "counter : " << counter_ << std::endl;
            logFileOut_ << "1 ";
            std::cout << "entro in execute di Player 1" << std::endl;
            player1->execute();
            logFileOut_ << "2 ";
            std::cout << "entro in execute di Player 2" << std::endl;
            player2->execute();
            counter_++;
            std::cout << "Ho finito un ciclo di while" << std::endl;
        } while(counter_ < maxTurns_ /*&& !player1->isWinner() && !player2->isWinner()*/);
    } else {
        //errore o qualcosa del genere
    }
}

void Game::playReplay() {
    std::string input;
    if(mode_ == 'v') {
        do {
            clear();
            logFileIn_ >> input;
            if(input[0] == '1') {
                player1->execute(input.substr(2));
                std::cout << "\t\t\t\tPLAYER 1\n\n";
                player1->viewGrids(std::cout);
            } else {
                player2->execute(input.substr(2));
                std::cout << "\t\t\t\tPLAYER 2\n\n";
                player2->viewGrids(std::cout);
            }
            sleep_function(time_multiplier * 2000);
        } while(!logFileIn_.eof());
    } else if(mode_ == 'f') {
        do {
            logFileIn_ >> input;
            if(input[0] == '1') {
                player1->execute(input.substr(2));
                logFileOut_ << "\t\t\t\tPLAYER 1\n";
                player1->viewGrids(logFileOut_);
                logFileOut_ << "\n\n";
            } else {
                player2->execute(input.substr(2));
                logFileOut_ << "\t\t\t\tPLAYER 2\n";
                player2->viewGrids(logFileOut_);
                logFileOut_ << "\n\n";
            }
        } while(!logFileIn_.eof());
    } else {
        //errore o qualcosa del genere
    }
}

void Game::showWinner() {
    if(counter_> maxTurns_) 
        std::cout << "MATCH ENDED IN TIE" << std::endl;
    else{
        if(player1->isWinner()) 
            std::cout << "WINNER: PLAYER 1";
        else  
            std::cout << "WINNER: PLAYER 2";
    }
}

#endif
