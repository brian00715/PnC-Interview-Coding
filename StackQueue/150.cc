/**
 * @name 150[M]. 逆波兰表达式
 * @details
 * @url
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/?envType=study-plan-v2&envId=top-interview-150
 * @idea  用栈存数字，遇到数字就压入，遇到操作符就连续弹两个数字，算完再压回去，直到遍历完成
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            auto token = tokens[i];
            if (isNum(token)) { st.push(atoi(token.c_str())); }
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (token[0])
                {
                case '+':
                    st.push(num1 + num2);
                    break;
                case '-':
                    st.push(num1 - num2);
                    break;
                case '*':
                    st.push(num1 * num2);
                    break;
                case '/':
                    st.push(num1 / num2);
                    break;
                }
            }
        }
        return st.top();
    }

    bool isNum(string token)
    {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}