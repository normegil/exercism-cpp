#include "acronym.h"

#include <vector>
#include <sstream>
#include <cctype>

namespace acronym
{
    std::vector<std::string> split(const std::string &s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream token_stream(s);
        while (std::getline(token_stream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::string acronym(std::string to_transform)
    {
        auto words = split(to_transform, ' ');
        std::vector<std::string> splitted_words{};
        for (auto &&word : words)
        {
            auto splitted = split(word, '-');
            if (1 < splitted.size())
            {
                for (auto &&s : splitted)
                {
                    splitted_words.push_back(s);
                }
            }
            else
            {
                splitted_words.push_back(word);
            }
        }

        std::string acronym{};
        for (auto &&word : splitted_words)
        {

            acronym.push_back(toupper(word[0]));
        }
        return acronym;
    }
} // namespace acronym
