#include "anagram.h"

#include <algorithm>
#include <cctype>

namespace anagram
{
    bool is_anagram(std::string base, std::string to_check)
    {
        std::string base_lower;
        for (auto &&b : base)
        {
            base_lower.push_back(tolower(b));
        }

        std::string to_check_lower;
        for (auto &&c : to_check)
        {
            to_check_lower.push_back(tolower(c));
        }

        if (base_lower == to_check_lower)
        {
            return false;
        }

        std::sort(base_lower.begin(), base_lower.end());
        std::sort(to_check_lower.begin(), to_check_lower.end());

        return base_lower == to_check_lower;
    }

    anagram::anagram(std::string subject) : subject(subject) {}
    std::vector<std::string> anagram::matches(std::vector<std::string> to_check)
    {
        std::vector<std::string> to_return{};
        for (auto &&check : to_check)
        {
            if (is_anagram(subject, check))
            {
                to_return.push_back(check);
            }
        }
        return to_return;
    }
} // namespace anagram
