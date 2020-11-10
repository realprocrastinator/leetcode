#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for singly-linked list.

class Solution:
    
    def sumUp(self,l):
        sum = 0
        place = 1
        while (l != None):
            sum += place*l.val
            place *= 10
            l = l.next
        return sum
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ret = ListNode(int(str(self.sumUp(l1) + self.sumUp(l2))[::-1][0]))
        head = ret
        for e in str(self.sumUp(l1) + self.sumUp(l2))[::-1][1:]:
            curr = ListNode(int(e))
            ret.next = curr
            ret = curr
        return head

# @lc code=end

