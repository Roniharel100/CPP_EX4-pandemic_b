#include <string>
using namespace std;

#include "Medic.hpp"

namespace pandemic
{
    Medic &Medic::drive(City c)
    {
        Player::drive(c);
        if (board.hasDisCure(Board::colorCity.at(c)))
        {
            board[city] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_direct(City c)
    {
        Player::fly_direct(c);
        if (board.hasDisCure(Board::colorCity.at(c)))
        {
            board[city] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_charter(City c)
    {
        Player::fly_charter(c);
        if (board.hasDisCure(Board::colorCity.at(c)))
        {
            board[city] = 0;
        }
        return *this;
    }

    Medic &Medic::fly_shuttle(City c)
    {
        Player::fly_shuttle(c);
        if (board.hasDisCure(Board::colorCity.at(c)))
        {
            board[city] = 0;
        }
        return *this;
    }

    Medic &Medic::treat(City city)
    {
        Player::treat(city);
        board[city] = 0;
        return *this;
    }
}