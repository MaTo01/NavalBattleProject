//2043414 Marco Toffoletto
#ifndef SUPPORTSHIP_H
#define SUPPORTSHIP_H

#include "Ship.h"

class SupportShip : public Ship{
private:

public:
    //Constructor
    SupporShip(): Ship(3,3){}
    //Destructor
    ~SupportShip() override = default;

    void action() override;
};

#include "SupportShip.hpp"

#endif