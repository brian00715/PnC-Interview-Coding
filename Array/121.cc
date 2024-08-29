/**
 * @name 121.买卖股票的最佳时机
 * @details
 * @url https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
 * @idea 一次遍历，找最小的值，然后比较当前值和最小值的差，得到最大值
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int min_profit = prices[0];
        int max_diff = 0;
        for (int i = 0; i < n; i++)
        {
            min_profit = min(min_profit, prices[i]);
            max_diff = max(max_diff, prices[i] - min_profit);
        }
        return max_diff;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ar = {7, 1, 5, 3, 6, 4};
    int profit = s.maxProfit(ar);
    cout << profit;
}