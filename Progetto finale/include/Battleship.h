#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

class Battleship : public Ship{
private:

public:
    Battleship();
    ~Battleship() override = default;
    void action() override;
};

#include "Battleship.hpp"

#endif