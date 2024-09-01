/**
 * @name 159[M]. 至多包含两个不同字符的最长子串
 * @details
 * @url https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/
 * @idea
 * @note
 */
#include "../header.hpp"
class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        int n = s.size();
        if (n < 2) return 1;
        int left = 0, right = 0;
        int ans = 0;
        unordered_map<char, int> hashmap;
        while (right < n)
        {
            hashmap[s[right]] = right; // 字符可能重复，存最右边的下标
            if (hashmap.size() == 3)
            { // 删除最左边的元素
                int del_idx = INT_MAX;
                for (auto &x : hashmap)
                {
                    del_idx = min(del_idx, x.second);
                }
                hashmap.erase(s[del_idx]);
                left = del_idx + 1;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}