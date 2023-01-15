//2032460 Van Sang Ho
#ifndef POSITION_H
#define POSITION_H
#include <iostream>
    
class Position {
private:
    int x_;
    int y_;
    
public:
    //Constructor
    Position(int a = 0, int b = 0) 
        : x_{a}, y_{b} {}
    //default destructor
    ~Position() {}

    //Get functions
    int getX() const { return x_; }
    int getY() const { return y_; }
    //Set functions
    void setX(int a) { x_ = a; }
    void setY(int b) { y_ = b; }

    //Converts a numerical coordinate into a letter of the Italian alphabet
    static char numberToLetter(int n);
    //Converts a letter of the Italian alphabet into a numerical coordinate
    static int letterToNumber(char l);

    //'==' operator overloading
    bool operator==(const Position& p);
    //'!=' operator overloading
    bool operator!=(const Position& p);
    //Assignment operator overloading
    Position& operator=(const Position& p);
};

//'<<' operator overloading
std::ostream& operator<<(std::ostream& os, const Position& p);

#include "Position.hpp"

#endif