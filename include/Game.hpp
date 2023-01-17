//2032496 Veronica Cisotto
#ifndef GAME_HPP
#define GAME_HPP

#include "Game.h"
#include <iostream>

void Game::setBattlefield(){
    if(secondPlayer_=='p'){
        cpu1_.placeShips();
        humanPlayer_.placeShips();
        cpu1_.setEnemyDefenseGrid(humanPlayer_.getDefenseGrid());
        humanPlayer_.setEnemyDefenseGrid(cpu1_.getDefenseGrid()); 
    }
    else if(secondPlayer_=='c'){
        cpu1_.placeShips();
        cpu2_.placeShips();
        cpu1_.setEnemyDefenseGrid(cpu2_.getDefenseGrid());
        cpu2_.setEnemyDefenseGrid(cpu1_.getDefenseGrid()); 
    }    
}

void Game::start(){
    setBattlefield();
    if(secondPlayer_=='p'){
        int starter = rand() % 2;
        if(starter==0){
            while(counter_<maxTurns_ || !cpu1_.isWinner() || !humanPlayer_.isWinner()){
                humanPlayer_.execute();
                cpu1_.execute();
                counter_++;
            }  
        }
        else if(starter==1){
            while(counter_<maxTurns_ || !cpu1_.isWinner() || !humanPlayer_.isWinner()){
                cpu1_.execute();
                humanPlayer_.execute();
                counter_++;
            }
        }
    }
    else if(secondPlayer_=='c'){
        while(counter_<maxTurns_ || !cpu1_.isWinner() || !cpu2_.isWinner()){
            cpu1_.execute();
            cpu2_.execute();
            counter_++;
        }
    }
}

void Game::showWinner(){
    if(counter_>maxTurns_) std::cout << "MATCH ENDED WITH TIE";
    else{
        if(humanPlayer_.isWinner()) std::cout << "WINNER: PLAYER";
        if(cpu1_.isWinner()) std::cout << "WINNER: CPU1";
        if(cpu2_.isWinner()) std::cout << "WINNER: CPU2";
    }
}

#endif
