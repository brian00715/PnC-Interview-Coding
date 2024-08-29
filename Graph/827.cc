/**
 * @name 827[H]. 最大人工岛/Kama 104
 * @details
 * @url https://kamacoder.com/problempage.php?pid=1176
 * @idea 两次遍历，第一次标记岛屿并用map维护面积；第二次用每个cell尝试拼接岛屿
 * @note
 */
// #include "../header.hpp"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &map, int x, int y, int flag)
    {
        if (x < 0 || y < 0 || x > map.size() - 1 || y > map[0].size() - 1 || map[x][y] != 1)
            return 0;

        map[x][y] = flag;
        int size = 1;
        size += dfs(map, x - 1, y, flag);
        size += dfs(map, x, y - 1, flag);
        size += dfs(map, x + 1, y, flag);
        size += dfs(map, x, y + 1, flag);
        return size;
    }

    int func(vector<vector<int>> &grid, int m, int n)
    {
        int flag = 2;
        unordered_map<int, int> map_size;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int size = dfs(grid, i, j, flag);
                    map_size.insert({flag, size});
                    flag++;
                }
            }
        }
        // PrintVector(grid);

        int max_size = 1;
        vector<vector<int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1},
        };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int flag = grid[i][j];
                int curr_size = map_size[flag];
                if (grid[i][j] == 0)
                {
                    int curr_max_size = 1;
                    unordered_set<int> neigh_flag;
                    for (auto &dir : dirs) // check neighbors
                    {
                        int new_x = i + dir[0], new_y = j + dir[1];
                        if (new_x < 0 || new_y < 0 || new_x > grid.size() - 1 ||
                            new_y > grid[0].size() - 1)
                            continue;

                        if (grid[new_x][new_y] != 0)
                        {
                            int flag = grid[new_x][new_y];
                            // NOTE: very important to prevent duplicated count!
                            if (neigh_flag.count(flag) == 0) { curr_max_size += map_size[flag]; }
                            neigh_flag.insert(flag);
                        }
                    }
                    max_size = std::max(max_size, curr_max_size);
                }
                max_size = max(max_size, curr_size);
            }
        }
        return max_size;
    }
};

int main(int argc, char const *argv[])
{
#define TWO
#ifdef ONE
    vector<vector<int>> map = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
    };
    int m = map.size(), n = map[0].size() - 1;
#endif

#ifdef TWO
    int m, n;
    cin >> m >> n;
    vector<vector<int>> map(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) { cin >> map[i][j]; }
    }
#endif

    Solution s;
    int max_size = s.func(map, m, n);
    cout << max_size;
}