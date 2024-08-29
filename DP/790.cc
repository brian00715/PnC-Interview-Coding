/**
 * @name 790.多米诺平铺和拖米诺平铺
 * @details
 * @url https://leetcode.cn/problems/domino-and-tromino-tiling/description/
 * @idea
 * 二维动态规划，dp[i][s]表示铺到第i列的时候状态s的铺法数量，要根据s=0123四种情况分类讨论状态转移
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int numTilings(int n)
    {
        const long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
        dp[0][3] = 1; // 通过这种初始化可以强迫迭代第一列的时候只铺竖着的2格或者不铺

        for (int i = 1; i <= n; i++) // NOTE: must start from 1, end in n
        {
            dp[i][0] = (dp[i - 1][3]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][3] + dp[i - 1][2] + dp[i - 1][1] + dp[i - 1][0]) % mod;
        }
        return dp[n][3];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int num = s.numTilings(3);
    cout << num;
    return 0;
}