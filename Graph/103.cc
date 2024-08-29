/**
 * @name 水流问题
 * @details 水流根据地形流向第一、第二边界，求第一、第二边界的水流量
 * @url https://kamacoder.com/problempage.php?pid=1175
 * @idea
 * @note
 */
// #include "../header.hpp"

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*这种写法会导致内存超限，不知道为什么*/
class SolutionDeprecated
{
public:
    int dfs(vector<vector<int>> &map, int x, int y, vector<vector<int>> &visited)
    {
        if (visited[x][y] != 0) return visited[x][y];

        if (x == 0 || y == 0) visited[x][y] = 1;
        if (x == map.size() - 1 || y == map[0].size() - 1) visited[x][y] = -1;

        const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<int> flag;
        for (auto &dir : dirs)
        {
            int next_x = x + dir[0], next_y = y + dir[1];
            if (next_x < 0 || next_y < 0 || next_x >= map.size() || next_y >= map[0].size())
                continue;

            auto next_height = map[next_x][next_y];
            if (next_height > map[x][y]) continue;

            int rst = dfs(map, next_x, next_y, visited);
            flag.insert(rst);
        }

        if ((flag.count(1) && flag.count(-1)) || flag.count(2))
        {
            visited[x][y] = 2;
            return 2;
        }
        if (flag.count(1))
        {
            visited[x][y] = 1;
            return 1;
        }
        if (flag.count(-1))
        {
            visited[x][y] = -1;
            return -1;
        }

        return 0;
    }

    void func(vector<vector<int>> &map, int m, int n)
    {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(map, i, j, visited) == 2) cout << i << " " << j << endl;
            }
        }
    }
};

/**
 * @brief 用两个visited数组分别从第一和第二边界出发找路，最后合并结果
 *
 */
class Solution
{
public:
    bool dfs(vector<vector<int>> &map, int x, int y, vector<vector<bool>> &visited)
    {
        if (x < 0 || y < 0 || x > map.size() - 1 || y > map[0].size() - 1 || visited[x][y])
            return false;
        visited[x][y] = true;
        const vector<vector<int>> dirs = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0},
        };
        for (auto &dir : dirs)
        {
            int new_x = x + dir[0], new_y = y + dir[1];
            if (new_x < 0 || new_y < 0 || new_x > map.size() - 1 || new_y > map[0].size() - 1)
                continue;

            int new_h = map[new_x][new_y];
            if (new_h < map[x][y]) continue; // from low to high

            dfs(map, new_x, new_y, visited);
        }
        return true;
    }

    void func(vector<vector<int>> map, int m, int n)
    {
        vector<vector<bool>> visiteed_lu(m, vector<bool>(n, false));
        vector<vector<bool>> visiteed_rd(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(map, i, 0, visiteed_lu);
            dfs(map, i, n - 1, visiteed_rd);
        }

        for (int i = 0; i < n; i++)
        {
            dfs(map, 0, i, visiteed_lu);
            dfs(map, m - 1, i, visiteed_rd);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visiteed_lu[i][j] && visiteed_rd[i][j]) { cout << i << " " << j << endl; }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
#define TWO

#ifdef ONE
    vector<vector<int>> map = {
        {1, 3, 1, 2, 4}, {1, 2, 1, 3, 2}, {2, 4, 7, 2, 1}, {4, 5, 6, 1, 1}, {1, 4, 1, 2, 1},
    };
    int m = map.size(), n = map[0].size();
#endif

#ifdef TWO
    int m, n;
    cin >> m >> n;
    vector<vector<int>> map(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }
    }

#endif

    Solution s;
    s.func(map, m, n);
    return 0;
}