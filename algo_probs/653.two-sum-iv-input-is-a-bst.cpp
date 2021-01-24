/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool bs(TreeNode *root, int target)
    {
        if (!root)
        {
            return false;
        }

        // std::cout << root->val << '\n';

        if (root->val == target)
        {
            return true;
        }
        else
        {
            return bs(root->left, target) || bs(root->right, target);
        }
    }

    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
        {
            return false;
        }

        auto q = std::queue<TreeNode *>();
        q.push(root);

        while (!q.empty())
        {
            auto tar = q.front();
            q.pop();

            // std::cout << "got: " << tar->val << '\n';

            if (tar->val != k - tar->val)
            {
                if (bs(root, k - tar->val))
                {
                    return true;
                }
            }

            if (tar->left)
            {
                q.push(tar->left);
            }

            if (tar->right)
            {
                q.push(tar->right);
            }
        }

        // no found
        return false;
    }
};
// @lc code=end
