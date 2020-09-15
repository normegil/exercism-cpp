#include "pangram.h"

#include <set>
#include <cctype>

namespace pangram
{
    const std::set<char> ALPHABET{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    bool is_pangram(std::string to_test)
    {
        std::set<char> letters{};
        for (auto &&c : to_test)
        {
            if (std::isalpha(c))
            {
                letters.insert(std::tolower(c));
            }
        }

        return ALPHABET == letters;
    }
} // namespace pangram
