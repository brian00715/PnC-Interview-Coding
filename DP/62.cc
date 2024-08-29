/**
 * @name 62.不同路径
 * @details
 * @url https://leetcode.cn/problems/unique-paths/description/?envType=study-plan-v2&envId=dynamic-programming
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // dp[i][j] = dp[i-1][j] + dp[i][j-1]
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
}