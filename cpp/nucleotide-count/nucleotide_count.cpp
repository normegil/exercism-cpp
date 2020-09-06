#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count
{
    counter::counter(std::string dna)
    {
        for (auto &&chr : dna)
        {
            auto found = this->internal_counter.find(chr);
            if (found != this->internal_counter.end())
            {
                found->second += 1;
            }
            else
            {
                throw std::invalid_argument("Invalid: " + chr);
            }
        }
    }
    std::map<char, int> counter::nucleotide_counts() const noexcept
    {
        return this->internal_counter;
    }
    int counter::count(char c) const
    {
        auto found = this->internal_counter.find(c);
        if (found == this->internal_counter.end())
        {
            throw std::invalid_argument("Invalid: " + c);
        }
        return found->second;
    }
} // namespace nucleotide_count
