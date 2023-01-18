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

class Game{
private:
    //Maximum of rounds allowed: beyond this limit
    //match will end in a tie
    static constexpr int maxTurns_ = 50;
    static constexpr int rows_ = 12;
    static constexpr int cols_ = 12;
    static constexpr int nBattleships_ = 3;
    static constexpr int nSupportShips_ = 3;
    static constexpr int nSubmarines_ = 2;

    //unique pointers to the pkayer, whether they are HumanPlayers o Computers
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    //char to identify which player is currently performing their action
    char mode_;
    //output stream into which every command will be written
    std::ofstream logFileOut_;
    //input stream which every command will be taken from
    std::ifstream logFileIn_;
    int turnCounter_ = 0;  

public:
    //Constructor
    Game(char mode, std::string logNameIn = "", std::string logNameOut = "");
    //Distructor
    ~Game();
    
    //both players place their ships in their defense grids
    void setBattlefield();
    //every palyer makes their move until either wins (or game ends in a tie)
    void start();
    void playReplay();
    void showWinner();
};

#include "Game.hpp"

#endif
