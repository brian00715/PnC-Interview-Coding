/**
 * @name 57[M].插入区间
 * @details
 * @url https://leetcode.cn/problems/insert-interval/
 * @idea 不断取区间和给定区间的并集，直到新区间和原区间断开（也就是right < li）的时候将新区间插入
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int left = newInterval[0], right = newInterval[1];
        vector<vector<int>> ans;
        bool added = false;
        for (auto &interval : intervals)
        {
            if (interval[0] > right)
            {
                if (!added)
                {
                    ans.push_back({left, right});
                    added = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) { ans.push_back(interval); }
            else
            {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!added) { ans.push_back({left, right}); }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}