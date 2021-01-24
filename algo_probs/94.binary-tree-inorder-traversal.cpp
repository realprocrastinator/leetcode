/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
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
public:
    void traverse_rec(struct TreeNode *root, std::vector<int> &ret)
    {
        if (root)
        {
            traverse_rec(root->left, ret);
            // printf("%d ", root->val);
            ret.push_back(root->val);
            traverse_rec(root->right, ret);
        }
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        auto res = std::vector<int>();
        if (root)
        {
            traverse_rec(root, res);
        }
        return res;
    }
};
// @lc code=end
