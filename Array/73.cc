/**
 * @name 73[M].矩阵置零
 * @details
 * @url https://leetcode.cn/problems/set-matrix-zeroes/
 * @idea  用额外的两个 vector作为行列标记，每遍历到0就标记，再遍历一次数组置零。
 * （建议）可以只用第一行和第一列标记0，但需要额外的两个变量标记第一行第一列本身是否包含0。
 *  (不建议)也可以只用一个变量标记第一行第一列是否有0
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool row1_zero = false,
             col1_zero = false; // indicate whether first row and col has 0
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0]) { col1_zero = true; }
        }
        for (int j = 0; j < n; j++)
        {
            if (!matrix[0][j]) { row1_zero = true; }
        }

        // set first row and col to 0 given matrix[i][j]
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j]) { matrix[i][0] = matrix[0][j] = 0; }
            }
        }

        // set matrix[i][j] to 0 given the result of first row and col
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j]) { matrix[i][j] = 0; }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (col1_zero) { matrix[i][0] = 0; }
        }
        for (int j = 0; j < n; j++)
        {
            if (row1_zero) { matrix[0][j] = 0; }
        }
    }
};

// 只使用一个标记的版本
class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0]) { flag_col0 = true; }
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j]) { matrix[i][0] = matrix[0][j] = 0; }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j]) { matrix[i][j] = 0; }
            }
            if (flag_col0) { matrix[i][0] = 0; }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}