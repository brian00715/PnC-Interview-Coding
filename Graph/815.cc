/**
 * @name 815.公交线路
 * @details
 * @url https://leetcode.cn/problems/bus-routes/description/
 * @idea 建图+BFS搜索
 * 用unordered_map维护每个站点包含的线路，队列维护遍历的站点。如何保证最短？因为BFS是逐层遍历，因此找到的就是最短的
 * https://leetcode.cn/problems/bus-routes/solutions/1814176/luo-by-jefff-r7i0/
 * @note 遍历顺序：对于当前节点，遍历所有节点所在的路线，再针对每一条路线遍历每一个新站点
 */
#include "../header.hpp"

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        // build grph
        unordered_map<int, vector<int>> site_route; // stores the routes inluded by every site
        for (int i = 0; i < routes.size(); i++)
        {
            for (auto site : routes[i])
            {
                site_route[site].push_back(i);
            }
        }

        // search the path
        queue<int> q;                               // stores sites to be traversed
        vector<bool> visited(routes.size(), false); // whether a route has been visited
        q.push(source);
        int length = 0; // routes(bus) number
        while (!q.empty())
        {
            length++;
            int size = q.size();           // NOTE: size must be acquired out of the loop below, because q.size() will change inside the loop
            for (int i = 0; i < size; i++) // traverse all nodes in queue at a time, which means
            {
                int curr_site = q.front();
                q.pop();
                for (auto &route : site_route[curr_site]) // traverse all possible routes from current site to target
                {
                    if (!visited[route])
                    {
                        visited[route] = true;
                        for (auto site : routes[route]) // next site to be visited
                        {
                            if (site == target)
                            {
                                return length;
                            }
                            q.push(site);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
}