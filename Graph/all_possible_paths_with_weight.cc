/**
 * 输入带权重的有向无环图，找出从start到end的所有路径，并按照权重从小到大排序
 */

#include "../header.hpp"

class Solution
{
public:
    Solution(vector<vector<int>> &input)
    {
        auto lastItem = input.back();
        vertexNum = lastItem[0];
        graph = new vector<vector<int>>(vertexNum, vector<int>(vertexNum, 0));
        for (int i = 0; i < input.size(); i++)
        {
            (*graph)[input[i][0] - 1][input[i][1] - 1] = input[i][2];
        }
        printGraph();
    }
    vector<vector<int>> allPathsSourceTarget(int start, int end)
    {
        path.push_back(0); // start from node 0
        dfs(start, end);
        return res;
    }

    /**
     * @param path current path
     * @param res all paths
     */
    void dfs(int start, int end)
    {
        if (start == end) // reach the end
        {
            res.push_back(path);
            weights.push_back(weight);
            return;
        }
        for (int i = 0; i < vertexNum; i++) // traverse all the adjecent nodes
        {
            if ((*graph)[start][i] == 0)
                continue;
            path.push_back(i);
            weight += (*graph)[start][i];
            dfs(i, end);     // find the path from current node to the end
            path.pop_back(); // backtracking. pop the current node to gurantee other recursions use the indipendent path variable
            weight -= (*graph)[start][i];
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
            cout << " weight: " << weights[i] << endl; // print the weight of each path
            cout << "------" << endl;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < graph->size(); i++)
        {
            for (int j = 0; j < (*graph)[i].size(); j++)
            {
                cout << (*graph)[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> res; // all paths
    vector<int> weights;     // all paths' weights
private:
    vector<vector<int>> *graph;
    vector<int> path; // current path
    int weight = 0;   // current path weight
    int vertexNum;
};

int main(int argc, char const *argv[])
{
    // [[1,2,3],[1,3,2],[1,4,1],[2,5,2],[3,6,1],[4,6,4],[4,5,3],[6,5,3]]
    vector<vector<int>> input = {
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 1},
        {2, 5, 2},
        {3, 6, 1},
        {4, 6, 4},
        {4, 5, 3},
        {6, 5, 3},
    };

    Solution s(input);
    vector<vector<int>> res = s.allPathsSourceTarget(0, 4);
    vector<int> weights(s.weights);

    cout << "all paths: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] + 1 << " ";
        }
        cout << " weight: " << s.weights[i] << endl;
    }

    vector<int> flag;
    for (int i = 0; i < res.size(); i++)
    {
        flag.push_back(i);
    }
    std::sort(flag.begin(), flag.end(),
              [&res, &weights](int a, int b)
              {
                  return weights[a] < weights[b];
              });
    cout << "sorted paths: " << endl;
    for (int i = 0; i < flag.size(); i++)
    {
        for (int j = 0; j < res[flag[i]].size(); j++)
        {
            cout << res[flag[i]][j] + 1 << " ";
        }
        cout << " weight: " << weights[flag[i]] << endl;
    }
    return 0;
}
