/**
 * @name 122.买卖股票的最佳时机2
 * @details
 * @url https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 * @idea n*2维的dp数组，dp[i]表示当天的最大利润，2维表示当天是否持有股票. 0表示没有股票，1表示有股票
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}