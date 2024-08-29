/**
 * @name 54.螺旋数组
 * @details
 * @url https://leetcode.cn/problems/spiral-matrix/description/
 * @idea 用同尺寸2d数组标记已访问元素，用方向数组调整遍历方向.
 * 每次更新下标时先判断新下标的范围和数字，决定是否要更新迭代方向
 * @note
 */
#include "../header.hpp"

class Solution
{
private:
public:
    /* 模拟法 */
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        int total = height * width;
        const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // visited flag matrix
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        vector<int> result;

        int row_idx = 0, col_idx = 0, dir_idx = 0;
        for (int i = 0; i < total; i++)
        {
            visited[row_idx][col_idx] = true;
            result.push_back(matrix[row_idx][col_idx]);
            int next_row = row_idx + dirs[dir_idx][0], next_col = col_idx + dirs[dir_idx][1];
            if (next_row > height - 1 || next_row < 0 || next_col > width - 1 || next_col < 0 ||
                visited[next_row][next_col])
            {
                dir_idx = (dir_idx + 1) % 4;
            }
            row_idx += dirs[dir_idx][0];
            col_idx += dirs[dir_idx][1];
        }
        return result;
    }

    /* 边界裁剪法 */
    vector<int> spiralOrder2(vector<vector<int>> &matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        int total = height * width;
        vector<int> result;

        int row_low = 0, col_low = 0, row_high = height - 1, col_high = width - 1;
        while (true)
        {
            for (int i = col_low; i <= col_high; i++) { result.push_back(matrix[row_low][i]); }
            if (++row_low > row_high) { break; }
            for (int i = row_low; i <= row_high; i++) { result.push_back(matrix[i][col_high]); }
            if (--col_high < col_low) { break; }
            for (int i = col_high; i >= col_low; i--) { result.push_back(matrix[row_high][i]); }
            if (--row_high < row_low) { break; }
            for (int i = row_high; i >= row_low; i--) { result.push_back(matrix[i][col_low]); }
            if (++col_low > col_high) { break; }
        }
        return result;
    }
};

void testSpiralOrder()
{
    Solution solution;

    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    // vector<int> result1 = solution.spiralOrder(matrix1);
    vector<int> result1 = solution.spiralOrder2(matrix1);
    for (int num : result1) { cout << num << " "; }
    cout << endl;

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    // vector<int> result2 = solution.spiralOrder(matrix2);
    vector<int> result2 = solution.spiralOrder2(matrix2);
    for (int num : result2) { cout << num << " "; }
    cout << endl;
}

int main()
{
    testSpiralOrder();
    return 0;
}