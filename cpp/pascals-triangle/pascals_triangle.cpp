#include "pascals_triangle.h"

namespace pascals_triangle
{
    std::vector<std::vector<int>> generate_rows(int nb)
    {
        if (nb == 0)
        {
            return {};
        }

        std::vector<std::vector<int>> result = {{1}};
        for (int i = 1; i < nb; i++)
        {
            std::vector<int> row = {};
            row.push_back(result[i - 1][0]);
            for (int j = 1; j < i; j++)
            {
                row.push_back(result[i - 1][j-1] + result[i - 1][j]);
            }
            row.push_back(result[i - 1][result[i - 1].size() - 1]);
            result.push_back(row);
        }
        return result;
    }
} // namespace pascals_triangle
