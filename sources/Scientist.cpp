#include <string>
using namespace std;

#include "Scientist.hpp"

namespace pandemic
{
    Scientist &Scientist::discover_cure(Color color)
    {
        if (!board.hasDisCure(color))
        {
            int temp = 0;
            for (const auto &cityCard : cardsCity)
            {
                if (Board::colorCity.at(cityCard) == color)
                {
                    temp++;
                }
            }
            if (temp < number || !board.hasResStation(city))
            {
                throw invalid_argument("error!");
            }
            int count = 1;
            auto it = cardsCity.begin();
            while (it != cardsCity.end())
            {
                if (Board::colorCity.at(*it) == color && count != number)
                {
                    it = cardsCity.erase(it);
                    count++;
                }
                else
                {
                    it++;
                }
            }
            board.addDisCure(color);
        }
        return *this;
    }
}