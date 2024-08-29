/**
 * @name 104.求二叉树最大深度
 * @details
 * @url https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 * @idea 递归，取左、右子树最大深度的最大值+1
 * @note
 */

#include "../header.hpp"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepthBFS(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root != nullptr)
            q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            int n = q.size(); // XXX important
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                };
                if (curr->right != nullptr)
                {
                    q.push(curr->right);
                };
            }
            ans++;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;
    vector<int> input{
        3, 9, 20, -1, -1, 15, 7};

    TreeNode tree(input);
    tree.traverse(TreeNode::TraverseMethod::LEVEL);

    // int rst = s.maxDepth(&tree);
    int rst = s.maxDepthBFS(&tree);
    cout << "max depth: " << rst << endl;
    return 0;
}