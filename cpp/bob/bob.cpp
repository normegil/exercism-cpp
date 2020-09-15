#include "bob.h"

#include <map>
#include <regex>

namespace bob
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

    bool is_silence(std::string message)
    {
        for (auto &&c : message)
        {
            if (!std::isblank(c) && !std::iscntrl(c))
            {
                return false;
            }
        }
        return true;
    }
    bool is_question(std::string message)
    {
        auto tmp = trim(message);
        return '?' == tmp[tmp.length() - 1];
    }

    bool is_yelling(std::string message)
    {
        bool atLeastOneCaps{false};
        for (auto &&c : message)
        {
            if (std::isupper(c))
            {
                atLeastOneCaps = true;
            }
            else if (' ' != c && !std::ispunct(c) && !std::isdigit(c))
            {
                return false;
            }
        }
        return atLeastOneCaps;
    }

    std::string hey(std::string message)
    {
        if (is_silence(message))
        {
            return "Fine. Be that way!";
        }
        else if (is_yelling(message) && is_question(message))
        {
            return "Calm down, I know what I'm doing!";
        }
        else if (is_yelling(message))
        {
            return "Whoa, chill out!";
        }
        else if (is_question(message))
        {
            return "Sure.";
        }
        return "Whatever.";
    }
} // namespace bob
