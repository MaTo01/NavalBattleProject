//2032460 Van Sang Ho
#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include "Grid.h"

Grid::Grid() {
    for(int i=0; i<12; i++)
        for(int j=0; j<12; j++)
            tiles[i][j] = ' ';
}

void Grid::printGrid(std::ostream& os) {
    os<<cornerLU;
    for(int i=0; i<11; i++){
        os<<lineH<<connectD;
    }
    os<<lineH<<cornerRU<<"\n";

    for(int i=0; i<12; i++) {
        for(int j=0; j<12; j++){
            os<<lineV<<tiles[i][j];
        }
        os<<lineV<<"\n";
        if(i<11) {
            os<<connectR;
            for(int j=0; j<11; j++){
                os<<lineH<<connectLR;
            }
            os<<lineH<<connectL<<"\n";
        }
    }

    os<<cornerLD;
    for(int i=0; i<11; i++){
        os<<lineH<<connectU;
    }
    os<<lineH<<cornerRD<<"\n";
}

#endif