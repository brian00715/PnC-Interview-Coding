/**
 * @name 53.最大子数组和
 * @details
 * @url https://leetcode.cn/problems/maximum-subarray/description/
 * @idea dp[i]顺着叠加就行
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_sum = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i],
                        dp[i - 1] + nums[i]); // NOTE: since we demand the sequence be consecutive,
                                              // the new sub-sequence may start from new nums[i]
            max_sum = max(max_sum,
                          dp[i]); // again, the Continuity results in max value may exist in mid pos
        }
        return max_sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ar = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = s.maxSubArray(ar);
    cout << ans << endl;
}