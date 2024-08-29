/**
 * @name 516.最长回文子串
 * @details
 * @url https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 * @idea dp(i,j) 表示字符串 s 的第 i 到 j 个字母组成的串是否为回文串,
 * 初始化单个字符是回文，枚举字符串长度，判断 i...j 之间是否是回文。如果 i,j
 * 的字符相同就给子串的dp+2，否则通过内截的子串是否是回文来判断
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) { dp[i][i] = 1; }

        for (int i = n - 1; i >= 0; i--) // NOTE：外层循环要从右边开始
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j]) { dp[i][j] = dp[i + 1][j - 1] + 2; }
                else { dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); }
            }
        }

        return dp[0][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}