#include <string>
using namespace std;

#include "Dispatcher.hpp"

namespace pandemic
{
    Dispatcher &Dispatcher::fly_direct(City c)
    {
        if (board.hasResStation(city) && city != c)
        {
            city = c;
        }
        else
        {
            Player::fly_direct(c);
        }
        return *this;
    }
}