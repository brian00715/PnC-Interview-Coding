/**
 * @name
 * @details
 * @url
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
}