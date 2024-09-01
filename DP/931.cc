/**
 * @name  931[M]. 下降路径最小和
 * @details
 * @url
 * https://leetcode.cn/problems/minimum-falling-path-sum/description/?envType=study-plan-v2&envId=dynamic-programming
 * @idea 注意第一行的初始化以及递推过程中列标的范围
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp = dp[i - 1][j];
                if (j > 0) { tmp = min(dp[i - 1][j - 1], tmp); }
                if (j < n - 1) { tmp = min(dp[i - 1][j + 1], tmp); }
                dp[i][j] = tmp + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            ans = min(ans, dp[m - 1][j]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}