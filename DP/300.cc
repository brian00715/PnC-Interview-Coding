/**
 * @name 300. 最长递增子序列
 * @details 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * @url https://leetcode.cn/problems/longest-increasing-subsequence/
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] means longest sequence at idx i
        int max_len = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i]) { dp[i] = max(dp[i], dp[j] + 1); }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> seqs = {10, 9, 2, 5, 3, 7, 101, 18};
    int max_len = s.lengthOfLIS(seqs);
    cout << max_len << endl;
}