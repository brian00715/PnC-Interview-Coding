/**
 * @name 162.寻找峰值
 * @details
 * @url https://leetcode.cn/problems/find-peak-element/description/
 * @idea 根据单调性二分查找迭代搜索区间
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1; // 峰值在右边
            }
            else
            {
                right = mid; // 峰值在左边或者mid就是峰值
            }
        }
        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ar = {1, 2, 3, 1};
    int idx = s.findPeakElement(ar);
    cout << idx;
    return 0;
}