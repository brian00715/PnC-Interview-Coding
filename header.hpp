#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void PrintMatrix(const vector<vector<int>> &matrix)
{
    cout << "matrix(" << matrix.size() << "," << matrix[0].size() << ") ------------------" << endl;
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

void PrintVector(const vector<int> &vector)
{
    cout << "vector(" << vector.size() << ") ------------------" << endl;
    for (const auto &elem : vector)
    {

        cout << elem << " ";
    }
    cout << endl << "----------------------------------" << endl;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
    ListNode(ListNode &node) : val(node.val), next(node.next)
    {
    }
    ListNode(ListNode *node) : val(node->val), next(node->next)
    {
    }

    ListNode(vector<int> &data)
    {
        int flag = 1;
        ListNode *rear = nullptr;
        for (auto element : data)
        {
            if (flag == 1)
            {
                this->val = element;
                flag++;
                rear = this;
            }
            else
            {
                ListNode *new_node = new ListNode{element};
                rear->next = new_node;
                rear = new_node;
            }
        }
    }

    void printList()
    {
        ListNode *p = this;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

class Graph
{
public:
    Graph(int size) : size(size)
    {
        adj = vector<vector<int>>(size, vector<int>(size, 0));
    }

    Graph(vector<vector<int>> input) : adj(input), size(input.size())
    {
    }

    void addEdge(int u, int v, float w)
    {
        adj[u][v] = w;
    }

    /**
     * @brief traverse from start to end. only output traverse path, not the path from start to end
     *
     */
    virtual void bfs(int start, int end)
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

    virtual void dfs(int start, int end)
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
    vector<vector<int>> adj;
    int size;
};

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    const vector<string> TraverseMethodString{"pre-order", "mid-order", "post-order",
                                              "level-order"};

    enum class TraverseMethod
    {
        PRE = 0,
        MID,
        POST,
        LEVEL
    };

    /**
     * @brief Construct a new Tree Node object given the level-order-traverse result in the form of
     * 1-D vector
     *
     * @param levelOrder
     */
    TreeNode(vector<int> &levelOrder)
    {
        if (levelOrder.empty())
        {
            val = -1;
            left = nullptr;
            right = nullptr;
        }

        val = levelOrder[0];
        queue<TreeNode *> q;
        q.push(this);

        int index = 1; // build from the second element

        while (index < levelOrder.size())
        {
            TreeNode *current = q.front();
            q.pop();

            // build left tree
            if (index < levelOrder.size() && levelOrder[index] != -1)
            {
                current->left = new TreeNode(levelOrder[index]);
                q.push(current->left);
            }
            index++;

            // build right tree
            if (index < levelOrder.size() && levelOrder[index] != -1)
            {
                current->right = new TreeNode(levelOrder[index]);
                q.push(current->right);
            }
            index++;
        }
    }

    void traverse(TreeNode::TraverseMethod opt = TreeNode::TraverseMethod::PRE)
    {
        printf("%s result: ", TraverseMethodString[(int)opt].c_str());
        switch (opt)
        {
        case TraverseMethod::PRE:
            prevTraverse(this);
            break;
        case TraverseMethod::MID:
            midTraverse(this);
            break;
        case TraverseMethod::POST:
            postTraverse(this);
            break;
        case TraverseMethod::LEVEL:
            layerTraverse(this);
            break;
        default:
            break;
        }
        cout << endl;
    }

private:
    void prevTraverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            cout << "null ";
            return;
        }

        cout << root->val << " ";
        prevTraverse(root->left);
        prevTraverse(root->right);
    }
    void midTraverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            cout << "null ";
            return;
        }

        midTraverse(root->left);
        cout << root->val << " ";
        midTraverse(root->right);
    }

    void postTraverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            cout << "null ";
            return;
        }

        postTraverse(root->left);
        postTraverse(root->right);
        cout << root->val << " ";
    }

    void layerTraverse(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr == nullptr) { cout << "null "; }
            else
            {
                cout << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout << endl;
    }
};
