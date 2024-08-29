/**
 * @name 97[M].交错字符串
 * @details
 * @url https://leetcode.cn/problems/interleaving-string/description/
 * @idea dp[i][j]表示 s1 的前 i 个和 s2 的前 j 个能否凑成 s3 的 i+j 个。dp 向后递推,考虑 s1 的前 i-1
 * 和 s2 的前 j 能否凑成 s3 的 i-1+j，注意要加字符的相等判断；s2 同理。 注意初始化方式
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n1; i++)
        {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j <= n2; j++)
        {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n1][n2];
    }
}

;

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}