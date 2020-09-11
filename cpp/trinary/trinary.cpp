#include "trinary.h"

#include <cmath>
#include <vector>
#include <algorithm>

namespace trinary
{
    const int BASE = 2;
    const std::vector<char> ALLOWED = {'0', '1', '2'};

    long valid(std::string binary)
    {
        for (auto &&c : binary)
        {
            auto found = std::find(ALLOWED.begin(), ALLOWED.end(), c);
            if (found == ALLOWED.end())
            {
                return false;
            }
        }
        return true;
    }

    int to_number(char c)
    {
        return c - '0';
    }

    long to_decimal(std::string trinary)
    {
        if (!valid(trinary))
        {
            return 0;
        }

        int length = static_cast<int>(trinary.length());
        long sum{0};
        for (int i = 0; i < length; i++)
        {
            int val = trinary[i] - '0';
            sum += val * std::pow(BASE, length - i - 1);
        }
        return sum;
    }
} // namespace trinary
