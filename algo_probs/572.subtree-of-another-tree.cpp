/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    void save_same_node(TreeNode *s, int tar, TreeNode **res, int *pos)
    {
        if (!s)
        {
            return;
        }

        if (s->val == tar)
        {
            res[(*pos)++] = s;
        }

        save_same_node(s->left, tar, res, pos);
        save_same_node(s->right, tar, res, pos);
    }

    bool is_same_tree(TreeNode *s, TreeNode *t)
    {
        if (s && t)
        {
            if (s->val == t->val)
            {
                return is_same_tree(s->left, t->left) && is_same_tree(s->right, t->right);
            }
            else
            {
                return false;
            }
        }
        else if (!(s || t))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int num_nodes(TreeNode *s)
    {
        if (!s)
        {
            return 0;
        }
        else
        {
            return 1 + num_nodes(s->left) + num_nodes(s->right);
        }
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        int num = num_nodes(s);
        TreeNode **res = (TreeNode **)malloc(num * sizeof(TreeNode *));
        memset(res, 0, num * sizeof(TreeNode *));

        int pos = 0;
        save_same_node(s, t->val, res, &pos);

        for (int i = 0; i < num; ++i)
        {
            if (res[i])
            {
                if (is_same_tree(res[i], t))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
