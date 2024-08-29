/**
 * @name 98. 验证二叉搜索树
 * @details
 * @url https://leetcode.cn/problems/validate-binary-search-tree/description/
 * @idea DFS判断是否满足要求或者用中序遍历看是否是递增序列
 * @note DFS时注意传递给递归函数的参数
 */
#include "../header.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    bool judge(TreeNode *root, long long left, long long right)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= left || root->val >= right) // must be >= or <= !!!
        {
            return false;
        }
        return judge(root->left, left, root->val) && judge(root->right, root->val, right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return judge(root, LONG_MIN, LONG_MAX);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
}