//2032496 Veronica Cisotto
#ifndef GAME_H
#define GAME_H

#include "HumanPlayer.h"
#include "Computer.h"
#include <fstream>
#include <iostream>

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
    //Maximum rounds allowed: beyond this limit the match will end in a tie
    static constexpr int maxTurns_ = 50;
    static constexpr int rows_ = 12;
    static constexpr int cols_ = 12;
    static constexpr int nBattleships_ = 3;
    static constexpr int nSupportShips_ = 3;
    static constexpr int nSubmarines_ = 2;

    //unique pointers to the two players, whether they are HumanPlayers or Computers
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    //char to identify in which configuration the game is run
    char mode_;
    //output file stream in which every command will be written
    std::ofstream logFileOut_;
    //input stream which every command will be taken from
    std::ifstream logFileIn_;
    int turnCounter_ = 0;  

    //shows the winner of the match
    void showWinner(std::ostream& os);

public:
    //Constructor
    Game(char mode, std::string logNameIn = "", std::string logNameOut = "");
    //Destructor
    ~Game();
    
    //both players place their ships in their defense grids
    void setBattlefield();
    //every player makes their move until either wins (or game ends in a tie)
    void start();
    //replay of a recorded game (commands, attack grids and defense grids) will be 
    //either displayed on screen or written into a .txt file
    void playReplay();
};

#include "Game.hpp"

#endif
