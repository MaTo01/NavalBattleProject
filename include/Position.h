
#ifndef POSITION_H
#define POSITION_H
#include <iostream>
    
class Position {
private:
    int x_;
    int y_;
    
public:
    Position(int a = 0, int b = 0) : x_{a}, y_{b} {}
    
    void setX(int a) { x_ = a; }
    void setY(int b) { y_ = b; }
    int getX() const { return x_; }
    int getY() const { return y_; }

    static char numberToLetter(int n);
    static int letterToNumber(char l);

    bool operator==(const Position& p);
    bool operator!=(const Position& p);
    Position& operator=(const Position& p);
};

std::ostream& operator<<(std::ostream& os, const Position& p);

#include "Position.hpp"

#endif