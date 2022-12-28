#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship{
private:

public:
    Submarine();
    ~Submarine() override = default;
    void action() override;
};

#include "Submarine.hpp"

#endif