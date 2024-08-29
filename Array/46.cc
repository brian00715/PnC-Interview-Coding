/**
 * @name 46[M].全排列
 * @details
 * @url https://leetcode.cn/problems/permutations/description/
 * @idea 递归回溯, 直接操作原数组，分成左右两半，遍历每一位数字，每次把当前数字交换到idx处，相当于固定开头，不重复地组合剩余的数字
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        backtrace(nums, res, 0, n);
        return res;
    }

    void backtrace(vector<int> &nums, vector<vector<int>> &res, int idx, int n)
    {
        if (idx == n)
        {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            std::swap(nums[i], nums[idx]);
            backtrace(nums, res, idx + 1, n);
            std::swap(nums[i], nums[idx]);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
