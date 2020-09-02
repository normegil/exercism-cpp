#include "isogram.h"

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <locale>

namespace isogram
{
    bool is_isogram(const std::string toCheck) noexcept
    {
        std::list<char> found = {};
        for (const auto to_find : toCheck)
        {
            if (' ' == to_find || '-' == to_find)
            {
                continue;
            }

            const auto normalized = tolower(to_find, std::locale());
            if (std::find(found.begin(), found.end(), normalized) != found.end())
            {
                return false;
            }
            found.push_back(normalized);
        }
        return true;
    }
} // namespace isogram
