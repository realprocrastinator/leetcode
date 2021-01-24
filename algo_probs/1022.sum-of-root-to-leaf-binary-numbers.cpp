/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int sum = 0;

    void sumRootToLeafRec(TreeNode *root, int currsum)
    {
        if (root)
        {

            currsum = ((currsum << 1) + root->val);

            if (!root->left && !root->right)
            {
                sum += currsum;
            }

            sumRootToLeafRec(root->left, currsum);
            sumRootToLeafRec(root->right, currsum);
        }
    }

    int sumRootToLeaf(TreeNode *root)
    {
        if (root)
        {
            sumRootToLeafRec(root, 0);
        }

        return sum;
    }
};
// @lc code=end
