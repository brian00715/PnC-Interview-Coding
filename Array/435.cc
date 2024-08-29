/**
 * @name 435[M].无重叠区间
 * @details
 * @url https://leetcode.cn/problems/non-overlapping-intervals
 * @idea  本质和300.最长上升子序列一样，动态规划,等价于选择数量最多的互不重叠的区间,
 * dp[i]表示以第i个区间结束不重叠的最大区间数量
 * @note
 */
#include "../header.hpp"

// 这种方法会超时
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (!n) return 0;
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &u, vector<int> &v) { return u[0] < v[0]; });
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (intervals[j][1] <= intervals[i][0]) { dp[i] = max(dp[i], dp[j] + 1); }
            }
        }
        return n - *max_element(dp.begin(), dp.end());
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}