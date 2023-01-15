//2032460 Van Sang Ho
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Position.h"

class Grid {
protected:
    //2D vector representing the content of the grid's tiles
    std::vector<std::vector<char>> tiles_;

    //Tests if a given Position is valid (as in within the limits of the Grid)
    bool isPosValid(Position pos);

public:
    //Constructors
    Grid() : tiles_{std::vector<std::vector<char>>()} {}
    Grid(unsigned int rows, unsigned int cols);
    //default Destructor
    ~Grid() {}
    
    //Returns the number of rows of the Grid
    int getRows() const;
    //Returns the number of columns of the Grid
    int getColumns() const;

    //Prints the Grid and its contents on the desired output stream (e.g. std::cout, std::ofstream, etc.)
    void printGrid(std::ostream& os);
};

//Constants indicating "high ASCII" characters used to display the Grid
#ifdef _WIN32   //code page 437 characters for Windows console
static constexpr char cornerLU = 218;           // ┌
static constexpr char cornerLD = 192;           // └
static constexpr char cornerRU = 191;           // ┐
static constexpr char cornerRD = 217;           // ┘
static constexpr char lineH = 196;              // ─
static constexpr char lineV = 179;              // │
static constexpr char connectL = 180;           // ┤
static constexpr char connectR = 195;           // ├
static constexpr char connectU = 193;           // ┴
static constexpr char connectD = 194;           // ┬
static constexpr char connectLR = 197;          // ┼
#else           //Unicode alternatives for Unix systems
static constexpr char cornerLU[] = "\u250C";    // ┌
static constexpr char cornerLD[] = "\u2514";    // └
static constexpr char cornerRU[] = "\u2510";    // ┐
static constexpr char cornerRD[] = "\u2518";    // ┘
static constexpr char lineH[] = "\u2500";       // ─
static constexpr char lineV[] = "\u2502";       // │
static constexpr char connectL[] = "\u2524";    // ┤
static constexpr char connectR[] = "\u251C";    // ├
static constexpr char connectU[] = "\u2534";    // ┴
static constexpr char connectD[] = "\u252C";    // ┬
static constexpr char connectLR[] = "\u253C";   // ┼

#endif

#include "Grid.hpp"

#endif