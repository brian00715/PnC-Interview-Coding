/**
 * @name 647.回文子串
 * @details 输出字符串中所有的回文串
 * @url https://leetcode.cn/problems/palindromic-substrings/description/
 * @idea dp[i][j]递推i到j之间的回文串
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int num = 0;
        for (int i = n - 1; i >= 0; i--) // 注意遍历顺序
        {
            for (int j = i; j < n; j++) // 注意起点
            {
                if (s[i] == s[j]) // 注意分情况判断
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        num++;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        num++;
                    }
                }
            }
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}