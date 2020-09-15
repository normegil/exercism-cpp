#include "matching_brackets.h"

#include <map>
#include <stack>
#include <stdexcept>

namespace matching_brackets
{
    const std::map<char, char> ALL_BRACKETS{
        {'[', ']'},
        {'{', '}'},
        {'(', ')'},
    };

    std::pair<const char, char> &searchByValue(std::map<char, char> to_search, char value)
    {
        for (auto &&e : to_search)
        {
            if (e.second == value)
            {
                return e;
            }
        }
        throw std::out_of_range("Could not find value");
    }

    bool check(std::string to_check)
    {
        std::stack<char> s{};

        for (auto &&c : to_check)
        {
            auto found = ALL_BRACKETS.find(c);

            if (ALL_BRACKETS.end() != found)
            {
                s.push(c);
            }

            try
            {
                auto found = searchByValue(ALL_BRACKETS, c);
                if (s.empty() || found.first != s.top())
                {
                    return false;
                }
                s.pop();
            }
            catch (const std::out_of_range &e)
            {
                continue;
            }
        }

        return s.empty();
    }

} // namespace matching_brackets
