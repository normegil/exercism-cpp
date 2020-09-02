#include "leap.h"

namespace leap
{
    bool is_leap_year(const int year) noexcept
    {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
} // namespace leap
