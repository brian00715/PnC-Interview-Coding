/**
 * @name 42[H].接雨水
 * @details
 * @url https://leetcode.cn/problems/trapping-rain-water/description/
 * @idea 维护两个一维dp，分别表示左边最高柱子和右边最高柱子，最后取min算差值
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        right[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = max(height[i], left[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i], right[i + 1]);
        }
        // PrintVector(left);
        // PrintVector(right);

        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            int diff_h = min(left[i], right[i]) - height[i];
            if (diff_h > 0) sum += diff_h;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height);
    return 0;
}