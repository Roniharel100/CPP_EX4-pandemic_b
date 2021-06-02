#include <string>
using namespace std;

#include "Researcher.hpp"

namespace pandemic
{
    Researcher &Researcher::discover_cure(Color color)
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
            if (checkNumOfCards < CARDS)
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
}