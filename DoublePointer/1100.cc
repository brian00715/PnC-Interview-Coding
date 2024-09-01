/**
 * @name 1100[M]. 长度为 K 的无重复字符子串
 * @details
 * @url
 * https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/description/
 * @idea  双指针滑动窗口，用map统计出现频次，动态移动左右指针
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int numKLenSubstrNoRepeats(string s, int k)
    {
        if (k > 26) { return 0; }
        int n = s.size();
        unordered_map<char, int> cnt;
        int left = 0, right = 0;
        int ans = 0;
        while (right <= n - 1)
        {
            cnt[s[right]]++;

            while (cnt[s[right]] > 1)
            {
                cnt[s[left]]--;
                left++;
            }

            if (right - left == k - 1)
            {
                ans++;
                cnt[s[left]]--;
                left++;
            }
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