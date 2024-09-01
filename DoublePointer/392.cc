/**
 * @name 392.判断子序列
 * @details
 * @url https://leetcode.cn/problems/is-subsequence/description/
 * @idea 贪心匹配+双指针，或者用二维dp向后递推dp[i][j]表示在目标串中从i向后字符j第一次出现的位置
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n1 = s.size(), n2 = t.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (s[i] == t[j]) { i++; }
            j++;
        }
        return i == n1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc");
    return 0;
}