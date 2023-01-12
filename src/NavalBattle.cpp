#include <iostream>
#include <fstream>
#include <memory>
#include "Game.h"

int main()
{
	DefenseGrid* enemyDG = new DefenseGrid(12,12);
	AttackGrid* enemyAG = new AttackGrid(12,12);
	DefenseGrid* myDG = new DefenseGrid(12,12);
	AttackGrid* myAG = new AttackGrid(12,12);

	//std::unique_ptr<Ship> s = std::make_unique<Battleship>(Position(0,3), Position(0,7), enemyAG);

	SupportShip* ss = new SupportShip(Position(8,8), Position(10,8), enemyDG);
	enemyDG->placeShip(new Battleship(Position(4,3), Position(4,7), enemyAG));
	enemyDG->placeShip(ss);
	enemyDG->placeShip(new Submarine(Position(1,1), Position(1,1), enemyAG, enemyDG));
	std::cout<<"\t\t\tEnemy defense grid:\n";
	enemyDG->printGrid(std::cout);
	std::cout<<"\n\t\t\tMy attack grid:\n";
	myAG->printGrid(std::cout);

	Battleship* b = new Battleship(Position(4,3), Position(4,7), myAG);
	b->action(Position(4, 4), enemyDG);
	//b->action(Position(1,1), enemyDG);
	std::cout<<"\n\t\t\tEnemy defense grid:\n";
	enemyDG->printGrid(std::cout);
	std::cout<<"\n\t\t\tMy attack grid:\n";
	myAG->printGrid(std::cout);

	enemyDG->moveShip(ss, Position(8,8));
	std::cout<<"\n\t\t\tEnemy defense grid:\n";
	enemyDG->printGrid(std::cout);

	ss->action(Position(4,8));
	std::cout<<"\n\t\t\tEnemy defense grid:\n";
	enemyDG->printGrid(std::cout);

	Submarine* s = new Submarine(Position(1,1), Position(1,1), myAG, myDG);
	myDG->placeShip(s);
	s->action(Position(4,8), enemyDG);
	std::cout<<"\n\t\t\tMy attack grid:\n";
	myAG->printGrid(std::cout);

	return 0;
}