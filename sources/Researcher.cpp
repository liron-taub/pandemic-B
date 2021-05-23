//
// Created by Liron on 28/04/2021.
//

#include "Researcher.hpp"
const unsigned int FIVE = 5;

pandemic::Player& pandemic::Researcher::discover_cure(pandemic::Color color) {
    vector<City> sameColor;
    for (auto card: cards) {
        if (board.getColor(card) == color) {
            sameColor.push_back(card);
        }
    }
    if (sameColor.size() < FIVE) {
        if (!board.getCure(color)) {
            throw std::invalid_argument(
                    "you dont have enough cards, you only have only " + to_string(sameColor.size()));
        }
        return *this;
    }
    for (unsigned int i = 0; i < FIVE; ++i) {
        cards.remove(sameColor[i]);
    }
    board.setCure(color, true);

    return *this;
}

string pandemic::Researcher::role() {
    return "Researcher";
}
