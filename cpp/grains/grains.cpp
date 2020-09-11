#include "grains.h"

#include <cmath>

namespace grains
{
    long square(int n)
    {
        return static_cast<long>(std::pow(2, n-1));
    }

    long total()
    {
        long sum {0};
        for (int i = 1; i < 65; i++)
        {
            sum += square(i);
        }
        return sum;
    }
} // namespace grains
