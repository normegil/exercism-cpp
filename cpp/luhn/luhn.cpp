#include "luhn.h"

#include <vector>
#include <algorithm>
#include <algorithm>

namespace luhn
{
    std::string trim(const std::string &str)
    {
        size_t first = str.find_first_not_of(' ');
        if (std::string::npos == first)
        {
            return str;
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    bool valid(std::string test_luhn)
    {

        auto trimmed = trim(test_luhn);

        if (trimmed.size() < 2)
        {
            return false;
        }

        std::vector<int> numbers{};

        for (auto &&c : trimmed)
        {
            if (' ' == c)
            {
                continue;
            }
            else if (!std::isdigit(c))
            {
                return false;
            }

            numbers.push_back(c - '0');
        }

        std::reverse(numbers.begin(), numbers.end());

        int sum;
        for (int i = 0; i < static_cast<int>(numbers.size()); i++)
        {
            if ((i + 1) % 2 == 0)
            {
                int tmp = numbers[i] * 2;
                if (tmp > 9)
                {
                    tmp -= 9;
                }
                sum += tmp;
            }
            else
            {
                sum += numbers[i];
            }
        }

        return sum % 10 == 0;
    }

} // namespace luhn
