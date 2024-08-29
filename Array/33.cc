/**
 * @name 33[M].搜索旋转排列数组
 * @details
 * @url https://leetcode.cn/problems/search-in-rotated-sorted-array/description/
 * @idea
 * 选择性二分查找，根据mid所在位置判断左右两边哪边是有序的，并判断target值和左右区间边界值的大小来更新二分查找的边界
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        if (n == 1) return nums[0] == target ? 0 : -1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]) // 左半边是有序的
            {
                // target就在有序的左半边 
                if (target < nums[mid] && target >= nums[0]) // NOTE: 所有和target和nums[mid]的比较都不带等号
                {
                    r = mid - 1; // 在有序区间内二分
                }
                else
                {
                    l = mid + 1; // 无法二分，在右区间顺序查找
                }
            }
            else // 右半边是有序的
            {
                if (target > nums[mid] && target <= nums[n - 1]) { l = mid + 1; }
                else { r = mid - 1; }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}