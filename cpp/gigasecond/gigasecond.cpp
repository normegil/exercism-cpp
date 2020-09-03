#include "gigasecond.h"

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond
{
    ptime advance(const ptime time)
    {
        long x = 1e+9l;
        return time + seconds{x};
    }
} // namespace gigasecond
