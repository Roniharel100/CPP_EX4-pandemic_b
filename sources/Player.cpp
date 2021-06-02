#include <string>
using namespace std;

#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"

namespace pandemic
{
    //------------------------------------------------------------------------------
    Player &Player::drive(City c)
    {
        if (Board::connection.at(city).count(c) == 0)
        {
            throw invalid_argument("error!");
        }
        city = c;
        return *this;
    }

    //------------------------------------------------------------------------------
    Player &Player::fly_direct(City c)
    {
        if (cardsCity.count(c) == 0)
        {
            throw invalid_argument("error!");
        }
        cardsCity.erase(c);
        city = c;
        return *this;
    }

    //------------------------------------------------------------------------------
    Player &Player::fly_charter(City c)
    {
        if (cardsCity.count(city) == 0)
        {
            throw invalid_argument("error!");
        }
        cardsCity.erase(city);
        city = c;
        return *this;
    }

    //------------------------------------------------------------------------------
    Player &Player::fly_shuttle(City c)
    {
        if (city == c)
        {
            throw invalid_argument("error!");
        }
        if (!board.hasResStation(city))
        {
            throw invalid_argument("error!");
        }
        if (!board.hasResStation(c))
        {
            throw invalid_argument("error!");
        }
        city = c;
        return *this;
    }

    //------------------------------------------------------------------------------
    Player &Player::build()
    {
        if (cardsCity.count(city) == 0)
        {
            throw invalid_argument("error!");
        }
        board.addResStation(city);
        cardsCity.erase(city);
        return *this;
    }

    //------------------------------------------------------------------------------
    Player &Player::discover_cure(Color color)
    {
        const int CARDS = 5;

        if (!board.hasDisCure(color))
        {
            int checkNumOfCards = 0;
            for (const auto &cityCard : cardsCity)
            {
                if (Board::colorCity.at(cityCard) == color)
                {
                    checkNumOfCards++;
                }
            }
            if (checkNumOfCards < CARDS || !board.hasResStation(city))
            {
                throw invalid_argument("error!");
            }
            int count = 1;
            auto it = cardsCity.begin();
            while (it != cardsCity.end())
            {
                if (count < CARDS && Board::colorCity.at(*it) == color)
                {
                    cardsCity.erase(it++);
                    count++;
                }
                else
                {
                    ++it;
                }
            }
            board.addDisCure(color);
        }
        return *this;
    }

    //------------------------------------------------------------------------------
    Player &Player::treat(City c)
    {
        if (board[c] == 0)
        {
            throw invalid_argument("error!");
        }
        if (!board.hasDisCure(Board::colorCity.at(c)))
        {
            board[c]--;
        }
        else
        {
            board[c] = 0;
        }
        return *this;
    }

    //------------------------------------------------------------------------------
    string Player::role()
    {
        return playerRole;
    }

    //------------------------------------------------------------------------------
    Player &Player::take_card(City c)
    {
        cardsCity.insert(c);
        return *this;
    }

    //------------------------------------------------------------------------------
    void Player::remove_cards()
    {
        cardsCity.clear();
    }
}