#ifndef GAME_H
#define GAME_H

#include "HumanPlayer.h"
#include "Computer.h"
#include <random>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#define sleep_function         Sleep
#define time_multiplier        1
#else
#include <unistd.h>
#define sleep_function         usleep
#define time_multiplier        1000
#endif

//Clears console screen
#define clear() std::cout<<"\033[H\033[J";

class Game{
private:
    static constexpr int maxTurns_ = 50;
    static constexpr int rows_ = 12;
    static constexpr int cols_ = 12;
    static constexpr int nBattleships_ = 3;
    static constexpr int nSupportShips_ = 3;
    static constexpr int nSubmarines_ = 2;

    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    char mode_;
    std::ofstream logFileOut_;
    std::ifstream logFileIn_;
    int counter_ = 0;  

public:
    Game(char mode, std::string logNameIn = "", std::string logNameOut = "");
    ~Game();

    void setBattlefield();
    void start();
    void playReplay();
    void showWinner();
};

#include "Game.hpp"

#endif
