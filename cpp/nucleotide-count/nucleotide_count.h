#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace nucleotide_count
{
    class counter
    {
    public:
        counter(std::string dna);
        int count(char c) const;
        std::map<char, int> nucleotide_counts() const noexcept;

    private:
        std::map<char, int> internal_counter{{'A', 0}, {'T', 0}, {'C', 0}, {'G', 0}};
    };
} // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H