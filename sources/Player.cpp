//
// Created by Liron on 28/04/2021.
//


#include "Player.hpp"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace pandemic;

const unsigned int FIVE = 5;


pandemic::Player &pandemic::Player::fly_direct(pandemic::City city) {
    if (city == current) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (find(cards.begin(), cards.end(), city) != cards.end()) {
        cards.remove(city);
        current = city;
    } else {
        throw std::invalid_argument("you do not have the card of the city");
    }
    //  מחזיר את הדבר עצמו, שלא יעבוד על עותק
    return *this;
}

pandemic::Player &pandemic::Player::drive(pandemic::City city) {
    if (city == current) {
        throw std::invalid_argument("cannot drive from city to it self");
    }
    if (board.isNeighbors(city, current)) {
        current = city;
    } else {
        throw std::invalid_argument("the cards is not connected");
    }
    return *this;
}

pandemic::Player &pandemic::Player::fly_charter(pandemic::City city) {
    if (city == current) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (find(cards.begin(), cards.end(), current) != cards.end()) {
        cards.remove(current);
        current = city;
    } else {
        throw std::invalid_argument("you do not have the card of " + pandemic::Board::toString(current));
    }
    return *this;
}

pandemic::Player &pandemic::Player::fly_shuttle(pandemic::City city) {
    if (city == current) {
        throw std::invalid_argument("cannot fly from city to it self");
    }
    if (board.getStation(current) && board.getStation(city)) {
        current = city;
    } else {
        throw std::invalid_argument("there is no research station" );
    }
    return *this;
}

pandemic::Player &pandemic::Player::build() {
    if (find(cards.begin(), cards.end(), current) != cards.end()) {
        cards.remove(current);
        board.setStation(current, true);
    } else {
        throw std::invalid_argument("you dont have the card of " + pandemic::Board::toString(current));
    }
    return *this;
}

pandemic::Player &pandemic::Player::discover_cure(pandemic::Color color) {
    if (!board.getStation(current)) {
        throw std::invalid_argument("there is no research ignoreStation in " + pandemic::Board::toString(current));
    }

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

    return *this;}

pandemic::Player &pandemic::Player::treat(pandemic::City city) {
    if (city != current) {
        throw std::invalid_argument("you are not in " + pandemic::Board::toString(city));
    }
    if (board[current] <= 0) {
        throw std::invalid_argument("no more cubes remain in " + pandemic::Board::toString(current));
    }
    if (board.getCure(board.getColor(current))) {
        board[current] = 0;
    } else {
        board[current]--;
    }
    return *this;
}

pandemic::Player &pandemic::Player::take_card(pandemic::City city) {
    if (find(cards.begin(), cards.end(), city) == cards.end()) {
        cards.push_front(city);
    }
    return *this;
}

string Player::role() {
    return std::string();
}
//קונסארקטור הצבה
Player::Player(Board &board, City city) : board(board) {
    this->current = city;
}


pandemic::Player &pandemic::Player::remove_cards() {
    cards.clear();
    return *this;

}


