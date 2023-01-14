
#ifndef POSITION_HPP
#define POSITION_HPP

#include "Position.h"

char Position::numberToLetter(int n) {
    if(n < 0 || n >= 21) {
        return '?';
    }

    if(n < 9) {
        return char('A' + n);
    } else if (n < 20) {
        return char('A' + n + 2);
    } else {
        return char('A' + n + 5);
    }
}

int Position::letterToNumber(char l) {
    l = toupper(l);
    if(l < 'A' || l > 'Z') {
        return -1;
    } 

    if(l < 'J') {
        return l - 'A';
    } else if (l < 'W') {
        return l - 2  - 'A';
    } else {
        return l - 5  - 'A';
    }
}

bool Position::operator==(const Position& p) {
    return (x_ == p.getX() && y_ == p.getY());
}

bool Position::operator!=(const Position& p) {
    return (x_ != p.getX() || y_ != p.getY());
}

Position& Position::operator=(const Position& p) {
    x_ = p.getX();
    y_ = p.getY();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Position& p) {
    os << "[" << p.getX() << ", " << p.getY() << "]";
    return os;
}

#endif