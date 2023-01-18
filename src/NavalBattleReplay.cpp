#include <iostream>
#include <fstream>
#include "Game.h"

int main(int argc, char* argv[]) {
	
	if(argc < 3 || argc > 4) {
		std::cout << "Invalid argument list.\n";
		return -1;
	}

	std::string argvToLower = "";
	for (int x=0; x < strlen(argv[1]); x++)
        argvToLower += tolower(argv[1][x]);

	if(argvToLower != "v" && argvToLower != "f") {
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