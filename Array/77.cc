/**
 * @name 77[M]. 组合
 * @details
 * @url https://leetcode.cn/problems/combinations
 * @idea 递归回溯
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> curr;
        backtrace(n, k, res, curr, 1);
        return res;
    }

    void backtrace(int n, int k, vector<vector<int>> &res, vector<int> &curr, int start)
    {
        if (curr.size() == k)
        {
            res.push_back(curr);
            return;
        }

        // n - i + 1 >= k -curr.size是剪枝操作，当剩余的数组不足以完整枚举的时候就提前停止遍历
        for (int i = start; n - i + 1 >= k - curr.size(); i++)
        {
            curr.push_back(i);
            backtrace(n, k, res, curr, i + 1);
            curr.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}