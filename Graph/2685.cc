#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // 使用度和邻居集合来判断连通分量
        vector<int> degree(n, 0);
        vector<unordered_set<int>> neighbors(n);

        // 记录每个节点的度数和邻居
        for (const auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            degree[u]++;
            degree[v]++;
            neighbors[u].insert(v);
            neighbors[v].insert(u);
        }

        // 找到每个连通分量并判断是否是完全连通分量
        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                unordered_set<int> componentNodes;
                findComponent(i, neighbors, visited, componentNodes);

                // 判断该连通分量是否是完全连通的
                bool isComplete = true;
                for (int node : componentNodes)
                {
                    // 如果度数不等于组件大小 - 1 或者邻居不是整个集合，说明不是完全连通分量
                    if (degree[node] != componentNodes.size() - 1)
                    {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) { completeComponents++; }
            }
        }

        return completeComponents;
    }

private:
    void findComponent(int node, const vector<unordered_set<int>> &neighbors, vector<bool> &visited,
                       unordered_set<int> &componentNodes)
    {
        visited[node] = true;
        componentNodes.insert(node);
        for (int neighbor : neighbors[node])
        {
            if (!visited[neighbor]) { findComponent(neighbor, neighbors, visited, componentNodes); }
        }
    }
};
