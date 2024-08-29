/**
 * 最小二乘法的实现
*/
#include "../header.hpp"
struct Param
{
    double k;
    double b;
};
// cost = sum((yi - k * xi - b)^2)
// \partial{cost}/\partial{b} = 0
// \partial{cost}/\partial{k} = 0
// \partial{ cost } / \partial{ b } = \sum{ 2 * (yi - k * xi - b) } = 0
// ==> b = mean(y) - k * mean(x)
// \partial{ cost } / \partial{ k } = \sum{ 2 * (yi - k * xi - b) * (-xi) } = 0

Param get_line(vector<vector<int>> points)
{
    double y_sum = 0, x_sum = 0;
    int num_points = points.size();
    for (int i = 0; i < num_points; ++i)
    {
        y_sum += points[i][1];
        x_sum += points[i][0];
    }
    double y_mean = y_sum / num_points, x_mean = x_sum / num_points;
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < num_points; ++i)
    {
        sum1 += (points[i][1] - y_mean) * points[i][0];
        sum2 += (points[i][0] - x_mean) * points[i][0];
    }
    Param res;
    res.k = sum1 / (sum2 + 1e-6);
    res.b = y_mean - res.k * x_mean;
    return res;
}
int main()
{
    vector<vector<int>> points = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    Param res = get_line(points);
    cout << res.k << " " << res.b << endl;
    return 0;
}