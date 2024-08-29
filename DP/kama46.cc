/**
 * @name 46.携带研究材料
 * @details 小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。
 * 他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，
 * 它们各自占据不同的空间，并且具有不同的价值。
小明的行李空间为
N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。
 * @url https://kamacoder.com/problempage.php?pid=1046
 * @idea
 * @note
 */

#include "../header.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cap, obj_num;
    vector<int> space;
    vector<int> value;
    cin >> obj_num;
    cin >> cap;
    for (int i = 0; i < obj_num; i++)
    {
        int tmp;
        cin >> tmp;
        space.push_back(tmp);
    }
    for (int i = 0; i < obj_num; i++)
    {
        int tmp;
        cin >> tmp;
        value.push_back(tmp);
    }
    // PrintVector(space);
    // PrintVector(value);

    vector<vector<int>> dp(obj_num, vector<int>(cap + 1, 0));

    for (int j = space[0]; j <= cap; j++)
    {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < obj_num; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (j < space[i]) { dp[i][j] = dp[i - 1][j]; } // 装不下当前物体，直接继承
            else { dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - space[i]] + value[i]); }
        }
    }
    cout << dp[obj_num - 1][cap];
}