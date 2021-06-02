#include "OperationsExpert.hpp"

namespace pandemic
{
    OperationsExpert &OperationsExpert::build()
    {
        board.addResStation(city);
        return *this;
    }
}