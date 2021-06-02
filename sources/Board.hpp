#pragma once
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
    private:
        std::map<City, int> pandemic;
        std::set<Color> discoveredCure;
        std::set<City> researchStation;

    public:
        static std::map<City, std::set<City>> connection;
        static std::map<City, Color> colorCity;

        int &operator[](City city);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        friend std::ostream &operator<<(std::ostream &os, const Board &board);

        bool hasDisCure(Color color);
        bool hasResStation(City city);
        void addDisCure(Color color);
        void addResStation(City city);
    };
}