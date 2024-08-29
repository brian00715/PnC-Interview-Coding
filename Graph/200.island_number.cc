/** https://leetcode.cn/problems/number-of-islands/
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

*/
#include "../header.hpp"

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        vector<vector<char>> grid_copy(grid);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1') // not been visited and is a piece of land
                {
                    num++;
                    // dfs(grid, i, j); // traverse the connected area and mark them as visited
                    bfs(grid, i, j);
                }
            }
        }
        return num;
    }

    /**
     * @param x,y the index of grid array
     */
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] != '1') // exceed the boundary or been visited or not land
            return;
        grid[r][c] = '2';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    void bfs(vector<vector<char>> &grid, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '2';
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            // traverse the four directions
            for (auto &d : directions)
            {
                int new_x = x + d[0];
                int new_y = y + d[1];
                if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() &&
                    grid[new_x][new_y] == '1')
                {
                    grid[new_x][new_y] = '2';
                    q.push({new_x, new_y});
                }
            }
        }
    }

private:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

int main()
{
    Solution s;
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};
    vector<vector<char>> grid3 = {{'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};
    vector<vector<char>> grid4 = {{'1', '1'}};
    cout << s.numIslands(grid2) << endl;
}