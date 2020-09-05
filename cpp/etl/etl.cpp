#include "etl.h"

#include<iostream>
#include<cctype>

namespace etl
{
    std::map<char, int> transform(std::map<int, std::vector<char>> old)
    {
        std::map<char, int> newFormat{};
        for (auto i = old.begin(); i != old.end(); ++i)
        {
            for (auto &&character : i->second)
            {
                auto toInsert = std::pair<char, int>{tolower(character), i->first};
                newFormat.insert(toInsert);
                std::cout << "Inserting: " << toInsert.first << ": " << toInsert.second << std::endl;
            }
        }
        return newFormat;
    }
} // namespace etl
