/**
 * @name 695.最大岛屿面积
 * @details
 * @url https://leetcode.cn/problems/max-area-of-island/description/
 * @idea
 * 1. 递归式DFS
 * 2. 栈式DFS
 * 3. BFS
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_area = -1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x == grid.size() || x < 0 || y == grid[0].size() || y < 0 || grid[x][y] != 1)
        {
            return 0;
        }
        grid[x][y] = 2;
        int area = 1;
        area += dfs(grid, x - 1, y);
        area += dfs(grid, x, y - 1);
        area += dfs(grid, x + 1, y);
        area += dfs(grid, x, y + 1);
        return area;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> input{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int max_area = s.maxAreaOfIsland(input);
    printf("max area is:%d\r\n", max_area);
}