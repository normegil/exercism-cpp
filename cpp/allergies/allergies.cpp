#include "allergies.h"

#include <map>

namespace allergies
{
    const std::map<std::string, uint_fast32_t> ALLERGENICS = {
        {"eggs", 0b0000'0000'0000'0000'0000'0000'0000'0001},
        {"peanuts", 0b0000'0000'0000'0000'0000'0000'0000'0010},
        {"shellfish", 0b0000'0000'0000'0000'0000'0000'0000'0100},
        {"strawberries", 0b0000'0000'0000'0000'0000'0000'0000'1000},
        {"tomatoes", 0b0000'0000'0000'0000'0000'0000'0001'0000},
        {"chocolate", 0b0000'0000'0000'0000'0000'0000'0010'0000},
        {"pollen", 0b0000'0000'0000'0000'0000'0000'0100'0000},
        {"cats", 0b0000'0000'0000'0000'0000'0000'1000'0000}};
    constexpr std::uint_fast32_t eggs{};
    constexpr std::uint_fast32_t peanuts{0b0000'0000'0000'0000'0000'0000'0000'0010};

    allergy_test::allergy_test(uint_fast32_t score) : score(score) {}

    bool allergy_test::is_allergic_to(std::string allergenic)
    {
        auto entry = ALLERGENICS.at(allergenic);
        return entry & score;
    }

    std::unordered_set<std::string> allergy_test::get_allergies()
    {
        std::unordered_set<std::string> allergies{};
        for (auto &&entry : ALLERGENICS)
        {
            if (entry.second & score)
            {
                allergies.insert(entry.first);
            }
        }

        return allergies;
    }
} // namespace allergies
