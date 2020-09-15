#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <string>
#include <vector>

namespace anagram
{
    class anagram
    {
    private:
        std::string subject;

    public:
        anagram(std::string subject);
        std::vector<std::string> matches(std::vector<std::string> to_check);
    };
} // namespace anagram

#endif // ANAGRAM_H