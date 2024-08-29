/**
 * @name 120. 三角形最短路径和
 * @details
 * @url https://leetcode.cn/problems/triangle/description/
 * @idea DP，注意斜边的初始化和状态转移规则
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp;
        vector<int> first_row;
        first_row.emplace_back(triangle[0][0]);
        dp.emplace_back(first_row);
        for (int i = 1; i < m; i++)
        {
            int n = triangle[i].size();
            vector<int> dp_row(n);
            dp_row[0] = dp[i - 1][0] + triangle[i][0];
            dp_row[n - 1] = dp[i - 1][n - 2] + triangle[i][n - 1];
            dp.emplace_back(dp_row);
        }

        for (int i = 2; i < m; i++)
        {
            for (int j = 1; j < dp[i].size() - 1; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        PrintMatrix(dp);

        int min_cost = dp[m - 1][0];
        for (int j = 1; j < triangle[m - 1].size(); j++) { min_cost = min(min_cost, dp[m - 1][j]); }

        return min_cost;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> tri = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };
    Solution s;
    int min_cost = s.minimumTotal(tri);
    cout << min_cost << endl;
}