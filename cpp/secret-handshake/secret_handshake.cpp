#include "secret_handshake.h"

#include <map>
#include <algorithm>

namespace secret_handshake
{
    const std::map<uint_fast8_t, std::string> CODE{
        {{0b0000'0001}, "wink"},
        {{0b0000'0010}, "double blink"},
        {{0b0000'0100}, "close your eyes"},
        {{0b0000'1000}, "jump"}};

    std::vector<std::string> commands(uint_fast8_t nb)
    {
        std::vector<std::string> command{};

        for (auto &&e : CODE)
        {
            if (e.first & nb)
            {
                command.push_back(e.second);
            }
        }

        if (nb & 0b0001'0000)
        {
            std::reverse(command.begin(), command.end());
        }

        return command;
    }
} // namespace secret_handshake
