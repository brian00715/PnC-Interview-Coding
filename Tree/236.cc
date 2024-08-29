/**
 * @name 236.二叉树的最近公共祖先
 * @details
 * @url https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 * @idea dfs，注意最近公共祖先的判读即可
 * @note
 */
#include "../header.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *ans;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root) return false;
        bool lchild = dfs(root->left, p, q);
        bool rchild = dfs(root->right, p, q);
        if ((lchild && rchild) ||
            ((root->val == p->val || root->val == q->val) && (lchild || rchild)))
        {
            ans = root;
        }
        return lchild || rchild || (root->val == p->val || root->val == q->val);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}