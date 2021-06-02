#include <string>
using namespace std;

#include "GeneSplicer.hpp"

namespace pandemic
{
    GeneSplicer &GeneSplicer::discover_cure(Color color)
    {
        const int CARDS = 5;

        if (!board.hasDisCure(color))
        {
            if (cardsCity.size() < CARDS || !board.hasResStation(city))
            {
                throw invalid_argument("error!");
            }
            int count = 1;
            for (auto it = cardsCity.begin(); it != cardsCity.end(); it++)
            {
                if (count != CARDS)
                {
                    it = cardsCity.erase(it);
                    count++;
                }
            }
            board.addDisCure(color);
        }
        return *this;
    }

}