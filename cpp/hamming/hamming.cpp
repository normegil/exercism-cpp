#include "hamming.h"

#include <stdexcept>

namespace hamming
{
    int compute(std::string fst, std::string snd)
    {

        if (fst.length() != snd.length()) {
            throw std::domain_error("Length doesn't match");
        }

        int count = 0;
        for (decltype(fst.length()) i = 0; i < fst.length(); i++)
        {
            if (fst[i] != snd [i])
            {
                count+=1;
            }
        }
        return count;
    }
} // namespace hamming
