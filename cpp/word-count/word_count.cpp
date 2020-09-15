#include "word_count.h"

#include <vector>
#include <sstream>
#include <iostream>

namespace word_count
{
    const std::vector<char> SEPARATORS = {' ', ',', '\n'};

    std::vector<std::string> split(const std::string &s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream stream{s};
        while (std::getline(stream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::vector<std::string> split(const std::string &s)
    {
        std::vector<std::string> splitted{s};
        for (auto &&sep : SEPARATORS)
        {
            std::vector<std::string> subsplitted{};
            for (auto &&word : splitted)
            {
                auto result = split(word, sep);
                for (auto &&r : result)
                {
                    subsplitted.push_back(r);
                }
                std::cout << word << " (" << sep << ") " << subsplitted.size() << std::endl;
            }
            splitted = subsplitted;
        }
        return splitted;
    }

    std::map<std::string, int> words(std::string text)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::map<std::string, int> count = {};

        auto words = split(text);

        std::cout << text << ": " << words.size() << " - " << words[0] << std::endl;

        for (auto &&word : words)
        {
            if ("" == word)
            {
                continue;
            }

            count[word] += 1;
        }

        for (auto &&p : count)
        {
            std::cout << p.first << ": " << p.second << std::endl;
        }

        return count;
    }
} // namespace word_count
