/**
 * 给你一个有 n 个节点的 有向无环图（DAG），请你找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
 graph[i] 是一个从节点 i 可以访问的所有节点的列表（即从节点 i 到节点 graph[i][j]存在一条有向边）。
 https://leetcode.cn/problems/all-paths-from-source-to-target/description/
*/

#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        path.push_back(0); // start from node 0
        dfs(graph, 0);
        return res;
    }

    /**
     * @param path current path
     * @param res all paths
     */
    void dfs(vector<vector<int>> &graph, int start)
    {
        if (start == graph.size() - 1) // reach the end
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[start].size(); i++) // traverse all the adjecent nodes
        {
            path.push_back(graph[start][i]);
            dfs(graph, graph[start][i]); // find the path from current node to the end
            path.pop_back();             // backtracking. pop the current node to gurantee other recursions use the indipendent path variable
        }
    }

    void printAllPaths()
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout << "path " << i << ": ";
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << "------" << endl;
        }
    }

private:
    vector<int> path;        // current path
    vector<vector<int>> res; // all paths
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}}; // means the adjacent nodes of each node
    Solution s;
    vector<vector<int>> res = s.allPathsSourceTarget(graph);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
