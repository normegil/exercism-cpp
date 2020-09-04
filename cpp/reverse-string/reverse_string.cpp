#include "reverse_string.h"

#include <string>
#include <algorithm>

namespace reverse_string
{
    std::string reverse_string(const std::string to_reverse) noexcept
    {
        std::string copy {to_reverse};
        std::reverse(copy.begin(), copy.end());
        return copy;
    }
} // namespace reverse_string
