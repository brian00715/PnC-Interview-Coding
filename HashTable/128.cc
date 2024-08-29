/**
 * @name 128. 最长连续子序列
 * @details 给定一个未排序的整数数组 nums
，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题
 * @url
https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked
 * @idea 哈希表
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // build a set
        unordered_set<int> hash;
        for (auto x : nums) { hash.insert(x); }

        int max_length = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr_num = nums[i];
            int length = 1;
            if (!hash.count(curr_num - 1))
            {
                while (hash.count(curr_num + 1))
                {
                    curr_num += 1;
                    length += 1;
                }
                if (length > max_length) { max_length = length; }
            }
        }
        return max_length;
    }
};

int main(int argc, char const *argv[]) { Solution s; }