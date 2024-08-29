/**
 * @name 3[M].无重复字符的最长子串
 * @details
 * @url https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * @idea 双指针滑动窗口，迭代最大值
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 1) return 1;
        unordered_map<char, int> hashmap;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < n)
        {
            hashmap[s[right]]++;
            while (hashmap[s[right]] > 1)
            {
                hashmap[s[left]]--;
                left++;
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