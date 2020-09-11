#include "triangle.h"

#include <stdexcept>

namespace triangle
{
    bool inequal(double a, double b, double c)
    {
        return a > b + c || b > a + c || c > a + b;
    }

    flavor kind(double a, double b, double c)
    {
        if (a < 0 || b < 0 || c < 0)
        {
            throw std::domain_error("Negative side");
        }

        if (inequal(a, b, c))
        {
            throw std::domain_error("Inequal");
        }

        if ((a == b) && (b == c))
        {
            if (a == 0)
            {
                throw std::domain_error("Null triangle");
            }
            return flavor::equilateral;
        }
        else if (a == b || a == c || b == c)
        {
            return flavor::isosceles;
        }
        return flavor::scalene;
    }
} // namespace triangle
