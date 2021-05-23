//
// Created by Liron on 28/04/2021.
//

#include "Scientist.hpp"

pandemic::Player& pandemic::Scientist::discover_cure(pandemic::Color color) {
    if (!board.getStation(current)) {
        throw std::invalid_argument("there is no research ignoreStation in " + pandemic::Board::toString(current));
    }

    vector<City> sameColor;
    for (auto card: cards) {
        if (board.getColor(card) == color) {
            sameColor.push_back(card);
        }
    }
    if (sameColor.size() < n) {
        if (!board.getCure(color)) {
            throw std::invalid_argument(
                    "you dont have enough cards, you only have only " + to_string(sameColor.size()));
        }
        return *this;
    }
    for (unsigned int i = 0; i < n; ++i) {
        cards.remove(sameColor[i]);
    }
    board.setCure(color, true);

    return *this;
}

string pandemic::Scientist::role() {
    return "Scientist";
}
