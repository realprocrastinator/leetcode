#
# @lc app=leetcode id=652 lang=python3
#
# [652] Find Duplicate Subtrees
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        from collections import defaultdict,Counter
        ans = []
        # traverse the tree in post-ord traverse to get all the node and its left child and right child 
        # for recording the subtree structure, because even the node structure is same their
        # memory address is different so will lead to bad result
        treemap = defaultdict()
        treemap.default_factory = treemap.__len__
        # print(treemap)
        # use the hash function to make sure the same structure will result in same id
        subtreecnt = defaultdict(int)
        def traverse(node):
            if node is None:
                return
            else:
                key = treemap[node.val,traverse(node.left),traverse(node.right)]
                subtreecnt[key] += 1
                # print(subtreecnt)
                if subtreecnt[key] == 2:
                    # print(node)
                    ans.append(node)
                return key
                    
        traverse(root)
        return ans
# @lc code=end

