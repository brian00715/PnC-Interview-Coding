/**
 * @name 583.两个字符串的删除操作
 * @details
 * @url https://leetcode.cn/problems/delete-operation-for-two-strings/description/
 * @idea 1143的变种。可以先找最长公共子序列，然后比较两个串的删除次数谁更少。
 * 或者可以直接dp，dp[i][j]表示到串1的i和串2的j为止，删除所需的最小次数，递推时判断字符是否相等，如果相等直接递归到子串；
 * 否则看删除哪一个串的字符，然后从中找次数最少的
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0)); // NOTE: 注意初始化的大小

        // 要让空串和非空串相等，只能完全删除另一个
        for (int j = 1; j <= n2; j++) { dp[0][j] = j; }
        for (int i = 1; i <= n1; i++) { dp[i][0] = i; }

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i - 1] == word2[j - 1]) // 字符串需要从0开始遍历
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else { dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1; }
            }
        }
        return dp[n1][n2];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}