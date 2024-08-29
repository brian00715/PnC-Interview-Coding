/**
 * @name 718. 最长重复子数组
 * @details
 * @url https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 * @idea 二维动态规划.dp[i][j] 表示 A[i:] 和 B[j:] 的最长公共前缀，答案为所有 dp[i][j]
 * 中的最大值. 如果 A[i] == B[j], dp[i][j] = dp[i -1][j - 1] + 1,否则为 0. i/j为0时单独处理
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        int max_len = 0;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    if (i == 0 || j == 0) { dp[i][j] = 1; }
                    else { dp[i][j] = dp[i - 1][j - 1] + 1; }
                }
                else { dp[i][j] = 0; }
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}