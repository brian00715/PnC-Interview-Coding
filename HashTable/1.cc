/**
 * @name 1. 两数之和
 * @details 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
 * @url https://leetcode.cn/problems/two-sum/description/
 * @idea 两层for或者哈希表
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hash.find(target - nums[i]);
            if (it != hash.end())
            {
                return {it->second, i};
            }

            hash.insert({nums[i], i});
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> input = {2, 7, 11, 15};
    vector<int> rst = s.twoSum(input, 9);
    for (auto x : rst)
    {
        cout << x << " ";
    }
}