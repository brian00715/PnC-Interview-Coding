/**
 * @name 63.不同路径2。考虑障碍物的存在
 * @details
 * @url
 * https://leetcode.cn/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=dynamic-programming
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        if (n == 0) return 0;
        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            dp[0][0] = 1;

        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0 && dp[i - 1][0] != 0)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0 && dp[0][j - 1] != 0)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1) { continue; }
                else { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution2
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector<int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) // NOTE: start idx
                {
                    f[j] += f[j - 1]; // NOTE:!!
                }
            }
        }

        return f.back();
    }
};

int main(int argc, char const *argv[]) { Solution s; }