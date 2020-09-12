#include "hexadecimal.h"

#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>

namespace hexadecimal
{
    const int BASE = 16;
    const std::vector<char> ALLOWED = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    long valid(std::string binary)
    {
        for (auto &&c : binary)
        {
            auto found = std::find(ALLOWED.begin(), ALLOWED.end(), toupper(c));
            if (found == ALLOWED.end())
            {
                return false;
            }
        }
        return true;
    }

    int to_number(char c)
    {
        char upper_c = toupper(c);
        if (isdigit(upper_c))
        {
            return upper_c - '0';
        }
        else if (upper_c == 'A')
        {
            return 10;
        }
        else if (upper_c == 'B')
        {
            return 11;
        }
        else if (upper_c == 'C')
        {
            return 12;
        }
        else if (upper_c == 'D')
        {
            return 13;
        }
        else if (upper_c == 'E')
        {
            return 14;
        }
        else if (upper_c == 'F')
        {
            return 15;
        }
        return 0;
    }

    long convert(std::string hexa)
    {
        if (!valid(hexa))
        {
            return 0;
        }

        int length = static_cast<int>(hexa.length());
        long sum{0};
        for (int i = 0; i < length; i++)
        {
            int val = to_number(hexa[i]);
            sum += val * std::pow(BASE, length - i - 1);
        }
        return sum;
    }
} // namespace hexadecimal
