#include "../header.hpp"
class Graph
{
public:
    Graph(int size) : size(size)
    {
        adj = new int *[size];
        for (int i = 0; i < size; i++)
        {
            adj[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v, float w)
    {
        adj[u][v] = w;
    }

    /**
     * @brief traverse from start to end. only output traverse path, not the path from start to end
     *
     */
    void bfs(int start, int end)
    {
        bool *visited = new bool[size];
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
        }

        std::queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS result: ";
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u + 1 << " ";
            if (u == end)
            {
                std::cout << "Found" << std::endl;
                break;
            }
            // traverse all the adjacent nodes
            for (int i = 0; i < size; i++)
            {
                if (adj[u][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfs(int start, int end)
    {
        vector<bool> visited(size, false);

        std::stack<int> s;
        s.push(start);
        visited[start] = true;
        cout << "DFS result: ";
        while (!s.empty())
        {
            int u = s.top();
            s.pop();
            cout << u + 1 << " ";
            if (u == end)
            {
                std::cout << "Found" << std::endl;
                break;
            }
            // traverse all the adjacent nodes
            for (int i = 0; i < size; i++)
            {
                if (adj[u][i] != 0 && !visited[i])
                {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        cout << endl;
    }

    void printAdj()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << i << ": ";
            for (int j = 0; j < size; j++)
            {
                std::cout << adj[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    float calcu_sum_weights(std::vector<int> path)
    {
        float sum = 0;
        for (int i = 0; i < path.size() - 1; i++)
        {
            sum += adj[path[i]][path[i + 1]];
        }
        return sum;
    }

private:
    int **adj;
    int size;
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> input = {
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 1},
        {2, 5, 2},
        {3, 6, 1},
        {4, 6, 4},
        {4, 5, 3},
        {6, 5, 3}};
    int start = 1, end = 5;
    Graph g(input.size());
    // build graph
    for (int i = 0; i < input.size(); i++)
    {
        g.addEdge(input[i][0] - 1, input[i][1] - 1, input[i][2]);
    }
    g.printAdj();
    g.bfs(start - 1, end - 1);
    g.dfs(start - 1, end - 1);

    return 0;
}
