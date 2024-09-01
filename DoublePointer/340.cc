/**
 * @name 340[M]. 至多包含 K 个不同字符的最长子串
 * @details
 * @url https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/
 * @idea
 * 滑动窗口，哈希表存每个字符最右边的下标，一旦窗口内有k+1个不同的字符就删除最左边的，迭代更新最大值
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int n = s.size();
        if (n < k) return n;
        int left = 0, right = 0;
        unordered_map<char, int> hashmap;
        int max_len = 0;
        while (right < n)
        {
            hashmap[s[right]] = right;
            if (hashmap.size() == k + 1)
            {
                int del_idx = INT_MAX;
                for (auto &x : hashmap)
                {
                    del_idx = min(del_idx, x.second);
                }
                hashmap.erase(s[del_idx]);
                left = del_idx + 1;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}