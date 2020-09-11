#include "space_age.h"

namespace space_age
{
    const int EARTH_YEAR_IN_SECONDS = 31557600;

    double compute_age(const double year_duration, long age)
    {
        return static_cast<double>(age) / year_duration;
    }
    space_age::space_age(const long age)
    {
        this->age = age;
    }

    int space_age::seconds() const
    {
        return age;
    }

    double space_age::on_mercury() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 0.2408467, age);
    }

    double space_age::on_venus() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 0.61519726, age);
    }

    double space_age::on_earth() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS, age);
    }

    double space_age::on_mars() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 1.8808158, age);
    }

    double space_age::on_jupiter() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 11.862615, age);
    }

    double space_age::on_saturn() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 29.447498, age);
    }

    double space_age::on_uranus() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 84.016846, age);
    }

    double space_age::on_neptune() const
    {
        return compute_age(EARTH_YEAR_IN_SECONDS * 164.79132, age);
    }
} // namespace space_age
