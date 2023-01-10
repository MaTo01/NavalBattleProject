//2032460 Van Sang Ho
#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include "Grid.h"

Grid::Grid(unsigned int rows, unsigned int cols) {
    std::vector<char> aux;
    for(int i = 0; i < rows; i++) {
        aux.clear();
        for(int j = 0; j < cols; j++)
            aux.push_back(' ');
        tiles_.push_back(aux);
    } 
}

bool Grid::isPosValid(Position pos) {
    if(pos.getX() < 0 || pos.getY() < 0)
        return false;
    if(pos.getX() >= tiles_.size() || pos.getY() >= tiles_[0].size())
        return false;
    return true;
}

void Grid::printGrid(std::ostream& os) {
    
    os << "\t   ";
    for(int i = 1; i <= tiles_.size(); i++) {
        os << " " << i;
        if(i <= 9)
            os << " ";
        os << " ";
    }
    os << "\n";

    os << "\t  " << cornerLU;
    for(int i = 0; i < tiles_.size() - 1; i++){
        os << lineH << lineH << lineH << connectD;
    }
    os << lineH << lineH << lineH << cornerRU << "\n";

    //table body
    for(int i = 0; i < tiles_.size(); i++) {
        os << "\t" << ((i <9 ) ? char(65 + i) : char(65 + i + 2)) << " ";

        for(int j = 0; j < tiles_[i].size(); j++) {
            os << lineV << " " << tiles_[i][j] << " ";
        }
        os << lineV << "\n";

        if(i < tiles_.size() - 1) {
            os << "\t  " << connectR;
            for(int j = 0; j < tiles_[i].size() - 1; j++){
                os << lineH << lineH << lineH << connectLR;
            }
            os << lineH << lineH << lineH << connectL << "\n";
        }
    }

    os << "\t  " << cornerLD;
    for(int i = 0; i < tiles_.size() - 1; i++){
        os << lineH << lineH << lineH << connectU;
    }
    os << lineH << lineH << lineH << cornerRD << "\n";
}

#endif