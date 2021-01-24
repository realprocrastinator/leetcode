/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        bool res = isUnivalTree(root->left) && isUnivalTree(root->right);
        if (root->left && root->right)
        {
            return res && root->left->val == root->right->val;
        }
        else if (!root->left && !root->right)
        {
            return res;
        }
        else
        {
            return res && ((root->left) ? root->left->val == root->val : root->right->val == root->val);
        }
    }
};
// @lc code=end
