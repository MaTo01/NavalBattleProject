#ifndef SUPPORTSHIP_H
#define SUPPORTSHIP_H

#include "Ship.h"

class SupportShip : public Ship{
private:

public:
    SupporShip();
    ~SupportShip() override = default;
    void action() override;
};

#endif