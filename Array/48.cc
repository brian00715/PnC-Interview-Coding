/**
 * @name 48.旋转图像
 * @details 顺时针旋转二维数组
 * @url
 * @idea
 * 1.用辅助数组，旋转后第i行第j列对应新数组中的倒数第i行和第j列；
 * 2.原地旋转，利用temp变量保存中间结果，比较复杂不考虑；
 * 3.翻转代替旋转，先水平线翻转，再对角线翻转即可，推荐使用
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // horizontal flip
        for (int i = 0; i < n / 2; i++) // NOTE: must be n/2
        {
            for (int j = 0; j < n; j++) { swap(matrix[i][j], matrix[n - i - 1][j]); }
        }

        // diagonal flip
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++) { swap(matrix[i][j], matrix[j][i]); }
        }
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    solution.rotate(matrix1);
    cout << "Test case 1 result:" << endl;
    PrintMatrix(matrix1);

    // Test case 2
    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16},
    };
    solution.rotate(matrix2);
    cout << "Test case 2 result:" << endl;
    PrintMatrix(matrix2);

    // Test case 3
    vector<vector<int>> matrix3 = {
        {1, 2},
        {3, 4},
    };
    solution.rotate(matrix3);
    cout << "Test case 3 result:" << endl;
    PrintMatrix(matrix3);

    // Test case 4
    vector<vector<int>> matrix4 = {{1}};
    solution.rotate(matrix4);
    cout << "Test case 4 result:" << endl;
    PrintMatrix(matrix4);

    // Test case 5
    vector<vector<int>> matrix5 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };
    solution.rotate(matrix5);
    cout << "Test case 5 result:" << endl;
    PrintMatrix(matrix5);

    return 0;
}