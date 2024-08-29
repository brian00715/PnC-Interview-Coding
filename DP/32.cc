/**
 * @name 32. 最长有效括号
 * @details
 * @url https://leetcode.cn/problems/longest-valid-parentheses/description/
 * @idea 动态规划,dp[i] 表示以下标 i 字符结尾的最长有效括号的长度;
 * 或者用栈其实最简单，每次匹配到括号后算一次长度即可
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size(), 0); // stores the max parenthes length at [i]

        int max_len = 0;
        for (int i = 1; i < s.size(); i++)
        {
            // case 1: ()
            if (s[i] == ')' && s[i - 1] == '(')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } // NOTE: index is i-2

            // case 2: ((...))
            if (s[i] == ')' && s[i - 1] == ')')
            {
                if (i > dp[i - 1] && s[i - 1 - dp[i - 1]] == '(')
                {
                    dp[i] = dp[i - 1] + 2 + (i >= 2 + dp[i - 1] ? dp[i - 1 - dp[i - 1] - 1] : 0);
                }
            }
            max_len = max(max_len, dp[i]);
        }

        return max_len;
    }

    /**
     * @brief use stack
     *
     * @param s
     * @return int
     */
    int longestValidParentheses2(string s)
    {
        stack<int> st; // store index of (
        st.push(-1);   // NOTE: important to preserve feasibility
        int size = s.size();
        if (size == 0) return 0;
        int max_len = 0;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(') { st.push(i); }
            else
            {
                st.pop(); // pop here since we want to know the index of last paired parenthes
                if (st.empty())
                    st.push(i);
                else { max_len = max(max_len, i - st.top()); }
            }
        }
        return max_len;
    }
};

int main(int argc, char const *argv[]) { Solution s; }