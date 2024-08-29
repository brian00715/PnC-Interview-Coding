/**
 * @name 115[H].不同的子序列
 * @details
 * @url https://leetcode.cn/problems/distinct-subsequences/description/
 * @idea dp[i][j] 表示在 s[i:] 的子序列中 t[j:] 出现的个数，倒序递推. s[i] ==
 * t[j]时有两种选择，加上这两个字符构成匹配还是只考虑s[i+1]的匹配，两种选择相加
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();
        if (s_size < t_size) return 0;
        vector<vector<unsigned long long>> dp(s_size + 1,
                                              vector<unsigned long long>(t_size + 1, 0));
        // when len(t)=t_size, empty str must be sub-seq
        for (int i = 0; i <= s_size; i++) // NOTE: <=
        {
            dp[i][t_size] = 1;
        }

        for (int i = s_size - 1; i >= 0; i--)
        {
            for (int j = t_size - 1; j >= 0; j--)
            {
                if (s[i] == t[j]) { dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]; }
                else { dp[i][j] = dp[i + 1][j]; }
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}