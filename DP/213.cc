/**
 * @name 213[M].打家劫舍 II
 * @details
 * @url https://leetcode.cn/problems/house-robber-ii/
 * @idea 思路沿用
 * 198，由于首尾相连，不能同时偷第一家和最后一家，因此对下标范围进行两种特殊讨论即可，然后取最大的。
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;
        else if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);

        int ans = max(get_max(nums, 0, n - 2), get_max(nums, 1, n - 1));
        return ans;
    }

    int get_max(vector<int> &nums, int st, int ed)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[st] = nums[st];
        dp[st + 1] = max(nums[st], nums[st + 1]);

        for (int i = st + 2; i <= ed; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[ed];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}