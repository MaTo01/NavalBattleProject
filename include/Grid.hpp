//2032460 Van Sang Ho
#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include "Grid.h"

Grid::Grid(unsigned int rows, unsigned int cols) {
    std::vector<char> aux;
    for(int i=0; i<rows; i++) {
        aux.clear();
        for(int j=0; j<cols; j++)
            aux.push_back(' ');
        tiles.push_back(aux);
    } 
}

bool Grid::isPosValid(Position p) {
    if(p.getX()<0 || p.getY()<0)
        return false;
    if(p.getX()>=tiles.size() || p.getY()>=tiles[0].size())
        return false;
    return true;
}

void Grid::printGrid(std::ostream& os) {
    
    os<<"\t   ";
    for(int i=1; i<=tiles.size(); i++) {
        os<<" "<<i;
        if(i<=9)
            os<<" ";
        os<<" ";
    }
    os<<"\n";

    os<<"\t  "<<cornerLU;
    for(int i=0; i<tiles.size()-1; i++){
        os<<lineH<<lineH<<lineH<<connectD;
    }
    os<<lineH<<lineH<<lineH<<cornerRU<<"\n";

    //table body
    for(int i=0; i<tiles.size(); i++) {
        os<<"\t"<<((i<9)?char(65+i):char(65+i+2))<<" ";

        for(int j=0; j<tiles[i].size(); j++){
            os<<lineV<<" "<<tiles[i][j]<<" ";
        }
        os<<lineV<<"\n";

        if(i<tiles.size()-1) {
            os<<"\t  "<<connectR;
            for(int j=0; j<tiles[i].size()-1; j++){
                os<<lineH<<lineH<<lineH<<connectLR;
            }
            os<<lineH<<lineH<<lineH<<connectL<<"\n";
        }
    }

    os<<"\t  "<<cornerLD;
    for(int i=0; i<tiles.size()-1; i++){
        os<<lineH<<lineH<<lineH<<connectU;
    }
    os<<lineH<<lineH<<lineH<<cornerRD<<"\n";
}

#endif