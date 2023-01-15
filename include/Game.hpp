#ifndef GAME_HPP
#define GAME_HPP

#include "Game.h"
#include <iostream>

void Game::setBattlefield(){
    Player p{};
    Computer e{};
    e.placeShips(p.getDefenseGrid());
    p.placeShips(e.getDefenseGrid());
}

void Game::start(){
    
}

#endif
