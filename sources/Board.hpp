//
// Created by Liron on 28/04/2021.
//

#ifndef DEMO1_CPP_BOARD_HPP
#define DEMO1_CPP_BOARD_HPP

#include <vector>
#include <string>
#include <map>
#include <list>
#include "City.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic {
    class Board {
    private:
        map<City, list<City>> neighbors;
        map<City, Color> colors;
        map<City, int> levels;
        map<Color, bool> cures;
        map<City, bool> stations;

    public:
        Board();
        static string toString(City city);
        int& operator[](City city);//If there was no empress we could not both accept and change
        bool isNeighbors(City city1, City city2);
        bool getStation(City city);
        Color getColor(City city);
        void setStation(City city, bool station);
        void setCure(Color color, bool cure);
        bool getCure(Color color);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        friend ostream &operator<<(ostream &os, Board &board);//Friend lets him access the department's private fields
    };
}


#endif //DEMO1_CPP_BOARD_HPP
