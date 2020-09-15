#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture
{
    int steps(int start)
    {
        if (start < 1)
        {
            throw std::domain_error("Invalid start");
        }

        int tmp{start};
        int nbSteps{};
        while (tmp != 1)
        {
            if (tmp % 2 == 0)
            {
                tmp /= 2;
            }
            else
            {
                tmp = 3 * tmp + 1;
            }
            nbSteps++;
        }
        return nbSteps;
    }
} // namespace collatz_conjecture
