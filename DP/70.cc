/**
 * @name 70.爬楼梯
 * @details
 * @url
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int climbStairs(int n)
    {
        int llast = 1;
        int last = 1;
        int curr;
        for (int i = 1; i <= n - 1; i++) // n-1 because the first two numbers are initialized
        {
            curr = last + llast;
            llast = last;
            last = curr;
        }
        return curr;
    }
    int climbStairsAr(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) { dp[i] = dp[i - 1] + dp[i - 2]; }
        return dp[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int rst = s.climbStairs(3);
    printf("%d", rst);
}