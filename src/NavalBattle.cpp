#include <iostream>
#include <fstream>
#include <memory>
#include "Game.h"

int main(int argc, char* argv[]){
	Game game('p');
	game.start();
    game.showWinner();

	return 0;
}
