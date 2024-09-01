/**
 * @name 15.三数之和
 * @details
 * @url https://leetcode.cn/problems/3sum/description/
 * @idea 核心思路是仍然是三重循环，但只枚举有序的三元组，并使用双指针避免重复枚举
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> rst;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // 跳过重复元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    rst.push_back({nums[i], nums[left], nums[right]});

                    // 跳过重复元素
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) { left++; }
                else { right--; }
            }
        }

        return rst;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}