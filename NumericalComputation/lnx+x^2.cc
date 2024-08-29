#include <cmath>
#include <iostream>

using namespace std;

// 定义目标函数 f(x) = ln(x) + x^2
double f(double x)
{
    return log(x) + x * x;
}

// 定义导数函数 f'(x) = 1/x + 2x
double f_derivative(double x)
{
    return 1.0 / x + 2 * x;
}

// 牛顿法求解
double newton_method(double initial_guess, double tolerance)
{
    double x = initial_guess;
    double x_next;

    while (true)
    {
        x_next = x - f(x) / f_derivative(x);
        if (fabs(x_next - x) < tolerance) { break; }
        x = x_next;
    }

    return x_next;
}

int main()
{
    double initial_guess = 0.5; // 初始猜测
    double tolerance = 0.0001;  // 精度要求

    double solution = newton_method(initial_guess, tolerance);
    cout << "方程的近似解为: " << solution << endl;

    return 0;
}
