#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Computer.h"

class Game{
private:
    Player player_;
    Computer cpu_;
    static constexpr int maxTurns = 50;
public:
    Game() = default;
    ~Game() = default;

    void setBattlefield();
    void start();
};

#include "Game.hpp"

#endif
