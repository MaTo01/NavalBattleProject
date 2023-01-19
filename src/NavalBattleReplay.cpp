//2043414 Marco Toffoletto
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {
	//Check if the command line arguments are enough
	if(argc < 3 || argc > 4) {
		std::cout << "Invalid argument list.\n";
		return -1;
	}

	//Capitalization errors on the first argument are accepted if the command is correct
	std::string argvToLower = "";
	for (int i = 0; i < strlen(argv[1]); i++) {
		argvToLower += tolower(argv[1][i]);
	}

	//Check of the command
	if((argc == 3 && argvToLower != "v") || (argc == 4 && argvToLower != "f")) {
		std::cout << "Invalid argument list.\n";
	} else {
		std::string fileOut = "";
		if(argc == 4) {
			fileOut = std::string(argv[3]);
		}
		Game replay(argvToLower[0], argv[2], fileOut);
		replay.setBattlefield();
		replay.playReplay();
	}

	return 0;
}
