/**
 * @name 2290[H].到达角落需要移除障碍物的最小数目
 * @details
 * @url https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/
 * @idea 把所有路都视为可通行的，障碍物视为代价，bfs搜索。注意用标记visited避免超时
 * @note
 */
#include "../header.hpp"

// Dijkstra
class Solution
{
    vector<vector<int>> dirs = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1},
    };

public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        auto cmp = [](tuple<int, int, int> node1, tuple<int, int, int> node2) {
            return get<2>(node1) > get<2>(node2);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       function<bool(tuple<int, int, int>, tuple<int, int, int>)>>
            open_list(cmp);
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX)); // 如果不加visited会超时
        visited[0][0] = 0;

        open_list.emplace(0, 0, 0);
        while (!open_list.empty())
        {
            auto [x, y, cost] = open_list.top();
            if (x == m - 1 && y == n - 1) { return cost; }
            open_list.pop();
            for (auto &dir : dirs)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                if (new_x < 0 || new_x > m - 1 || new_y < 0 || new_y > n - 1) { continue; }
                int new_cost = grid[new_x][new_y] + cost;
                if (new_cost < visited[new_x][new_y])
                {
                    open_list.emplace(new_x, new_y, new_cost);
                    visited[new_x][new_y] = new_cost;
                }
            }
        }
        return -1;
    }
};

// 0-1 BFS优化耗时
class Solution2
{
    vector<vector<int>> dirs = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1},
    };

public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        deque<tuple<int, int, int>> dq;
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = 0;

        dq.emplace_front(0, 0, 0); // 起点入队，代价为0

        while (!dq.empty())
        {
            auto [x, y, cost] = dq.front();
            dq.pop_front();

            if (x == m - 1 && y == n - 1) { return cost; }

            for (auto &dir : dirs)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) { continue; }

                int new_cost = cost + grid[new_x][new_y];
                if (new_cost < visited[new_x][new_y])
                {
                    visited[new_x][new_y] = new_cost;
                    if (grid[new_x][new_y] == 0)
                    {
                        dq.emplace_front(new_x, new_y, new_cost); // 如果代价为0，优先处理
                    }
                    else
                    {
                        dq.emplace_back(new_x, new_y, new_cost); // 代价为1的放在队列后面
                    }
                }
            }
        }

        return -1; // 理论上不会到达这里
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}