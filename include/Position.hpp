//Ho Van Sang
#ifndef POSITION_HPP
#define POSITION_HPP

#include "Position.h"
#include <iostream>

bool Position::operator==(const Position& p) {
    return (x==p.getX() && y==p.getY());
}

bool Position::operator!=(const Position& p) {
    return (x!=p.getX() || y!=p.getY());
}

Position& Position::operator=(const Position& p) {
    x = p.getX();
    y = p.getY();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Position& p) {
    os<<"["<<p.getX()<<", "<<p.getY()<<"]";
    return os;
}

#endif