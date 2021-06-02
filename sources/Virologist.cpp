#include <string>
using namespace std;

#include "Virologist.hpp"

namespace pandemic
{
    Virologist &Virologist::treat(City c)
    {
        if (city != c)
        {
            if (board[c] == 0 || cardsCity.count(c) == 0)
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
            cardsCity.erase(c);
        }
        else
        {
            Player::treat(c);
        }
        return *this;
    }
}