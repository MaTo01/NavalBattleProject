//2043414 Marco Toffoletto
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {
	//Check if the command line arguments are enough
	if(argc != 2) {
		std::cout << "Invalid argument list.\n";
		return -1;
	}

	//Capitalization errors on the first argument are accepted if the command is correct
	std::string argvToLower = "";
	for (int x=0; x < strlen(argv[1]); x++) {
		argvToLower += tolower(argv[1][x]);
	}
	
	//Check of the command
	if(argvToLower != "cc" && argvToLower != "pc") {
		std::cout << "Invalid argument list.";
	} else {
		Game game(argvToLower[0]);
		game.setBattlefield();
		game.start();
	}
	
	return 0;
}
