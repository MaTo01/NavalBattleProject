//2032496 Veronica Cisotto
#ifndef GAME_HPP
#define GAME_HPP

#include "Game.h"
#include <iostream>

void Game::setBattlefield(){
    Player p{};
    Computer e{};
    e.placeShips();
    p.placeShips();
    p.setEnemyDefenseGrid(e.getDefenseGrid());
    e.setEnemyDefenseGrid(p.getDefenseGrid());
}

void Game::start(){
    
}

#endif
