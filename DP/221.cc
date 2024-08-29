/**
 * @name 221.最大正方形
 * @details
 * @url https://leetcode.cn/problems/maximal-square/
 * @idea 跟1277一样，状态转移方程完全一致，改一下统计方式，注意输入的是char不是int
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector(n, 0));
        int max_size = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0) { dp[i][j] = matrix[i][j] - '0'; }
                else if (matrix[i][j] == '0') { dp[i][j] == 0; }
                else { dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; }
                max_size = max(max_size, dp[i][j]);
            }
        }
        return max_size * max_size;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}