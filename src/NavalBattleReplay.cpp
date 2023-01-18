#include <iostream>
#include <fstream>
#include "Game.h"

int main(int argc, char* argv[]) {
	
	if(argc < 3 || argc > 4) {
		std::cout << "Invalid argument list.\n";
	} else {
		std::string fileOut = "";
		if(argc == 4) {
			fileOut = std::string(argv[3]);
		}
		Game replay(*argv[1], argv[2], fileOut);
		replay.setBattlefield();
		replay.playReplay();
	}

	return 0;
}