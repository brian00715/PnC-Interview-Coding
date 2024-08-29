/**
 * @name 20.有效的括号
 * @details

    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

    有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    每个右括号都有一个对应的相同类型的左括号。
    输入：s = "()[]{}"
    输出：true

 * @url https://leetcode.cn/problems/valid-parentheses/description/
 * @idea 用栈和字典实现括号匹配
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> bracket;
        for (char ch : s)
        {
            if (bracket.empty() && ch == '}' ||
                bracket.empty() && ch == ')' ||
                bracket.empty() && ch == ']') // does not have the matched left bracket
            {
                return false;
            }

            if (ch == '(' || ch == '{' || ch == '[')
            {
                bracket.push(ch);
            }
            else
            {
                if ((ch == ')' && bracket.top() == '(') ||
                    (ch == '}' && bracket.top() == '{') ||
                    (ch == ']' && bracket.top() == '[')) // match
                {
                    bracket.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (bracket.empty())
            return true;
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string input{"()[]{}"};
    bool rst = s.isValid(input);
    printf("the input is %s\r\n", rst ? "true" : "false");
}