#include "atbash_cipher.h"

#include <cctype>

namespace atbash_cipher
{
    const std::string ALPHABET{"abcdefghijklmnopqrstuvwxyz"};
    const std::string NUMBERS{"0123456789"};

    std::string encode(std::string to_encode)
    {
        std::string encoded{};
        int pushed_char{};
        for (auto &&c : to_encode)
        {
            auto nbPos = NUMBERS.find_first_of(tolower(c));
            auto pos = ALPHABET.find_first_of(tolower(c));

            if ((std::string::npos != nbPos || std::string::npos != pos) && pushed_char != 0 && pushed_char % 5 == 0)
            {
                encoded.push_back(' ');
                pushed_char = 0;
            }

            if (nbPos != std::string::npos)
            {
                encoded.push_back(c);
                pushed_char += 1;
                continue;
            }
            
            if (pos == std::string::npos)
            {
                continue;
            }
            encoded.push_back(ALPHABET[ALPHABET.size() - 1 - pos]);
            pushed_char += 1;
        }
        return encoded;
    }

    std::string decode(std::string to_decode)
    {
        std::string decoded{};
        for (auto &&c : to_decode)
        {
            if (c == ' ')
            {
                continue;
            }
            auto nbPos = NUMBERS.find_first_of(tolower(c));
            if (nbPos != std::string::npos)
            {
                decoded.push_back(c);
                continue;
            }
            auto pos = ALPHABET.find_first_of(tolower(c));
            decoded.push_back(ALPHABET[ALPHABET.size() - 1 - pos]);
        }
        return decoded;
    }
} // namespace atbash_cipher
