#include <string>
using namespace std;

#include "FieldDoctor.hpp"

namespace pandemic
{
    FieldDoctor &FieldDoctor::treat(City c)
    {
        if ((city != c && Board::connection.at(city).count(c) == 0) || board[c] == 0)
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
}