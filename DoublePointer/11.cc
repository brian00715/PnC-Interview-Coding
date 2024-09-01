/**
 * @name 11[M]. 盛最多水的容器
 * @details
 * @url https://leetcode.cn/problems/container-with-most-water/description/
 * @idea 双指针，每次移动高度更小的柱子
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int max_area = 0;
        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);
            if (height[left] <= height[right]) { left++; }
            else { right--; }
        }
        return max_area;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}