/**
 * @name 322.零钱兑换
 * @details
 * @url
 * https://leetcode.cn/problems/coin-change/solutions/132979/322-ling-qian-dui-huan-by-leetcode-solution/
 * @idea 动态规划，从0开始攒总金额，每一步能凑的钱都基于上一步，看这次用什么面值的硬币
 * 舍硬币面值为c_j，F(i)为凑成面值i所需的最小硬币数，则状态转移方程为
 * F(i) = min(F(i-c_j))+1, for all c_j in C^R
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int max_coin_num = amount + 1;
        vector<int> F(amount + 1, max_coin_num); // 多了一个0，因此要+1
        F[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++) // traverse coin combination
            {
                if (coins[j] <= i) // NOTE: don't forget this step! used to judge wether the current
                                   // coin's value can constitute the final amount
                {
                    F[i] = min(F[i], F[i - coins[j]] + 1); // choose use which value of coin to use
                }
            }
            return F[amount] > amount ? -1 : F[amount];
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> coins{1, 2, 5};
    int min_num = s.coinChange(coins, 11);
    printf("min num is:%d\r\n", min_num);
    return 0;
}