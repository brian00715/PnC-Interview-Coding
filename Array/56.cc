/**
 * @name 56. 合并区间
 * @details
 * @url https://leetcode.cn/problems/merge-intervals/
 * @idea 按照左端点排序，然后遍历
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0) return {};
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if (merged.size() == 0 || l > merged.back()[1]) { merged.push_back({l, r}); }
            else
            {
                merged.back()[1] = max(merged.back()[1], r); // NOTE: remember to use max()
            }
        }
        return merged;
    }
};

int main(int argc, char const *argv[]) { Solution s; }