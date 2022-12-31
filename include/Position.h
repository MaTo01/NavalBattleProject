//Ho Van Sang
#ifndef POSITION_H
#define POSITION_H
#include <iostream>
    
class Position {
private:
    int x;
    int y;
    
public:
    Position(int a = 0, int b = 0) : x{a}, y{b} {}
    
    void setX(int a) { x = a; }
    void setY(int b) { y = b; }
    int getX() const { return x; }
    int getY() const { return y; }

    bool operator==(const Position& p);
    bool operator!=(const Position& p);
    Position& operator=(const Position& p);
};

std::ostream& operator<<(std::ostream& os, const Position& p);

#include "Position.hpp"

#endif