/**
 * @name 牛群仰视图
 * @details
 * @url https://www.nowcoder.com/practice/0f37a18320c4466abf3a65819592e8be?tab=note
 * @idea 实际就是遍历叶子结点，DFS就完事了.注意叶子结点的定义是左child和右child都为空
 * @note
 */
#include "../header.hpp"

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> bottomView(TreeNode *root)
    {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode *root, vector<int> &res)
    {
        if (!root) return;
        if (!root->left && !root->right) res.push_back(root->val);

        traverse(root->left, res);
        traverse(root->right, res);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}