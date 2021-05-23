//
// Created by Liron on 28/04/2021.
//

#include "Dispatcher.hpp"

pandemic::Player &pandemic::Dispatcher::fly_direct(pandemic::City city) {
    if (city == current) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (board.getStation(current)) {
        current = city;
        return *this;
    }
    if (find(cards.begin(), cards.end(), city) != cards.end()) {
        cards.remove(city);
        current = city;
    } else {
        if (!board.getStation(current)) {
            throw std::invalid_argument("there is no research station");
        }
        throw std::invalid_argument("you do not have the card of the city");
    }
    return *this;
}

string pandemic::Dispatcher::role() {
    return "Dispatcher";
}
