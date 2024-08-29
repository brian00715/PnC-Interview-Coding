/**
 * @name 153[M].寻找旋转排序数组中的最小值
 * @details
 * @url https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
 * @idea 二分查找，可以画图判断pivot和边界的递推关系
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) { right = mid; }
            else if (nums[mid] > nums[right]) { left = mid + 1; }
        }
        return nums[left];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}