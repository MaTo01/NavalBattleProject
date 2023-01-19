//2032460 Van Sang Ho
#ifndef GRID_HPP
#define GRID_HPP

#include "Grid.h"

Grid::Grid(unsigned int rows, unsigned int cols) {
    std::vector<char> aux;
    //all the tiles are initialized as empty (' ')
    for(int i = 0; i < rows; i++) {
        aux.clear();
        for(int j = 0; j < cols; j++)
            aux.push_back(' ');
        tiles_.push_back(aux);
    }
}

int Grid::getRows() const {
    return tiles_.size();
}

int Grid::getColumns() const {
    if(tiles_.size() > 0)
        return tiles_[0].size();
    return 0;
}

bool Grid::isPosValid(Position pos) {
    if(pos.getX() < 0 || pos.getY() < 0) {
        return false;
    }
    if(pos.getX() >= tiles_.size() || pos.getY() >= tiles_[0].size()) {
        return false;
    }
    return true;
}

void Grid::printGrid(std::ostream& os) {
    //Column headers
    os << "\t   ";
    for(int i = 1; i <= tiles_.size(); i++) {
        os << " " << i;
        if(i <= 9)          //an additional space to account for single digit numbers
            os << " ";
        os << " ";
    }
    os << "\n";

    //Upper border
    os << "\t  " << cornerLU;
    for(int i = 0; i < tiles_.size(); i++){
        os << lineH << lineH << lineH;
        if(i < tiles_.size() - 1) {
            os << connectD;
        } else {
            os << cornerRU << "\n";
        }
    }

    //Main body of the Grid
    for(int i = 0; i < tiles_.size(); i++) {
        //Row headers
        os << "\t" << Position::numberToLetter(i) << " ";

        //Row cells and their contents
        for(int j = 0; j < tiles_[i].size(); j++) {
            os << lineV << " " << tiles_[i][j] << " ";
        }
        os << lineV << "\n";

        //If the current row is not the last one, a row separator is added
        if(i < tiles_.size() - 1) {
            os << "\t  " << connectR;
            for(int j = 0; j < tiles_[i].size() - 1; j++){
                os << lineH << lineH << lineH << connectLR;
            }
            os << lineH << lineH << lineH << connectL << "\n";
        }
    }

    //Lower border
    os << "\t  " << cornerLD;
    for(int i = 0; i < tiles_.size(); i++){
        os << lineH << lineH << lineH;
        if(i < tiles_.size() - 1) {
            os << connectU;
        } else {
            os << cornerRD << "\n";
        }
    }
}

#endif