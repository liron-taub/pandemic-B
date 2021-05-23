//
// Created by Liron on 28/04/2021.
//

#include "FieldDoctor.hpp"

pandemic::Player& pandemic::FieldDoctor::treat(pandemic::City city) {
    if(!board.isNeighbors(city,current)){
        throw std::invalid_argument("not neighbors");
    }
    if (board[city] <= 0) {
        throw std::invalid_argument("no more cubes remain in " + pandemic::Board::toString(city));
    }
    if (board.getCure(board.getColor(city))) {
        board[city] = 0;
    } else {
        board[city]--;
    }
    return *this;
}

string pandemic::FieldDoctor::role() {
    return "FieldDoctor";
}
