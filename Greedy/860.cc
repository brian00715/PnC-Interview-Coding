/**
 * @name 860.柠檬水找零
 * @details
 * @url https://leetcode.cn/problems/lemonade-change/description/
 * @idea 贪心+分类讨论
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0; // number of cash we have
        for (auto bill : bills)
        {
            if (bill == 5) // don't need to change
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five == 0)
                {
                    return false;
                }
                five--;
                ten++;
            }
            else // 20
            {
                // there's two kinds of combination to change: 10+5 or 5x3
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> input{
        5, 5, 5, 10, 20};
    bool rst = s.lemonadeChange(input);
    cout << (rst ? "true" : "false") << endl;
}