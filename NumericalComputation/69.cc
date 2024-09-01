/**
 * https://leetcode.cn/problems/sqrtx/
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 */
#include "../header.hpp"
class Solution
{
public:
    /**
     * @brief gradient based method
     *
     * @param x
     * @return int
     */
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        double c = x, xi = 1;
        double lr = 0.001;
        for (;;)
        {
            // obj func: f(x) = （x^2-c)^2
            // diff f(x) = 4x(x^2-c)
            double gradient = 4 * xi * (xi * xi - c);
            double xi_1 = xi - lr * gradient;
            double diff = fabs(xi * xi - c);
            cout << "xi+1: " << xi_1 << ", diff: " << diff << endl;
            if (diff < 1e-6)
            {
                break;
            }
            xi = xi_1;
        }
        return int(xi + 1e-3);
    }

    /**
     * @brief newton method
     *
     * @param x
     * @return int
     */
    int mySqrtNewton(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        double c = x, xi = x;
        for (;;)
        {
            // f(x) = （x^2-c)
            // diff f(x) = 2x
            double xi_1 = 0.5 * (xi + c / xi);
            double diff = xi * xi - c;
            cout << "xi+1: " << xi_1 << ", diff: " << diff << endl;
            if (diff < 1e-6)
            {
                break;
            }
            xi = xi_1;
        }
        return int(xi);
    }

    /**
     * @note Numerical overflow will hapen when inputting a large number
     */
    int mySqrtBinarySearch(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        double left_interval = 0, right_interval = x;
        double xi = x;
        double diff = x;
        while (fabs(diff) > 1e-6)
        {
            if (diff > 0)
            {
                right_interval = xi;
            }
            else
            {
                left_interval = xi;
            }
            xi = (left_interval + right_interval) / 2;
            diff = xi * xi - x;
            printf("diff: %6.3f, [%6.3f,%6.3f], xi: %6.3f\r\n", diff, left_interval, right_interval, xi);
        }
        return int(xi + 1e-3);
    }

    /**
     * there are many boundary problems to be solved in Int-based binary search
     */
    int mySqrtBinarySearchInt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        int left = 0, right = x;
        int ans = -1;
        while (left <= right) // Must <=
        {
            int xi = left + (right - left) / 2;
            long long diff = (long long)xi * xi - x;
            if (diff > 0) // Must >0
            {
                right = xi - 1;
            }
            else
            {
                ans = xi; // assignment must occer at <=0
                left = xi + 1;
            }
            printf("xi: %d [%d,%d]\r\n", xi, left, right);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int input;
    cout << "input: ";
    cin >> input;
    cout << "value: " << input << endl;
    int result = sol.mySqrtBinarySearchInt(input);
    cout << "result: " << result << endl;
    return 0;
}
