/*
二叉树层序遍历
https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
*/
#include "../header.hpp"

class Solution
{
public:
    vector<vector<int>> layerTraverse(TreeNode *root)
    {
        vector<vector<int>> rst;
        if (root == nullptr)
        {
            return rst;
        }
        queue<TreeNode *> open_list;
        open_list.push(root);

        while (!open_list.empty())
        {
            int n = open_list.size(); // for distinguishing every layer's result
            vector<int> layer_rst;
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = open_list.front();
                open_list.pop();
                layer_rst.push_back(curr->val);

                if (curr->left != nullptr)
                {
                    open_list.push(curr->left);
                }
                if (curr->right != nullptr)
                {

                    open_list.push(curr->right);
                }
            }
            rst.push_back(layer_rst);
        }
        return rst;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> input{
        3, 9, 20, -1, -1, 15, 7};

    TreeNode tree(input);
    tree.traverse(TreeNode::TraverseMethod::LEVEL);
    vector<vector<int>> rst;
    rst = s.layerTraverse(&tree);
    for (auto layer : rst)
    {
        for (auto x : layer)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
