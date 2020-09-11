#include "scrabble_score.h"

#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

namespace scrabble_score
{
    const std::map<int, std::vector<char>> points = {
        {1, {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'}},
        {2, {'D', 'G'}},
        {3, {'B', 'C', 'M', 'P'}},
        {4, {'F', 'H', 'V', 'W', 'Y'}},
        {5, {'K'}},
        {8, {'J', 'X'}},
        {10, {'Q', 'Z'}}};

    int pointsFor(char c)
    {
        for (auto &&entry : points)
        {
            auto charList = entry.second;
            auto found = std::find(charList.begin(), charList.end(), toupper(c));
            if (found != charList.end())
            {
                return entry.first;
            }
        }
        return 0;
    }

    int score(std::string word)
    {
        std::vector<int> scores = {};
        std::transform(word.begin(), word.end(), std::back_inserter(scores), pointsFor);
        return std::accumulate(scores.begin(), scores.end(), decltype(scores)::value_type(0));
    }
} // namespace scrabble_score
