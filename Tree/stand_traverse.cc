#include "../header.hpp"

class Solution
{

    vector<char> &traverseTree(TreeNode *root)
    {
        vector<char> result;
        preTraverse(root, result);
        return result;
    }

    void preTraverse(TreeNode *root, vector<char> &rst)
    {
        // mid left right
        if (root == nullptr)
        {
            return;
        }
        rst.push_back(root->val);
        preTraverse(root->left, rst);
        preTraverse(root->right, rst);
    }

    void midTraverse(TreeNode *root, vector<char> &rst)
    {
        if (root == nullptr)
        {
            return;
        }
        //  left mid right
        midTraverse(root->left, rst);
        rst.push_back(root->val);
        midTraverse(root->right, rst);
    }

    void postTraverse(TreeNode *root, vector<char> &rst)
    {
        if (root == nullptr)
        {
            return;
        }
        // left right mid
        postTraverse(root->left, rst);
        postTraverse(root->right, rst);
        rst.push_back(root->val);
    }

    void layerTraverse(TreeNode *root, vector<char> &rst)
    {
        queue<TreeNode *> tmp;
        tmp.push(root);
        while (!tmp.empty())
        {
            TreeNode *node = tmp.front();
            tmp.pop();
            if (node->left)
            {
                tmp.push(node->left);
            }
            if (node->right)
            {
                tmp.push(node->right);
            }
        }
    }
};
class Solution
{

    vector<char> &traverseTree(TreeNode *root)
    {
        vector<char> result;
        preTraverse(root, result);
        return result;
    }

    void preTraverse(TreeNode *root, vector<char> &rst)
    {
        // mid left right
        if (root == nullptr)
        {
            return;
        }
        rst.push_back(root->val);
        preTraverse(root->left, rst);
        preTraverse(root->right, rst);
    }

    void midTraverse(TreeNode *root, vector<char> &rst)
    {
        if (root == nullptr)
        {
            return;
        }
        //  left mid right
        midTraverse(root->left, rst);
        rst.push_back(root->val);
        midTraverse(root->right, rst);
    }

    void postTraverse(TreeNode *root, vector<char> &rst)
    {
        if (root == nullptr)
        {
            return;
        }
        // left right mid
        postTraverse(root->left, rst);
        postTraverse(root->right, rst);
        rst.push_back(root->val);
    }

    void layerTraverse(TreeNode *root, vector<char> &rst)
    {
        queue<TreeNode *> tmp;
        tmp.push(root);
        while (!tmp.empty())
        {
            TreeNode *node = tmp.front();
            tmp.pop();
            if (node->left)
            {
                tmp.push(node->left);
            }
            if (node->right)
            {
                tmp.push(node->right);
            }
        }
    }
};

int main()
{
    // 创建一个最小堆的优先队列（默认情况下）
    // std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    std::priority_queue<int, std::vector<int>> min_heap;

    // 插入元素
    min_heap.push(3);
    min_heap.push(1);
    min_heap.push(4);
    min_heap.push(2);

    // 访问队首元素（最小元素）
    std::cout << "Top element: " << min_heap.top() << std::endl;

    // 弹出队首元素
    min_heap.pop();

    // 输出剩余元素
    while (!min_heap.empty())
    {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }
    std::cout << std::endl;

    return 0;
}
