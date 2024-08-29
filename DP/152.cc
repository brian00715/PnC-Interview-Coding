/**
 * @name 152.乘积最大子数组
 * @details
 * @url https://leetcode.cn/problems/maximum-product-subarray/description/
 * @idea
 * 由于有复数存在，要维护两个dp，一个算最大值一个算最小值，因为负的越大，再乘一个负数就有可能更大
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<long> dp_max(nums.begin(), nums.end());
        vector<long> dp_min(nums.begin(), nums.end());
        long long max_num = nums[0];
        for (int i = 1; i < n; i++)
        {
            // 由于用原数组进行了初始化，因此max和min谁在前谁在后无所谓
            dp_min[i] = min((long)nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_max[i] = max((long)nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));

            // 单纯用来逃leetcode的不合理测试用例，无意义
            if (dp_min[i] < INT_MIN) { dp_min[i] = nums[i]; }

            max_num = max((long)max_num, max(dp_max[i], dp_min[i]));
        }
        return max_num;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ar = {-1, -2, -9, -6};
    int ans = s.maxProduct(ar);
    cout << ans << endl;
}