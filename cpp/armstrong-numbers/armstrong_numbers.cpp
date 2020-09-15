#include "armstrong_numbers.h"

#include <cmath>
#include <vector>
#include <iostream>

namespace armstrong_numbers
{
    bool is_armstrong_number(int nb)
    {
        std::vector<int> decomposed{};

        int i = 1;
        while (i < nb)
        {
            int digit = nb % (i * 10);
            digit /= i;
            decomposed.push_back(digit);
            i *= 10;
        }

        int recomposed{};
        int length = static_cast<int>(decomposed.size());
        for (auto &&n : decomposed)
        {
            recomposed += std::pow(n, length);
        }

        return recomposed == nb;
    }
} // namespace armstrong_numbers
