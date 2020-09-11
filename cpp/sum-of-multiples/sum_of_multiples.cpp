#include "sum_of_multiples.h"

#include <numeric>

namespace sum_of_multiples
{
    bool divisible(const std::vector<int> bases, const int nb)
    {
        for (auto &&base : bases)
        {
            if (0 == nb % base)
            {
                return true;
            }
        }
        return false;
    }

    int to(const std::vector<int> bases, const int limit)
    {
        std::vector<int> matching = {};
        for (int i = 0; i < limit; i++)
        {
            if (divisible(bases, i))
            {
                matching.push_back(i);
            }
        }
        return std::accumulate(matching.begin(), matching.end(), decltype(matching)::value_type(0));
    }
} // namespace sum_of_multiples
