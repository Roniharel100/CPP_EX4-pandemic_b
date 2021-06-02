#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &b, City c) : Player(b, c, "Medic") {}
        Medic &drive(City);
        Medic &fly_direct(City) override;
        Medic &fly_charter(City);
        Medic &fly_shuttle(City);
        Medic &treat(City city) override;
    };
}