/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
class Solution {
public:
    TreeNode* buildSubtree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int postend) {
        // exit
        if (postend < 0 || instart > inend || inend < 0) {
            return nullptr;
        }
        
        // postend tells us the root
        TreeNode *root = new TreeNode(postorder[postend]);
        
        // find the partition pos in the inorder array to build the tree recursivly
        int i;
        for (i = instart; i<= inend; ++i) {
            if (postorder[postend] == inorder[i]){
                break;
            }
        }
        
        // now i points to the root of subtree
        int r_nele = inend - i;
        int l_nele = i - instart; 
        root->left = buildSubtree(inorder, postorder, i - l_nele , i - 1, postend - r_nele - 1);
        root->right = buildSubtree(inorder, postorder, i + 1, inend, postend - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildSubtree(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};
// @lc code=end

