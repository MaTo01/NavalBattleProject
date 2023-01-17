#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "HumanPlayer.h"
#include "Computer.h"
#include <random>

class Game{
private:
    HumanPlayer humanPlayer_;
    Computer cpu1_;
    Computer cpu2_;
    char secondPlayer_;
    int counter_ = 0;
    static constexpr int maxTurns_ = 50;
public:
    Game(char secondPlayer) : secondPlayer_{secondPlayer} {srand(time(NULL));}
    ~Game() = default;

    void setBattlefield();
    void start();
    void showWinner();
};

#include "Game.hpp"

#endif
