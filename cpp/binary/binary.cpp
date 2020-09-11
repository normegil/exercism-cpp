#include "binary.h"

#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

namespace binary
{
    const int BASE = 2;
    const std::vector<char> ALLOWED = {'0', '1'};

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

    long convert(std::string binary)
    {
        if (!valid(binary))
        {
            return 0;
        }
        

        int length = static_cast<int>(binary.length());
        long sum{0};
        for (int i = 0; i < length; i++)
        {
            int val = binary[i] - '0';
            sum += val * std::pow(BASE, length - i - 1);
        }
        return sum;
    }
} // namespace binary
