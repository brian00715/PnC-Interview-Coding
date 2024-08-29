/**
 * @name 1277. 统计全为 1 的正方形子矩阵
 * @details
 * @url https://leetcode.cn/problems/count-square-submatrices-with-all-ones/
 * @idea
 * dp[i][j]表示坐标i,j处的最大正方形数量，状态转移考虑左上角3个格子的正方形数量，取min（由于木桶效应）。
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = matrix[0][0];
        int max_num = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0) { dp[i][j] = matrix[i][j]; }
                else if (matrix[i][j] == 0) { dp[i][j] = 0; }
                else { dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; }
                max_num += dp[i][j];
            }
        }
        return max_num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}