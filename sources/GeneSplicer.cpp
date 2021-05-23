//
// Created by Liron on 28/04/2021.
//

#include "GeneSplicer.hpp"

const unsigned int FIVE = 5;


pandemic::Player& pandemic::GeneSplicer::discover_cure(pandemic::Color color) {
    if (!board.getStation(current)) {
        throw std::invalid_argument("there is no research ignoreStation in " + pandemic::Board::toString(current));
    }

    if (cards.size() < FIVE) {
        if (!board.getCure(color)) {
            throw std::invalid_argument(
                    "you dont have enough cards, you only have only " + to_string(cards.size()));
        }
        return *this;
    }
    for (unsigned int i = 0; i < FIVE; ++i) {
        cards.remove(*cards.begin());
    }
    board.setCure(color, true);

    return *this;
}

string pandemic::GeneSplicer::role() {
    return "GeneSplicer";
}
