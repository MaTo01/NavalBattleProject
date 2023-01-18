#include <iostream>
#include <fstream>
#include <memory>
#include "Game.h"

int main(int argc, char* argv[]){

	if(argc != 2){
		std::cout << "Invalid argument list.\n";
		return -1;
	}

	std::string argvToLower = "";
	for (int x=0; x < strlen(argv[1]); x++)
        argvToLower += tolower(argv[1][x]);
	
	if(argvToLower != "cc" && argvToLower != "pc"){
		std::cout << "Invalid argument list.";
	} else {
		Game game(argvToLower[0]);
		game.setBattlefield();
		game.start();
		game.showWinner();
	}
	
	return 0;
}
