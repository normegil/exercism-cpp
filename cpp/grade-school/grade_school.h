#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <string>

namespace grade_school
{
    class school
    {
    private:
        std::map<int, std::vector<std::string>> rosterData = {};

    public:
        std::map<int, std::vector<std::string>> roster() const;
        std::vector<std::string> grade(int grade) const;
        void add(std::string name, int grade);
    };
} // namespace grade_school

#endif // GRADE_SCHOOL_H