/**
 * @name 50.pow(x,y)
 * @details
 * @url https://leetcode.cn/problems/powx-n/solutions/238559/powx-n-by-leetcode-solution/
 * @idea 递归求解平方，例如x^64 = x^(32)的平方，而不用计算64个x相乘
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        return N > 0 ? subPow(x, N) : 1.0 / subPow(x, N);
    }

    double subPow(double x, long long N)
    {
        if (N == 0)
        {
            return 1.0;
        }
        double y = subPow(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
}