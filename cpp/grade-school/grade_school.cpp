#include "grade_school.h"

#include <algorithm>

using namespace std;

namespace grade_school
{
    map<int, vector<string>> school::roster() const
    {
        return rosterData;
    }

    void school::add(string name, int grade)
    {
        auto names = rosterData[grade];
        names.push_back(name);
        sort(names.begin(), names.end());
        rosterData[grade] = names;
    }

    vector<string> school::grade(int grade) const
    {
        auto namesIt = rosterData.find(grade);
        if (rosterData.end() == namesIt)
        {
            return {};
        }
        auto names = namesIt->second;
        sort(names.begin(), names.end());
        return names;
    }
} // namespace grade_school
