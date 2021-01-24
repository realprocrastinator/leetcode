/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    // make sure left and right not null
    bool isSymmetricRec(TreeNode *left, TreeNode *right)
    {
        if ((!left->left && right->right || left->left && !right->right) || ((!left->right && right->left || left->right && !right->left)))
        {
            return false;
        }
        else
        {
            if (left->left && right->right && left->right && right->left)
            {
                return (left->left->val == right->right->val) && isSymmetricRec(left->left, right->right) && (left->right->val == right->left->val) && isSymmetricRec(left->right, right->left);
            }
            else if (left->right && right->left)
            {
                return (left->right->val == right->left->val) && isSymmetricRec(left->right, right->left);
            }
            else if (left->left && right->right)
            {
                return (left->left->val == right->right->val) && isSymmetricRec(left->left, right->right);
            }
            else
            {
                return true;
            }
        }
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root || !root->left && !root->right)
        {
            return true;
        }
        else if (root->left && root->right)
        {
            return (root->left->val == root->right->val) && isSymmetricRec(root->left, root->right);
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
