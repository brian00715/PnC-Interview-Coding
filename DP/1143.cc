/**
 * @name 1143.最长公共子序列
 * @details
 * @url https://leetcode.cn/problems/longest-common-subsequence/description/
 * @idea 二维动态规划，dp[i][j] 表示 text 1[0:i] 和 text2[0:j] 的最长公共子序列的长度。
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        // NOTE: idx of string starts from 0 while idx of dp starts from 1
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (text1[i - 1] == text2[j - 1]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
                else { dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); }
            }
        }
        return dp[n1][n2];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string s1 = "abcde", s2 = "ace";
    int max_len = s.longestCommonSubsequence(s1, s2);
    cout << max_len;
}