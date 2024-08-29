/**
 * @name 343.整数拆分
 * @details
 * @url https://leetcode.cn/problems/integer-break/
 * @idea DP，dp[i]表示把数字i拆解后的最大成乘积，状态转移在不拆、只拆一次和递归拆分中最大的
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            // 拆分成j和i-j, 看j是否继续拆分
            for (int j = 1; j < i; j++) { dp[i] = max(dp[i], max(j * (i - j), (i - j) * dp[j])); }
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.integerBreak(10);
    return 0;
}