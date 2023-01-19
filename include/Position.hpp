//2032460 Van Sang Ho
#ifndef POSITION_HPP
#define POSITION_HPP

#include "Position.h"

char Position::numberToLetter(int n) {
    if(n < 0 || n >= 21) {
        return '?';
    }

    if(n < 9) {
        return char('A' + n);       //A to I
    } else if (n < 20) {
        return char('A' + n + 2);   //L to V (J, K are skipped)
    } else {
        return char('A' + n + 5);   //Z (J, K, W, X, Y are skipped)
    }
}

//This function uses the Italian alphabet (21 letters)
int Position::letterToNumber(char l) {
    l = toupper(l);
    switch (l) {
        case 'J':
        case 'K':
        case 'W':
        case 'X':
        case 'Y':
            return -1;
        default:
            if(l < 'A' || l > 'Z') {
                return -1;
            }

            if(l < 'J') {
                return l - 'A';         //0 to 8
            } else if (l < 'W') {
                return l - 2  - 'A';    //9 to 19 (J, K are skipped)
            } else {
                return l - 5  - 'A';    //20 (J, K, W, X, Y are skipped)
            }
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