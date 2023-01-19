//2032460 Van Sang Ho
#ifndef POSITION_H
#define POSITION_H
#include <iostream>
    
//Class representing a simple (X,Y) Position
class Position {
private:
    //X and Y coordinates
    int x_;
    int y_;
    
public:
    //Constructor
    Position(int a = 0, int b = 0) 
        : x_{a}, y_{b} {}
    //Default destructor
    ~Position() {}

    //Get functions
    int getX() const { return x_; }
    int getY() const { return y_; }
    //Set functions
    void setX(int a) { x_ = a; }
    void setY(int b) { y_ = b; }

    
    //Converts a numerical coordinate into a letter
    static char numberToLetter(int n);
    //Converts a letter into a numerical coordinate
    static int letterToNumber(char l);
    //Both of the above functions use the Italian alphabet (21 letters)

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