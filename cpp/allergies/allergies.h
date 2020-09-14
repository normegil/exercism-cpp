#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <cstdint>
#include <string>
#include <unordered_set>

namespace allergies
{
    class allergy_test
    {
    private:
        uint_fast32_t score;

    public:
        allergy_test(uint_fast32_t score);

        bool is_allergic_to(std::string allergenic);

        std::unordered_set<std::string> get_allergies();
    };
} // namespace allergies

#endif // ALLERGIES_H