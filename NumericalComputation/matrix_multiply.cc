/**
 * @name 矩阵乘法实现
 * @details
 * @url
 * @idea
 * @note
 */
#include "../header.hpp"
#include <stdexcept>

double vectorDotProduct(vector<double> &vec1, vector<double> &vec2)
{
    if (vec1.size() != vec2.size())
    {
        throw std::runtime_error("dimention error");
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < vec1.size(); i++) { sum += vec1[i] * vec2[i]; }
    return sum;
}

vector<vector<double>> matrixMultiply(vector<vector<double>> &mat1, vector<vector<double>> &mat2)
{
    if (mat1.empty() || mat2.empty() || mat1[0].empty() || mat2[0].empty())
    {
        throw std::runtime_error("dimention not match!");
    }
    int m1 = mat1.size(), n1 = mat1[0].size();
    int m2 = mat2.size(), n2 = mat2[0].size();
    if (n1 != m2) { throw std::runtime_error("dimention not match!"); }

    vector<vector<double>> res(m1, vector<double>(n2));
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            vector<double> col2;
            for (int k = 0; k < m2; k++) { col2.emplace_back(mat2[k][j]); }
            res[i][j] = vectorDotProduct(mat1[i], col2);
        }
    }
    return res;
}

int main()
{
    vector<vector<double>> mat1 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<double>> mat2 = {{7, 8}, {9, 10}, {11, 12}};

    vector<vector<double>> result = matrixMultiply(mat1, mat2);

    for (const auto &row : result)
    {
        for (double val : row) { cout << val << " "; }
        cout << endl;
    }

    return 0;
}