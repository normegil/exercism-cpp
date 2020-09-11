#include "raindrops.h"

namespace raindrops
{
    std::string convert(int n)
    {
        std::string toReturn;
        if (n % 3 == 0)
        {
            toReturn += "Pling";
        }

        if (n % 5 == 0)
        {
            toReturn += "Plang";
        }

        if (n % 7 == 0)
        {
            toReturn += "Plong";
        }

        if (toReturn.empty())
        {
            return std::to_string(n);
        }

        return toReturn;
    }
} // namespace raindrops
