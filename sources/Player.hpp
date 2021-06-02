#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic
{
    class Player
    {
    protected:
        Board &board;
        City city;
        std::string playerRole;
        std::set<City> cardsCity;

    public:
        Player(Board &b, City c, std::string role = "Player") : board(b), city(c), playerRole(role) {}

        Player &drive(City c);
        virtual Player &fly_direct(City c);
        Player &fly_charter(City c);
        Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City c);
        std::string role();
        Player &take_card(City c);
        void remove_cards();
    };
}